//
// Created by roman on 17.05.25.
//
#pragma once
#include <random>
namespace math {
    bool isPrimeMillerRabin(long long n);
    long generatePrime(long min,long max);
    long long modPow(long base,long exp,long mod);
    long long random(long long min, long long max);
}