#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <vector>
#include "matplotlib-cpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

double pareto(double a, double boundary) {
    double random = (static_cast<double>(rand()) / RAND_MAX);
    return boundary * pow(1.0 - random, -1.0 / a);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int a = 2;
    const double boundary = 1;
    const int N = 20000;

    std::vector<int> distributions(21, 0);
    for (int i = 0; i < N; ++i) {
        double value = pareto(a, boundary);
        int index = static_cast<int>(value);
        distributions[std::min(index, 20)]++;
    }

    plt::ylabel("Count");
    plt::xlabel("Random Value");
    plt::bar(distributions);
    plt::show();
}