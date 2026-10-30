#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

struct FVector {
    float X, Y, Z;
};

struct FFastDot
{
    float A;
    float B;
    float C;
    float (FFastDot::*Kernel)(const FVector* Vec);
    int SavedOps;

    float FastDotZZZ(const FVector* Vec);
    float FastDotZZO(const FVector* Vec);
    float FastDotZZG(const FVector* Vec);
    float FastDotZOZ(const FVector* Vec);
    float FastDotZOO(const FVector* Vec);
    float FastDotZOG(const FVector* Vec);
    float FastDotZGZ(const FVector* Vec);
    float FastDotZGO(const FVector* Vec);
    float FastDotZGG(const FVector* Vec);
    float FastDotOZZ(const FVector* Vec);
    float FastDotOZO(const FVector* Vec);
    float FastDotOZG(const FVector* Vec);
    float FastDotOOZ(const FVector* Vec);
    float FastDotOOO(const FVector* Vec);
    float FastDotOOG(const FVector* Vec);
    float FastDotOGZ(const FVector* Vec);
    float FastDotOGO(const FVector* Vec);
    float FastDotOGG(const FVector* Vec);
    float FastDotGZZ(const FVector* Vec);
    float FastDotGZO(const FVector* Vec);
    float FastDotGZG(const FVector* Vec);
    float FastDotGOZ(const FVector* Vec);
    float FastDotGOO(const FVector* Vec);
    float FastDotGOG(const FVector* Vec);
    float FastDotGGZ(const FVector* Vec);
    float FastDotGGO(const FVector* Vec);
    float FastDotGGG(const FVector* Vec);
};

struct TestResult {
    bool passed;
    std::string name;
    float expected;
    float actual;
};

std::vector<TestResult> results;

void check(const std::string& name, float actual, float expected, float epsilon = 1e-4f) {
    bool pass = std::abs(actual - expected) <= epsilon;
    results.push_back({pass, name, expected, actual});
}

int main() {
    std::ofstream log("vitatest_log.txt");
    log << "VitaTest Build Version 1.0" << std::endl;

    FFastDot dot;
    dot.A = 2.0f;
    dot.B = 3.0f;
    dot.C = 4.0f;

    FVector vec = {1.0f, 2.0f, 3.0f};

    check("FastDotGGG Normal", dot.FastDotGGG(&vec), 20.0f);

    FVector vec_zero = {0.0f, 0.0f, 0.0f};
    check("FastDotGGG Zero", dot.FastDotGGG(&vec_zero), 0.0f);

    check("FastDotZZZ", dot.FastDotZZZ(&vec), 0.0f);
    check("FastDotOOO", dot.FastDotOOO(&vec), 6.0f);
    check("FastDotOZG", dot.FastDotOZG(&vec), 13.0f);

    int passed = 0;
    for (const auto& r : results) {
        if (r.passed) passed++;
        else log << "FAIL: " << r.name << " (Expected: " << r.expected << ", Actual: " << r.actual << ")" << std::endl;
    }
    log << "Total tests: " << results.size() << ", Passed: " << passed << std::endl;

    return 0;
}
