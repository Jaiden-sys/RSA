// rsa.cpp
#include "rsa.h"
#include "rsamath.h"
#include <numeric>


RSA::RSA() : p(0), q(0), module(0), phi(0), e(0) {}

bool RSA::isCoprime(uint64_t a, uint64_t b) const {
    return std::gcd(a, b) == 1;
}

void RSA::generatePrimes() {
    p = math::generatePrime(MIN, MAX);
    do {
        q = math::generatePrime(MIN, MAX);
    } while (q == p); // Гарантируем разные простые числа
}

void RSA::calcModule() {
    module = p * q;
}

void RSA::calcEuler() {
    phi = (p - 1) * (q - 1);
}

void RSA::calcPublicExponent() {
    const std::vector<uint64_t> candidates = {65537, 257, 17, 5, 3};
    for (uint64_t candidate : candidates) {
        if (candidate < phi && isCoprime(candidate, phi)) {
            e = candidate;
            return;
        }
    }

    do {
        e = math::random(3, phi - 1);
    } while (!isCoprime(e, phi));
}

void RSA::calcSecretExponent(uint64_t e, uint64_t phi) {
    if (math::extended_gcd(e,phi))
}
