//verifiyed @ contest: Codeforces Round #535 (Div. 3), problem: (B) Divisors of Two Integers
// https://atcoder.jp/contests/abc142/submissions/7772465
#include <bits/stdc++.h>
using namespace std;
template<typename T>
auto divisors(T n){
    vector<T>v;
    for(T i = 1; i *  i <= n;i++){
        if(n % i)continue;
        v.push_back(i);
        if(i != 1 and i * i != n)
            v.push_back(n /i);
    }
    // input : 6 ->  1 2 3 6
    // input : 1 -> 1
    // input : 2 -> 2
    if(n != 1) v.push_back(n);
    sort(v.begin(),v.end());
    return v;
}


