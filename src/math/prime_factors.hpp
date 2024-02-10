// @verifyed : https://atcoder.jp/contests/abc142/submissions/7772922
#include <bits/stdc++.h>
using namespace std;
/*
 Factorize the num.
 60 -> {2,2,3.5}
 2*2*3*5 = 60;
 1 -> 0;
 */
template <typename T> vector<T> factorize(T n) {
    vector<T> v;
    T i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            v.push_back(i);
            n /= i;
        } else {
            i++;
        }
    }
    if (n != 1) v.push_back(n);
    return v;
};
template <typename T> set<T> primeFactors(const vector<T> &vec) {
    /* vecotor must be factolized*/
    set<T> res;
    for (auto e : vec) { res.insert(e); }
    return res;
}
