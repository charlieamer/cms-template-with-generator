#include "testlib.h"
#include <fstream>
#include <string>
#include <assert.h>

// optional function, might be useful if you want to create test cases that
// gradually increase the difficulty of the generated tests
float lerp(float a, float b, float f)
{
    return a + f * (b - a);
}

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    // You may use rnd.next(...) functions from testlib.h to generate random things.
    // rnd.next(from, to)
    // rnd.next(regex_like_pattern)
}