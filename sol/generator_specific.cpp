#include "testlib.h"
#include <fstream>
#include <string>
#include <assert.h>

float lerp(float a, float b, float f)
{
    return a + f * (b - a);
}

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    inputFile << rnd.next(1, 100) << " "
              << rnd.next(1, 100) << std::endl;
}