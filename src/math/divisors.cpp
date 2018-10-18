// Not verify yet.....
#include<bits/stdc++.h>
auto divisors(int n){
    vector<int>v;
    for(int i = 1; i *  i <= n;i++){
        if(n % i)continue;
        v.push_back(i);
        if(i != 1 and i * i != n)
            v.push_back(n /i);
    }
    sort(v.begin(),v.end());
    return v;
}

