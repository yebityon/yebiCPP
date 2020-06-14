class Prime{
    public :
    vector<bool>Isprime;
    vector<int>prime;
    int size;
    Prime(int N) : Isprime(N+1,true),size(N+1){
        Isprime[0] = Isprime[1] = false;
        for(int i = 2; i<= size; i++){
            if(!Isprime[i])continue;
            prime.push_back(i);
            for(int j = 2;i*j <=size;j++) Isprime[i*j] = false;
        }
    }
    bool IsPrime(int N){return ( N <= size? Isprime[N]:false);}
    int indexOf(int i){return (i<prime.size()?prime[i]:INF);}
};

