#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <filesystem>
namespace fs = std::filesystem;

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent);
void testInit(int argc, char** argv);

std::chrono::steady_clock::time_point timeMeasurementStart;

void startMeasuringTime() {
    timeMeasurementStart = std::chrono::steady_clock::now();
}

void stopMeasuringTime() {
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - timeMeasurementStart).count() << "ms" << std::endl;
}

#define MEASURE_TIME(code) {\
    startMeasuringTime();\
    code;\
    stopMeasuringTime();\
}

bool hasSubtasks;
int globalCount;
bool manualSubtasks;
std::ofstream genFile;

#ifdef _WIN32
#define SEP "\\"
#else
#define SEP "/"
#endif

void generateSubtask(int subtask, int testcase, float testPercent) {
    std::stringstream inputFileName;
    if (!manualSubtasks) {
        inputFileName << ".." SEP "input" SEP "input" << globalCount << ".txt";
    } else {
        inputFileName << ".." SEP "tests" SEP "subtask_" << subtask
                      << "_test_" << testcase << ".in";
    }
    std::ofstream inputFile(inputFileName.str(), std::ios_base::binary);

    makeTest(inputFile, subtask, testcase, testPercent);
    inputFile.close();

    std::stringstream outputFileName;
    
    if (!manualSubtasks) {
        outputFileName << ".." SEP "output" SEP "output" << globalCount << ".txt";
    } else {
        outputFileName << ".." SEP "tests" SEP "subtask_" << subtask
                      << "_test_" << testcase << ".out";
    }
    
    globalCount++;
    std::string outputCommand = "." SEP "main <\"" + inputFileName.str() + "\" >\"" + outputFileName.str() + "\"";
    MEASURE_TIME(system(outputCommand.c_str()));
}

int main (int argc, char** argv) {
    testInit(argc, argv);
    std::ifstream config("../sol/config.txt");
    if (config.bad()) {
        std::cout << 
            "Please make sure config.txt exists with number of "
            "subtasks (first number) followed by number of tasks "
            "in subtasks in each subtask (ex, 5 1 2 3 4 5 will "
            "have 5 subtasks, with 1, 2, 3 ... tasks in each "
            "subtask).";
        return 1;
    }
    std::string countType;
    config >> countType;
    if (fs::exists("../gen/GEN")) {
        fs::remove("../gen/GEN");
    }
    if (countType == "global_count") {
        hasSubtasks = false;
    } else if (countType == "subtask_count") {
        hasSubtasks = true;
        system("mkdir .." SEP "gen");
        genFile.open("..gen/GEN");
    } else if (countType == "manual_subtasks") {
        hasSubtasks = true;
        manualSubtasks = true;
    } else {
        std::cout << "Wrong count_type. Expected global_count, "
                  << "subtask_count or manual_subtasks. Found " << countType;
        return 1;
    }
    if (!manualSubtasks) {
        system("mkdir .." SEP "input");
        system("mkdir .." SEP "output");
    } else {
        system("mkdir .." SEP "tests");
    }
    unsigned subtasks;
    config >> subtasks;
    if (subtasks > 10) {
        std::cout << "WARNING: More than 10 subtasks detected. (" << subtasks << ")\n";
    }
    for (unsigned i=0; i<subtasks; i++) {
        genFile << "# ST: " << std::endl;
        unsigned tasks;
        config >> tasks;
        if (tasks > 30) {
            std::cout << "WARNING: More than 30 tasks detected (" << tasks << ")\n";
        }
        std::cout << "---- subtask " << (i + 1) << "/" << subtasks << "\n";
        for (unsigned j=0; j<tasks; j++) {
            genFile << globalCount + 1;
            if ((i != subtasks -1) || (j != tasks-1)) {
                genFile << std::endl;
            }
            std::cout << (j + 1) << "/" << tasks << "\n";
            generateSubtask(i, j, (float)j / (float)(tasks - 1));
        }
    }
    if (hasSubtasks && !manualSubtasks) {
        std::cout << "DONT FORGET TO EDIT gen/GEN FILE !!!!!!\n";
    }
}