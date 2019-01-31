#include <bits/stdc++.h>
//main(){};
//
//
//
//@verify 08/10/2018 ------add minimize_bsearch and maximize_bsearch
auto cal(int mid){
    //W以下最大の数字を探す
    return v[mid]<= W;
}
auto mcal(int mid){
    //W以上最小の数字をふ返すふ
    return v[mid]>=W;
}
auto  minimize_bsearch(int imin,int imax){ //(imin,imax]
    while(imax - imin > 1){
        int mid = imin + (imax - imin)/2;
        if(mcal(mid)) imax = mid;
        else imin = mid;
    }
    return imax; //imax is ans
}

auto  maximize_bsearch(int imin,int imax){ //[imin,imax)
    while(imax - imin > 1){
        int mid = imin + (imax - imin)/2;
        if(cal(mid)) imin = mid;
        else imax = mid;
    }
    return imin; //imin is ans
}



// Mot verify yet....
int UpperBound(int *array,int size,int value){
    //size := arraysize
    //value := the value which you want to know index
    int imax=size-1;//last index
    int imin=0;
    while(imax>=imin){
        int mid=(imax+imin)/2;
        //UpperBoundは単調増加列の最後の要素をのindexを返すため, iminを詰めていく。
        if(array[mid]>value)imax=mid-1;
        else imin=mid+1;
    }
    //答えはimaxとなる
    return imax;
}
//lowerboundは単調増加列の最初の要素のindexを返す
int LowerBound(int *array,int size,int value){
    int imax=size-1;
    int imin=0;
    while(imax>=imin){
        int mid=(imax+imin)/2;
        if(array[mid]>=value)imax=mid-1;
        else imin=mid+1;
    }
    return imin;
}
void arraybinarysearch(int *array,int size,int value){
    //両方閉区間
    /*配列の中から、valueを探索する*/
    int imax=size-1;
    int imin=0;
    int mid;
    //imaxとiminが重なる場合がある
    while(imax>=imin){
        mid=(imax+imin)/2;
        //次の区間に更新する時、midを見る必要は無い。したがってmid+,-1に区間を変更する。
        if(array[mid]>value)imax=mid-1;
        else if(array[mid]<value)imin=mid+1;
        else {
            puts("found");
            //return imin;
        }
    }
}
