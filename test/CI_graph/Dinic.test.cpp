#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A"
#include "../../src/graph/Dinic.cpp"

#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e;
    cin>>v>>e;
    Dinic yebi(v+1);
    for(int i = 0; i < e; ++i){
        int a,b,c;cin>>a>>b>>c;
        yebi.add_Edge(a,b,c);
    }
    cout<<yebi.max_flow(0, v-1)<<endl;
}
