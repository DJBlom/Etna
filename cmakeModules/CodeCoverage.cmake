


include(CMakeParseArguments)

option(CODE_COVERAGE_VERBOSE "Verbose information" FALSE)

# Check prereqs
find_program( GCOV_PATH gcov )
find_program( LCOV_PATH  NAMES lcov lcov.bat lcov.exe lcov.perl)
find_program( FASTCOV_PATH NAMES fastcov fastcov.py )
find_program( GENHTML_PATH NAMES genhtml genhtml.perl genhtml.bat )
find_program( GCOVR_PATH gcovr PATHS ${CMAKE_SOURCE_DIR}/scripts/test)
find_program( CPPFILT_PATH NAMES c++filt )

if(NOT GCOV_PATH)
    message(FATAL_ERROR "gcov not found! Aborting...")
endif() # NOT GCOV_PATH

# Check supported compiler (Clang, GNU and Flang)
get_property(LANGUAGES GLOBAL PROPERTY ENABLED_LANGUAGES)
foreach(LANG ${LANGUAGES})
  if("${CMAKE_${LANG}_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
    if("${CMAKE_${LANG}_COMPILER_VERSION}" VERSION_LESS 3)
      message(FATAL_ERROR "Clang version must be 3.0.0 or greater! Aborting...")
    endif()
  elseif(NOT "${CMAKE_${LANG}_COMPILER_ID}" MATCHES "GNU"
         AND NOT "${CMAKE_${LANG}_COMPILER_ID}" MATCHES "(LLVM)?[Ff]lang")
    message(FATAL_ERROR "Compiler is not GNU or Flang! Aborting...")
  endif()
endforeach()

set(COVERAGE_COMPILER_FLAGS "-g --coverage"
    CACHE INTERNAL "")
if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
    include(CheckCXXCompilerFlag)
    check_cxx_compiler_flag(-fprofile-abs-path HAVE_fprofile_abs_path)
    if(HAVE_fprofile_abs_path)
        set(COVERAGE_COMPILER_FLAGS "${COVERAGE_COMPILER_FLAGS} -fprofile-abs-path")
    endif()
endif()

set(CMAKE_Fortran_FLAGS_COVERAGE
    ${COVERAGE_COMPILER_FLAGS}
    CACHE STRING "Flags used by the Fortran compiler during coverage builds."
    FORCE )
set(CMAKE_CXX_FLAGS_COVERAGE
    ${COVERAGE_COMPILER_FLAGS}
    CACHE STRING "Flags used by the C++ compiler during coverage builds."
    FORCE )
set(CMAKE_C_FLAGS_COVERAGE
    ${COVERAGE_COMPILER_FLAGS}
    CACHE STRING "Flags used by the C compiler during coverage builds."
    FORCE )
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used for linking binaries during coverage builds."
    FORCE )
set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used by the shared libraries linker during coverage builds."
    FORCE )
mark_as_advanced(
    CMAKE_Fortran_FLAGS_COVERAGE
    CMAKE_CXX_FLAGS_COVERAGE
    CMAKE_C_FLAGS_COVERAGE
    CMAKE_EXE_LINKER_FLAGS_COVERAGE
    CMAKE_SHARED_LINKER_FLAGS_COVERAGE )

if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")
    link_libraries(gcov)
endif()

# Defines a target for running and collection code coverage information
# Builds dependencies, runs the given executable and outputs reports.
# NOTE! The executable should always have a ZERO as exit code otherwise
# the coverage generation will not complete.
#
# setup_target_for_coverage_lcov(
#     NAME testrunner_coverage                    # New target name
#     EXECUTABLE testrunner -j ${PROCESSOR_COUNT} # Executable in PROJECT_BINARY_DIR
#     DEPENDENCIES testrunner                     # Dependencies to build first
#     BASE_DIRECTORY "../"                        # Base directory for report
#                                                 #  (defaults to PROJECT_SOURCE_DIR)
#     EXCLUDE "src/dir1/*" "src/dir2/*"           # Patterns to exclude (can be relative
#                                                 #  to BASE_DIRECTORY, with CMake 3.4+)
#     NO_DEMANGLE                                 # Don't demangle C++ symbols
#                                                 #  even if c++filt is found
# )
function(setup_target_for_coverage_lcov)

    set(options NO_DEMANGLE SONARQUBE)
    set(oneValueArgs BASE_DIRECTORY NAME)
    set(multiValueArgs EXCLUDE EXECUTABLE EXECUTABLE_ARGS DEPENDENCIES LCOV_ARGS GENHTML_ARGS)
    cmake_parse_arguments(Coverage "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT LCOV_PATH)
        message(FATAL_ERROR "lcov not found! Aborting...")
    endif() # NOT LCOV_PATH

    if(NOT GENHTML_PATH)
        message(FATAL_ERROR "genhtml not found! Aborting...")
    endif() # NOT GENHTML_PATH

    # Set base directory (as absolute path), or default to PROJECT_SOURCE_DIR
    if(DEFINED Coverage_BASE_DIRECTORY)
        get_filename_component(BASEDIR ${Coverage_BASE_DIRECTORY} ABSOLUTE)
    else()
        set(BASEDIR ${PROJECT_SOURCE_DIR})
    endif()

    # Conditional arguments
    if(CPPFILT_PATH AND NOT ${Coverage_NO_DEMANGLE})
      set(GENHTML_EXTRA_ARGS "--demangle-cpp")
    endif()

    # Setting up commands which will be run to generate coverage data.
    # Cleanup lcov
    set(LCOV_CLEAN_CMD
        ${LCOV_PATH} ${Coverage_LCOV_ARGS} --gcov-tool ${GCOV_PATH} -directory .
        -b ${BASEDIR} --zerocounters
    )
    # Create baseline to make sure untouched files show up in the report
    set(LCOV_BASELINE_CMD
        ${LCOV_PATH} ${Coverage_LCOV_ARGS} --gcov-tool ${GCOV_PATH} -c -i -d . -b
        ${BASEDIR} -o ${Coverage_NAME}.base
    )
    # Run tests
    set(LCOV_EXEC_TESTS_CMD
        ${Coverage_EXECUTABLE} ${Coverage_EXECUTABLE_ARGS}
    )
    # Capturing lcov counters and generating report
    set(LCOV_CAPTURE_CMD
        ${LCOV_PATH} ${Coverage_LCOV_ARGS} --gcov-tool ${GCOV_PATH} --directory . -b
        ${BASEDIR} --capture --output-file ${Coverage_NAME}.capture
    )
    # add baseline counters
    set(LCOV_BASELINE_COUNT_CMD
        ${LCOV_PATH} ${Coverage_LCOV_ARGS} --gcov-tool ${GCOV_PATH} -a ${Coverage_NAME}.base
        -a ${Coverage_NAME}.capture --output-file ${Coverage_NAME}.total
    )
    # filter collected data to final coverage report
    set(LCOV_FILTER_CMD
        ${LCOV_PATH} ${Coverage_LCOV_ARGS} --gcov-tool ${GCOV_PATH} --remove
        ${Coverage_NAME}.total --output-file ${Coverage_NAME}.info
    )
    # Generate HTML output
    set(LCOV_GEN_HTML_CMD
        ${GENHTML_PATH} ${GENHTML_EXTRA_ARGS} ${Coverage_GENHTML_ARGS} -o
        ${Coverage_NAME} ${Coverage_NAME}.info
    )
    if(${Coverage_SONARQUBE})
        # Generate SonarQube output
        set(GCOVR_XML_CMD
            ${GCOVR_PATH} --sonarqube ${Coverage_NAME}_sonarqube.xml -r ${BASEDIR} ${GCOVR_ADDITIONAL_ARGS}
            ${GCOVR_EXCLUDE_ARGS} --object-directory=${PROJECT_BINARY_DIR}
        )
        set(GCOVR_XML_CMD_COMMAND
            COMMAND ${GCOVR_XML_CMD}
        )
        set(GCOVR_XML_CMD_BYPRODUCTS ${Coverage_NAME}_sonarqube.xml)
        set(GCOVR_XML_CMD_COMMENT COMMENT "SonarQube code coverage info report saved in ${Coverage_NAME}_sonarqube.xml.")
    endif()


    if(CODE_COVERAGE_VERBOSE)
        message(STATUS "Executed command report")
        message(STATUS "Command to clean up lcov: ")
        string(REPLACE ";" " " LCOV_CLEAN_CMD_SPACED "${LCOV_CLEAN_CMD}")
        message(STATUS "${LCOV_CLEAN_CMD_SPACED}")

        message(STATUS "Command to create baseline: ")
        string(REPLACE ";" " " LCOV_BASELINE_CMD_SPACED "${LCOV_BASELINE_CMD}")
        message(STATUS "${LCOV_BASELINE_CMD_SPACED}")

        message(STATUS "Command to run the tests: ")
        string(REPLACE ";" " " LCOV_EXEC_TESTS_CMD_SPACED "${LCOV_EXEC_TESTS_CMD}")
        message(STATUS "${LCOV_EXEC_TESTS_CMD_SPACED}")

        message(STATUS "Command to capture counters and generate report: ")
        string(REPLACE ";" " " LCOV_CAPTURE_CMD_SPACED "${LCOV_CAPTURE_CMD}")
        message(STATUS "${LCOV_CAPTURE_CMD_SPACED}")

        message(STATUS "Command to add baseline counters: ")
        string(REPLACE ";" " " LCOV_BASELINE_COUNT_CMD_SPACED "${LCOV_BASELINE_COUNT_CMD}")
        message(STATUS "${LCOV_BASELINE_COUNT_CMD_SPACED}")

        message(STATUS "Command to filter collected data: ")
        string(REPLACE ";" " " LCOV_FILTER_CMD_SPACED "${LCOV_FILTER_CMD}")
        message(STATUS "${LCOV_FILTER_CMD_SPACED}")

        message(STATUS "Command to generate lcov HTML output: ")
        string(REPLACE ";" " " LCOV_GEN_HTML_CMD_SPACED "${LCOV_GEN_HTML_CMD}")
        message(STATUS "${LCOV_GEN_HTML_CMD_SPACED}")

        if(${Coverage_SONARQUBE})
            message(STATUS "Command to generate SonarQube XML output: ")
            string(REPLACE ";" " " GCOVR_XML_CMD_SPACED "${GCOVR_XML_CMD}")
            message(STATUS "${GCOVR_XML_CMD_SPACED}")
        endif()
    endif()

    # Setup target
    add_custom_target(${Coverage_NAME}
        COMMAND ${LCOV_CLEAN_CMD}
        COMMAND ${LCOV_BASELINE_CMD}
        COMMAND ${LCOV_EXEC_TESTS_CMD}
        COMMAND ${LCOV_CAPTURE_CMD}
        COMMAND ${LCOV_BASELINE_COUNT_CMD}
        COMMAND ${LCOV_FILTER_CMD}
        COMMAND ${LCOV_GEN_HTML_CMD}

        # Set output files as GENERATED (will be removed on 'make clean')
        BYPRODUCTS
            ${Coverage_NAME}.base
            ${Coverage_NAME}.capture
            ${Coverage_NAME}.total
            ${Coverage_NAME}.info
            ${Coverage_NAME}/index.html
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
        DEPENDS ${Coverage_DEPENDENCIES}
        VERBATIM # Protect arguments to commands
        COMMENT "Resetting code coverage counters to zero.\nProcessing code coverage counters and generating report."
    )

    # Show where to find the lcov info report
    add_custom_command(TARGET ${Coverage_NAME} POST_BUILD
        COMMAND ;
        COMMENT "Lcov code coverage info report saved in ${Coverage_NAME}.info."
    )

    # Show info where to find the report
    add_custom_command(TARGET ${Coverage_NAME} POST_BUILD
        COMMAND ;
        COMMENT "Open ./${Coverage_NAME}/index.html in your browser to view the coverage report."
    )

endfunction() # setup_target_for_coverage_lcov


function(append_coverage_compiler_flags)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COVERAGE_COMPILER_FLAGS}" PARENT_SCOPE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_COMPILER_FLAGS}" PARENT_SCOPE)
    message(STATUS "Appending code coverage compiler flags: ${COVERAGE_COMPILER_FLAGS}")
endfunction() # append_coverage_compiler_flags


