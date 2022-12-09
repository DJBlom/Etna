/**********************************************************************************
 * Contents: Main function for the CppUTest framework.
 *
 * Author: Dawid Blom.
 *
 * Data: December 8, 2022.
 *
 * NOTE: This file contains the main function to used by CppUTest to execute
 *       all the tests of the project.
 *********************************************************************************/
#include "CppUTest/CommandLineTestRunner.h"

int main(int argc, char **argv)
{
        return CommandLineTestRunner::RunAllTests(argc, argv);
}

