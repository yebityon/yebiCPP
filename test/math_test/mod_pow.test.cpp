#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"

#include "../../src/math/mod_pow.cpp"

int main(){
    long long m,n; cin >> m >> n;
    cout << modpow(m,n) << endl;
}
