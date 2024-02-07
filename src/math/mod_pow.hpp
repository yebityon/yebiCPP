#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;
template <class T> T modpow(T a, T b) {
    if (b == 0) return T(1);
    if (b % 2 == 0) {
        long long d = modpow(a, b / T(2));
        return (d * d) % mod;
    } else {
        return (a * modpow(a, b - 1) % mod );
    }
}
