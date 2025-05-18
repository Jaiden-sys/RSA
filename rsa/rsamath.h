//
// Created by roman on 17.05.25.
//
#pragma once
#include <random>
#include <vector>
#include <cstdint>
namespace math {
    bool isPrimeMillerRabin(uint64_t n);
    uint64_t generatePrime(uint64_t min,uint64_t max);
    uint64_t modPow(uint64_t base,uint64_t exp,uint64_t mod);
    uint64_t random(uint64_t min, uint64_t max);
    extern const std::vector<std::pair<uint64_t, std::vector<uint64_t>>> WITNESS_RANGES;
}