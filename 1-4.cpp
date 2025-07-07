#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
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
    const int N = 2000;

    double sum = 0.0;
    std::vector<double> y(N + 1, 0.0);
    for (int i = 1; i <= N; i++) {
        sum += pareto(a, boundary);
        double value = sum / i;
        y[i] = value;
    }

    plt::ylabel("Count");
    plt::xlabel("Random Value [x0.1]");
    plt::plot(y);
    plt::show();
}