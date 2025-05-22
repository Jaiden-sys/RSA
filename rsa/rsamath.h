//
// Created by roman on 17.05.25.
//
#pragma once
#include <random>
#include <vector>ןרו
#include <cstdint>
namespace math {
    static const std::vector<std::pair<uint64_t, std::vector<uint64_t>>> WITNESS_RANGES = {
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

    static constexpr uint64_t MIN = 1ULL << 29; // 2^29
    static constexpr uint64_t MAX = 1ULL << 32; // 2^32
    bool isPrimeMillerRabin(uint64_t n);
    uint64_t generatePrime(uint64_t min,uint64_t max);
    uint64_t modPow(uint64_t base,uint64_t exp,uint64_t mod);
    uint64_t random(uint64_t min, uint64_t max);

};