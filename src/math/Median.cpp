#include<bits/stdc++.h>
using namespace std;

template <class Itr>
auto Median(Itr first,Itr last){
	  //when value_type is double or long double , you should use "round"" function
		//these Iterator must be Random Access Iterator
    typename iterator_traits<Itr>::difference_type n = distance(first, last);
    sort(first,last);
    if(n % 2 == 1){
        return *(first+n/2);
    } else {
        return (*(first+n/2)+*(first+n/2-1))/2;
    }
}
