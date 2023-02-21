#include<functional>
#include<iostream>
// main(){};
//
//
// verified@ 31/1/2019
// AtC  https://atcoder.jp/contests/code-festival-2018-final-open/submissions/4131587


/*
 (imin,imax] -> imax
 return minimum index such that v[index] >= value
 auto f(int mid) {return v[mid] >= value;}
 */
template<class F, class T>
auto  minimize(T imin,T imax,F &f){
    while(imax - imin > 1){
        T mid = imin + (imax - imin)/2;
        if(f(mid)) imax = mid;
        else imin = mid;
    }
    return imax;
}

/*
 [imin,imax) -> imin
 return maximum index such that v[index] <= value
 auto f(int mid) {return v[mid] <= value;}
 */
template<class F,class T>
auto  maximize(T imin,T imax,F &f){
    while(imax - imin > 1){
        T mid = imin + (imax - imin)/2;
        if(f(mid)) imin = mid;
        else imax = mid;
    }
    return imin;
}

