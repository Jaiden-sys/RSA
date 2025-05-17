//
// Created by roman on 17.05.25.
//
#include "math.h"
#include <numeric>
#include <random>
#include <cmath>
long long math::modPow(long base, long exp, long mod) {
    long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {result = (result*exp) % mod;}
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
long long math::random(long long min,long long max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long long> distrib(min,max);
    return distrib(gen);
}

bool math::isPrimeMillerRabin(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if ((n & 1) == 0) return false;

    long long d = n - 1;
    long long s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    long long k = (63 - __builtin_clzll(n));
    for (long int i = 0; i <= k; i++) {
        long long a = random(2, n - 2);
        long long x = modPow(a,d,n);
        if (x == 1 || x == (n-1)){continue;}

        for (long int j = 0; j <= s-1; j++) {
            x = modPow(x,2,n);
            if (x == n-1){break;}
            if (x == 1){return false;}
        }
    }
}
