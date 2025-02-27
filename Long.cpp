#include "Long.hpp"
#include <stdexcept>

LongNumber::LongNumber() : integerPart(0), fractionalPart(0), precision(64) {}

LongNumber::LongNumber(long double number, int precision) : precision(precision) {
    integerPart = static_cast<long long>(number);
    fractionalPart = static_cast<long long>((number - integerPart) * pow2(precision));
    normalize();
}

LongNumber::LongNumber(const LongNumber& other) {
    integerPart = other.integerPart;
    fractionalPart = other.fractionalPart;
    precision = other.precision;
}

LongNumber::~LongNumber() {}

LongNumber& LongNumber::operator=(const LongNumber& other) {
    if (this != &other) {
        integerPart = other.integerPart;
        fractionalPart = other.fractionalPart;
        precision = other.precision;
    }
    return *this;
}

LongNumber LongNumber::operator+(const LongNumber& other) const {
    LongNumber result;
    result.integerPart = integerPart + other.integerPart;
    result.fractionalPart = fractionalPart + other.fractionalPart;
    result.precision = precision;
    result.normalize();

    std::cout << "Adding: " << *this << " + " << other << " = " << result << std::endl;

    return result;
}

LongNumber LongNumber::operator-(const LongNumber& other) const {
    LongNumber result;
    result.integerPart = integerPart - other.integerPart;
    result.fractionalPart = fractionalPart - other.fractionalPart;
    result.precision = precision;
    result.normalize();
    return result;
}

LongNumber LongNumber::operator*(const LongNumber& other) const {
    LongNumber result;
    long long a = integerPart * pow2(precision) + fractionalPart;
    long long b = other.integerPart * pow2(precision) + other.fractionalPart;
    long long product = a * b;
    result.integerPart = product / pow2(2 * precision);
    result.fractionalPart = (product % pow2(2 * precision)) / pow2(precision);
    result.precision = precision;
    result.normalize();
    return result;
}

LongNumber LongNumber::operator/(const LongNumber& other) const {
    if (other.integerPart == 0 && other.fractionalPart == 0) {
        throw std::invalid_argument("Division by zero");
    }
    LongNumber result;
    long long a = integerPart * pow2(precision) + fractionalPart;
    long long b = other.integerPart * pow2(precision) + other.fractionalPart;
    long long quotient = (a * pow2(precision)) / b;
    result.integerPart = quotient / pow2(precision);
    result.fractionalPart = quotient % pow2(precision);
    result.precision = precision;
    result.normalize();
    return result;
}

LongNumber LongNumber::operator-() const {
    LongNumber result;
    result.integerPart = -integerPart;
    result.fractionalPart = -fractionalPart;
    result.precision = precision;
    result.normalize();
    return result;
}

bool LongNumber::operator==(const LongNumber& other) const {
    return integerPart == other.integerPart && fractionalPart == other.fractionalPart;
}

bool LongNumber::operator!=(const LongNumber& other) const {
    return !(*this == other);
}

bool LongNumber::operator<(const LongNumber& other) const {
    if (integerPart < other.integerPart) return true;
    if (integerPart > other.integerPart) return false;
    return fractionalPart < other.fractionalPart;
}

bool LongNumber::operator>(const LongNumber& other) const {
    if (integerPart > other.integerPart) return true;
    if (integerPart == other.integerPart && fractionalPart > other.fractionalPart) return true;
    return false;
}

void LongNumber::setPrecision(int precision) {
    this->precision = precision;
    fractionalPart = (fractionalPart * pow2(precision)) / pow2(this->precision);
    normalize();
}

std::ostream& operator<<(std::ostream& os, const LongNumber& num) {
    os << num.integerPart << "." << num.fractionalPart;
    return os;
}

void LongNumber::normalize() {
    if (fractionalPart >= pow2(precision)) {
        integerPart += fractionalPart / pow2(precision);
        fractionalPart %= pow2(precision);
    } else if (fractionalPart < 0) {
        integerPart -= 1 + (-fractionalPart) / pow2(precision);
        fractionalPart += pow2(precision);
    }
}

long long LongNumber::pow2(int n) const {
    return 1LL << n;
}

LongNumber operator""_longnum(long double number) {
    return LongNumber(number);
}