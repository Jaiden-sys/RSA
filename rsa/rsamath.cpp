//
// Created by roman on 17.05.25.
//
#include "rsamath.h"
#include <random>
#include <cmath>
#include <cstdint>
//#include <boost/multiprecision/cpp_int.hpp>
const std::vector<std::pair<uint64_t, std::vector<uint64_t>>> WITNESS_RANGES = {
    {2047, {2}},
    {1373653, {2, 3}},
    {9080191, {31, 73}},
    {25326001, {2, 3, 5}},
    {3215031751, {2, 3, 5, 7}},
    {4759123141, {2, 7, 61}},
    {1122004669633, {2, 13, 23, 1662803}},
    {2152302898747, {2, 3, 5, 7, 11}},
    {3474749660383, {2, 3, 5, 7, 11, 13}},
    {341550071728321, {2, 3, 5, 7, 11, 13, 17}}
};

uint64_t math::modPow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {result = (result*base) % mod;}
        base = (base * base) % mod;
        exp >>= 1; //exp /= 2
    }
    return result;
}
uint64_t math::random(uint64_t min,uint64_t max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint64_t> distrib(min,max);
    return distrib(gen);
}

bool math::isPrimeMillerRabin(uint64_t n) {
    for (uint64_t p : {2,3,5,6,11,13,17,19,23,29}) {
        if (n % p == 0){return n == p;}
    }
    if ((n & 1) == 0) return false; //n % 2 == 0

    uint64_t d = n - 1;
    uint64_t s = 0;
    while ((d & 1) == 0) { // d % 2 == 0
        d >>= 1; // d /= 2
        s++;
    }
    for (const auto& [limit,bases] : WITNESS_RANGES) {
        if (n < limit) {
            for (uint64_t a : bases) {
                u_int64_t x = modPow(a,d,n);
                if (x == 1 || x == n-1) continue;
                bool composite = true;
                for (uint64_t j = 0;j < s - 1; j++) {
                    x = modPow(x,2,n);
                    if (x == n - 1) {
                        composite = false;
                        break;
                    }
                }
                if (composite) return false;
            }
            return true;
        }
    }
    return true;
}

uint64_t math::generatePrime(uint64_t min, uint64_t max) {
    while (true) {
        uint64_t candidate = random(min,max);
        if (isPrimeMillerRabin(candidate)) return candidate;
    }
}

