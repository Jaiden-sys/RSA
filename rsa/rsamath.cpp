//
// Created by roman on 17.05.25.
//
#include "rsamath.h"
#include <random>
#include <cmath>
#include <cstdint>
//#include <boost/multiprecision/cpp_int.hpp>
namespace math {

    uint64_t modPow(uint64_t base, uint64_t exp, uint64_t mod) {
        uint64_t result = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) { result = (result * base) % mod; }
            base = (base * base) % mod;
            exp >>= 1; //exp /= 2
        }
        return result;
    }
    bool isPrimeMillerRabin(uint64_t n) {
        for (uint64_t p : {2, 3, 5, 6, 11, 13, 17, 19, 23, 29}) {
            if (n % p == 0) { return n == p; }
        }
        if ((n & 1) == 0) return false; //n % 2 == 0

        uint64_t d = n - 1;
        uint64_t s = 0;
        while ((d & 1) == 0) { // d % 2 == 0
            d >>= 1; // d /= 2
            s++;
        }
        for (const auto& [limit, bases] : WITNESS_RANGES) {
            if (n < limit) {
                for (uint64_t a : bases) {
                    uint64_t x = modPow(a, d, n);
                    if (x == 1 || x == n - 1) continue;
                    bool composite = true;
                    for (uint64_t j = 0; j < s - 1; j++) {
                        x = modPow(x, 2, n);
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
    std::mt19937& get_rn() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return gen;
    }
    uint64_t random(uint64_t min, uint64_t max){
        std::uniform_int_distribution<uint64_t> distib(min, max);
        return distib(get_rn());
    }
    uint64_t generatePrime(uint64_t min, uint64_t max) {
        while (true) {
            uint64_t candidate = random(min, max);
            if (isPrimeMillerRabin(candidate)) return candidate;
        }
    }
    uint64_t extended_gcd(uint64_t a, uint64_t b, uint64_t& x, uint64_t& y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }
        uint64_t x1, y1;
        uint64_t d = extended_gcd(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }

};

