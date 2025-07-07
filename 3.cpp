#include "matplotlib-cpp/matplotlibcpp.h"
#include <vector>
#include <cmath>
#include <random>
#include <map>

namespace plt = matplotlibcpp;

const double LAMBDA = 1.62;
const int NUM_SAMPLES = 10000;
const int MAX_X = 15;

int generate_poisson_from_cdf(double u, const std::vector<double>& cdf) {
    for (size_t i = 0; i < cdf.size(); ++i) {
        if (u < cdf[i]) {
            return static_cast<int>(i);
        }
    }
    return static_cast<int>(cdf.size() - 1);
}

int main() {
    std::vector<double> probabilities(MAX_X + 1);
    std::vector<double> cumulative_probabilities(MAX_X + 1);

    probabilities[0] = std::exp(-LAMBDA);
    cumulative_probabilities[0] = probabilities[0];

    for (int x = 1; x <= MAX_X; ++x) {
        probabilities[x] = probabilities[x - 1] * LAMBDA / x;
        cumulative_probabilities[x] = cumulative_probabilities[x - 1] + probabilities[x];
    }
    cumulative_probabilities.back() = 1.0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::map<int, int> hist;

    for (int i = 0; i < NUM_SAMPLES; ++i) {
        double u = dis(gen);
        int random_val = generate_poisson_from_cdf(u, cumulative_probabilities);
        hist[random_val]++;
    }

    std::vector<double> x_values;
    std::vector<double> relative_frequencies;
    std::vector<double> theory_probs_for_plot;

    for (int i = 0; i <= MAX_X; ++i) {
        x_values.push_back(i);
        relative_frequencies.push_back(static_cast<double>(hist[i]) / NUM_SAMPLES);
        theory_probs_for_plot.push_back(probabilities[i]);
    }
    
    plt::bar(x_values, relative_frequencies);

    plt::title("Poisson Distribution Po(lambda=" + std::to_string(LAMBDA) + ")");
    plt::xlabel("Value (x)");
    plt::ylabel("Probability / Relative Frequency");
    plt::xticks(x_values);
    plt::legend();
    plt::grid(true);

    plt::show();
    // またはファイルに保存する場合
    // plt::save("./poisson_cpp.png");

    return 0;
}