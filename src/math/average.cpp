//Not verify yet
//[first, last)
#include <bits/stdc++.h>
using namespace std;

template <class Itr> auto average(Itr first, Itr last) {
    typename iterator_traits<Itr>::difference_type n = distance(first, last);
    return accumulate(first,last,0.0)/n;
}