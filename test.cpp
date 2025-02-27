#include "Long.hpp"
#include <iostream>
#include <cassert>

void testArithmeticOperations() {
    LongNumber a = 3.14_longnum;
    LongNumber b = 2.71_longnum;

    LongNumber c = a + b;
    std::cout << a << " + " << b << " = " << c << std::endl;

    LongNumber d = a - b;
    std::cout << a << " - " << b << " = " << d << std::endl;

    LongNumber e = a * b;
    std::cout << a << " * " << b << " = " << e << std::endl;

    LongNumber f = a / b;
    std::cout << a << " / " << b << " = " << f << std::endl;
}

void testComparisonOperators() {
    LongNumber a = 6127989408.6841951676_longnum;
    LongNumber b = 8611528784.10_longnum;

    assert((a == b) == false);
    assert((a != b) == true);

    assert((a < b) == true);
    assert((a > b) == false);

    std::cout << "Comparison tests passed!" << std::endl;
}

void testPrecision() {
    LongNumber a = 3.14159265358979323846_longnum;
    a.setPrecision(32);

    std::cout << "Pi with 32-bit precision: " << a << std::endl;
}

void testDivisionByZero() {
    LongNumber a = 5.0_longnum;
    LongNumber b = 0.0_longnum;
    try {
        LongNumber c = a / b;
        std::cout << "Test failed: Division by zero did not throw an exception!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Division by zero test passed!" << std::endl;
    }
}

void testNegativeNumbers() {
    LongNumber a = -3.14_longnum;
    LongNumber b = 2.71_longnum;
    LongNumber result = a + b;
    std::cout << a << " + " << b << " = " << result << std::endl;
}

int main() {
    std::cout << "Testing Arithmetic Operations:" << std::endl;
    testArithmeticOperations();

    std::cout << "\nTesting Comparison Operators:" << std::endl;
    testComparisonOperators();

    std::cout << "\nTesting Precision Setting:" << std::endl;
    testPrecision();

    std::cout << "\nTesting Division by Zero:" << std::endl;
    testDivisionByZero();

    std::cout << "\nTesting Negative Numbers:" << std::endl;
    testNegativeNumbers();

    std::cout << "\nAll tests passed!" << std::endl;
    return 0;
}