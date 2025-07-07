#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <matplotlibcpp.h>

double exponential(double lambda) {
    double random = static_cast<double>(rand()) / RAND_MAX;
    return lambda * exp(-lambda * random);
}

int main() {
    const int lambda = 2;
    const int N = 20000;

    double exponentialValues[N];
    for (int i = 0; i < N; ++i) {
        exponentialValues[i] = exponential(lambda);
    }
}