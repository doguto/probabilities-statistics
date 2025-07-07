#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <vector>
#include "matplotlib-cpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

double clt_normal(double mean = 2.0, double variance = 7.0) {
    double sum = 0.0;
    for (int i = 0; i < 12; ++i) {
        sum += static_cast<double>(rand()) / RAND_MAX;  // U[0,1]
    }
    return mean + sqrt(variance) * sum;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int N = 35;

    double sum = 0.0;
    std::vector<double> y(N + 1, 0.0);
    for (int i = 1; i <= 10000; i++) {
        double value = clt_normal();
        y[std::min(static_cast<int>(value), N)] += 1.0 / 10000;
    }

    plt::title("N(2,7)");
    plt::ylabel("Value");
    plt::xlabel("Count");
    plt::bar(y);
    plt::show();
}