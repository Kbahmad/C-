#include "Long.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>

LongNumber calculatePi(int iterations, int precision) {
    LongNumber pi(0.0, precision);
    LongNumber four(4.0, precision);
    LongNumber denominator(1.0, precision);
    LongNumber sign(1.0, precision);

    std::cout << "Initial values: pi = " << pi << ", sign = " << sign
              << ", denominator = " << denominator << std::endl;

    std::ofstream outfile("pi_values.csv");
    outfile << "Iteration,Pi Value\n";

    std::ofstream timefile("pi_calculation_time.csv");
    timefile << "Iteration,Time Taken (milliseconds)\n";

    for (int i = 0; i < iterations; ++i) {

        auto start = std::chrono::high_resolution_clock::now();

        pi = pi + sign * (four / denominator);

        outfile << i + 1 << "," << pi.getIntegerPart() << "." << pi.getFractionalPart() << "\n";

        denominator = denominator + 2.0_longnum;
        sign = -sign;

        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        timefile << i + 1 << "," << duration.count() << "\n";

        std::cout << "Iteration " << i + 1 << " took " << duration.count() << " milliseconds." << std::endl;
    }

    outfile.close();
    timefile.close();

    return pi;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: ./pi <iterations> <decimal_places>\n";
        return 1;
    }

    int iterations = std::stoi(argv[1]);
    int decimal_places = std::stoi(argv[2]);

    auto start = std::chrono::high_resolution_clock::now();

    LongNumber pi = calculatePi(iterations, decimal_places);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Pi calculated to " << decimal_places << " decimal places: "
              << std::fixed << std::setprecision(decimal_places) << pi << std::endl;

    std::cout << "Total time for calculation: " << duration.count() << " milliseconds." << std::endl;

    if (duration.count() > 1000) {
        std::cerr << "Error: Total calculation time exceeds 1 second." << std::endl;
    } else {
        std::cout << "Total calculation time is within the acceptable limit." << std::endl;
    }

    return 0;
}