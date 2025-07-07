#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "matplotlib-cpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

double pareto(double lambda) {
    double random = static_cast<double>(rand()) / RAND_MAX;
    return -std::log(1.0 - random) / lambda;
}

int main() {
    const int lambda = 2;
    const int N = 20000;

    std::vector<double> distributions(101, 0);
    for (int i = 0; i < N; ++i) {
        double value = pareto(lambda);
        int index = static_cast<int>(value / 0.1);
        distributions[std::min(index, 100)]++;
    }

    plt::ylabel("Count");
    plt::xlabel("Random Value [x0.1]");
    plt::bar(distributions);
    plt::show();
}