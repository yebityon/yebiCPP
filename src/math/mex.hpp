#include <bits/stdc++.h>
using namespace std;
using Int = long long;

constexpr Int inf = (LLONG_MAX >> 1);

template <typename T>
class mex_set{
    private:
        set<pair<T, T>>S;

    public:
     bool insert(T x){ return false;}
     bool erase(T x){ return false;}
     bool contain(T x){ return false;}
     T mex(T x){ return T(0);}
};
