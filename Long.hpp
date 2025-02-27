#ifndef LONGNUMBER_HPP
#define LONGNUMBER_HPP

#include <iostream>
#include <string>
#include <cmath>

class LongNumber {
private:
    long long integerPart;
    long long fractionalPart;
    int precision;

    void normalize();
    long long pow2(int n) const;

public:

    LongNumber();
    LongNumber(long double number, int precision = 64);
    LongNumber(const LongNumber& other);
    ~LongNumber();

    LongNumber& operator=(const LongNumber& other);

    LongNumber operator+(const LongNumber& other) const;
    LongNumber operator-(const LongNumber& other) const;
    LongNumber operator*(const LongNumber& other) const;
    LongNumber operator/(const LongNumber& other) const;

    LongNumber operator-() const;

    bool operator==(const LongNumber& other) const;
    bool operator!=(const LongNumber& other) const;
    bool operator<(const LongNumber& other) const;
    bool operator>(const LongNumber& other) const;

    void setPrecision(int precision);

    friend std::ostream& operator<<(std::ostream& os, const LongNumber& num);

    long long getIntegerPart() const { return integerPart; }
    long long getFractionalPart() const { return fractionalPart; }
};

LongNumber operator""_longnum(long double number);

#endif 