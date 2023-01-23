#! /bin/bash

thresholds=("85" "90" "60")
PASS=0
FAIL=1
PATH_TO_COVERAGE_FILE=../build/CodeCoverage/Coverage.txt

# Get the code coverage report from coverage.txt
total_coverage=$(grep -F "Total:" $PATH_TO_COVERAGE_FILE | tr -d ' ')

# Extract the line coverage percentage
line_coverage=($(echo "$total_coverage" | awk -F '|' '{print $2}' | awk -F '%' '{print $1}' ))

# Extract the function coverage percentage
function_coverage=($(echo "$total_coverage" | awk -F '|' '{print $3}' | awk -F '%' '{print $1}'))

# Extract the branch coverage percentage
branch_coverage=($(echo "$total_coverage" | awk -F '|' '{print $4}' | awk -F '%' '{print $1}'))



# Check if the line coverage is less than 85%
line_threshold=$PASS
if [[ "$line_coverage)" < "${thresholds[0]}" ]];
then
    echo "Line coverage should be greater than ${thresholds[0]}%: FAILED"
    line_threshold=$FAIL
else
    echo "Line coverage is: $line_coverage%: PASSED"
fi

## Check if the function coverage is less than 90%
function_threshold=$PASS
if [[ "$function_coverage" < "${thresholds[1]}" ]]; 
then
    echo "Function coverage should be greater than ${thresholds[1]}%: FAILED"
    function_threshold=$FAIL
else
    echo "Function coverage is: $function_coverage%: PASSED"
fi

# Check if the branch coverage is less than 60%
branch_threshold=$PASS
if [[ "$branch_coverage" < "${thresholds[2]}" ]]; 
then
    echo "Branch coverage should be greater than ${thresholds[2]}%: FAILED"
    branch_threshold=$FAIL
else
    echo "Branch coverage is: $branch_coverage%: PASSED"
fi


if [[ $line_threshold = $FAIL || $function_threshold = $FAIL || $branch_threshold = $FAIL ]];
then
    echo " "
    echo "Code Coverage FAILED!"
    exit $FAIL
else
    echo " "
    echo "Code Coverage PASSED!"
    exit $PASS
fi