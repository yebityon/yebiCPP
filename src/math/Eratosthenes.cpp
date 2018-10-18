class Prime{
    vector<bool>Isprime;
    vector<int>prime;
public:
    int size;
    Prime(int n) : Isprime(n+1,true),size(n+1){
        Isprime[0] = Isprime[1] = false;
        for(int i = 2; i<=size; i++){
            if(!Isprime[i])continue;
            prime.push_back(i);
            for(int j = 2;i*j <=size;j++) Isprime[i*j] = false;
        }
    }
    bool IsPrime(int n){return (n<=size? Isprime[n]:false);}
    int indexOf(int i){return (i<prime.size()?prime[i]:INF);}
};

