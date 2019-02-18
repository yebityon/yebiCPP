//verifiyed @ contest: Codeforces Round #535 (Div. 3), problem: (B) Divisors of Two Integers

#include<bits/stdc++.h>

//main(){}
auto divisors(int n){
    vector<int>v;
    for(int i = 1; i *  i <= n;i++){
        if(n % i)continue;
        v.push_back(i);
        if(i != 1 and i * i != n)
            v.push_back(n /i);
    }
    sort(v.begin(),v.end());
		//v.push_back(n)
		// n itself also divisor.
    return v;
}

