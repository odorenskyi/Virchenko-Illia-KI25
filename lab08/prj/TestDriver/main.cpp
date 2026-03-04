#include <iostream>
#include <cmath>
#include "s_calculation.h"

int main() {
    double x, y, z;

    std::cout << "Enter x, y, z separated by space or Enter: ";
    std::cin >> x >> y >> z;

    // Check if sin(x) is too small
    if (std::fabs(std::sin(x)) < 1e-5) {
        std::cout << "Error: sin(x) is too small or zero, computation not possible." << std::endl;
        return 1;
    }

    try {
        double result = s_calculation(x, y, z);
        std::cout << "Result of s_calculation: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
