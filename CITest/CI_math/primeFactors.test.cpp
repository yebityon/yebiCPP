#include<bits/stdc++.h>
using namespace std;
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A"
#include "../../src/math/primeFactors.cpp"
int main(){
    int N; cin >> N;
    auto p = factorize(N);
    cout << N << ":";
    for(auto t : p)
        cout << " " << t;
    cout << endl;
    
}
