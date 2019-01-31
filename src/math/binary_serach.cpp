template<class T,class U>
auto cal(int mid, T &v, U &value ){
    //return the maximum index which v[index] <= value
    return v[mid].first<=value ;
}
template<class T,class U>
auto mcal(int mid,T &v, U &value){
		//return the minimum index which v[index] >= value
    return v[mid].first>=value;
}
template<class T,class U>
auto  minimize_bsearch(int imin,int imax,T &v, U &value){ //(imin,imax]
    while(imax - imin > 1){
        int mid = imin + (imax - imin)/2;
        if(mcal(mid,v,value)) imax = mid;
        else imin = mid;
    }
    return imax; //imax is ans
}

template<class T,class U>
auto  maximize_bsearch(int imin,int imax, T &v,U &value){ //[imin,imax)
    while(imax - imin > 1){
        int mid = imin + (imax - imin)/2;
        if(cal(mid,v,value)) imin = mid;
        else imax = mid;
    }
    return imin; //imin is ans
}

