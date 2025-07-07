#include <stdio.h>
#include <stdlib.h>
#include <cmath>

double pareto(double lambda) {
    double random = static_cast<double>(rand()) / RAND_MAX;
    return lambda * exp(-lambda * random);
}

int main() {
    const int lambda = 2;
    double result = pareto(lambda);
    printf("Exponential random variable with lambda = %d: %f\n", lambda, result);
}