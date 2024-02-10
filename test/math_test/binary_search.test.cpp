#include<bits/stdc++.h>
#include "../../src/math/binary_search.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_4_B"

using namespace std;

int main(){
    int N ; cin >> N;
    const int n = 10000;     //  [0, N) の乱数を発生
    std::random_device rnd;     // 非決定的な乱数生成器を生成
    std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
    std::uniform_int_distribution<> randN(0, n-1);
    vector<int>v(N);
    for(auto& e : v) cin >> e;
    int Q; cin >> Q;
    int ans = 0;
    map<int,int>mp;
    map<int,int>maxi;
    int crt;
    auto f = [&](int mid){
        return v[mid] >= crt;
    };
    auto mf = [&](int mid){
        return v[mid] <= crt;
    };
    for(int i = 0; i < N; ++i){
        maxi[v[i]] = i;
        if(mp.find(v[i]) == mp.end()){
            mp[v[i]]  = i;
        }
    }
    for(int i = 0; i < Q; ++i){
        cin >> crt;
        int rnd = randN(mt);
        if(rnd % 2 == 0){
            int id = minimize(-1, N - 1,f);
            if(mp.find(crt) == mp.end()){
                assert(id == -1 || v[id] != crt);
            } else {
                assert(mp[crt] == id);
                assert(v[id] == crt);
                ++ans;
            }
        } else  {
            int id = maximize(0, N,mf);
            if(maxi.find(crt) == maxi.end()){
                assert(id == N || v[id] != crt);
            } else {
                assert(id == maxi[crt]);
                assert(v[id] == crt);
                ++ans;
            }
            
        }
        
    }
    cout << ans << endl;
}

