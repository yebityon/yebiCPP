//verifiyed @ contest: Codeforces Round #535 (Div. 3), problem: (B) Divisors of Two Integers
// https://atcoder.jp/contests/abc142/submissions/7772465
#include <bits/stdc++.h>
using namespace std;

// input : 6 ->  1 2 3 6
// input : 1 -> 1
// input : 2 -> 2
template<typename T>
auto divisors(T n){
    vector<T>v;
    for(T i = 1; i *  i <= n;i++){
        if(n % i)continue;
        v.emplace_back(i);
        if(i != 1 and i * i != n)
            v.emplace_back(n /i);
    }
    if(n != 1) v.emplace_back(n);
    sort(v.begin(),v.end());
    return v;
}
