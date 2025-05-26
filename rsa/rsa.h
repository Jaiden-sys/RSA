//
// Created by roman on 16.05.25.
//
#pragma once
#include <cstdint>
#include <numeric>
class RSA {
private:
    static constexpr uint64_t MIN = 1ULL << 29; // 2^29
    static constexpr uint64_t MAX = 1ULL << 32; // 2^32

    uint64_t p;
    uint64_t q;
    uint64_t module;
    uint64_t phi;
    uint64_t e;

    bool isCoprime(uint64_t a, uint64_t b) const;
public:
    RSA();

    void generatePrimes();
    void calcModule();
    void calcEuler();
    void calcPublicExponent();
    void calcSecretExponent();
    uint64_t getP() const { return p; }
    uint64_t getQ() const { return q; }
    uint64_t getModule() const { return module; }
    uint64_t getEuler() const { return phi; }
    uint64_t getPublicExponent() const { return e; }
    uint64_t getSecretExponent() const {return d;}
};
