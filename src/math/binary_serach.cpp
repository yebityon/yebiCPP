#include<fanctional>
#include<iostream>
// main(){};
//
//
// verified@ 31/1/2019
// AtC  https://atcoder.jp/contests/code-festival-2018-final-open/submissions/4131587


template<class F>
auto  minimize_bsearch(int imin,int imax,F &f){ //(imin,imax]
    /*
     return minimum index such that v[index] >= value
     auto f(int mid) {return v[mid] >= value;}
     */
    while(imax - imin > 1){
        int mid = imin + (imax - imin)/2;
        if(f(mid)) imax = mid;
        else imin = mid;
    }
    return imax; //imax is ans
}

template<class F>
auto  maximize_bsearch(int imin,int imax,F &f){ //[imin,imax)
    /*
     return maximum index such that v[index] <= value
     auto f(int mid) {return v[mid] <= value;}
     */
    while(imax - imin > 1){
        int mid = imin + (imax - imin)/2;
        if(f(mid)) imin = mid;
        else imax = mid;
    }
    return imin; //imin is ans
}
