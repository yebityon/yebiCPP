#include<bits/stdc++.h>
#define IGNORE
#include "../../src/math/Eratosthenes.cpp"
using namespace std;
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0044"

int main(){
    auto p = Prime(50000 * 2);
    int N;
    while(cin >> N){
        int remu = 0,ramu = 50000 * 2;
        for(auto e : p.prime) {
            if(e < N) remu = max(remu,e);
            else if(e > N) ramu = min(ramu,e);
        }
        cout << remu << " " << ramu << endl;
    }
}
