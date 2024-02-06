#include<bits/stdc++.h>
using namespace std;
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D"

#include "../../src/math/divisors.cpp"


int main(){
    int a,b,c; cin >> a >> b >> c;
    auto v = divisors(c);
    int ans = 0;
    for(auto& e : v){
        if(a <= e && e <= b)
            ++ans;
    }
    cout << ans << endl;
}
