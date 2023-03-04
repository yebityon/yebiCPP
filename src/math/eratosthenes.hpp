#include <bits/stdc++.h>
using namespace std;

class Prime{
    public :
    vector<bool>isPrime;
    vector<int>prime;
    int size;
    Prime(int N) : isPrime(N+1,true),size(N+1){
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i <= size; i++){
            if(!isPrime[i])continue;
            prime.push_back(i);
            for(int j = 2; i*j <= size; j++ ) isPrime[ i*j ] = false;
        }
    }
    bool isPrime(int N){return ( N <= size ? isPrime[N]:false);}
    int indexOf(int i){return (i < prime.size() ? prime[i] : -1);}
};
