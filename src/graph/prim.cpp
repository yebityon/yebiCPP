#include<bits/stdc++.h>
using namespace std;

template<class T>
class Prim{
public:
    vector<vector<pair<int,T>>>edge;
    T res = 0;
    Prim(vector<vector<pair<int,T>>>&e): edge(e){
        vector<bool>used(e.size(),false);
        priority_queue<pair<T, int>,vector<pair<T, int>>,greater<pair<T, int>>>que;
        que.push(make_pair(0, 0));
        while(not que.empty()){
            auto [cost,v] = que.top();
            que.pop();
            if(used[v])continue;
            used[v] = true;
            res += cost;
            for(auto & e : edge[v]){
                if(not used[e.first])
                    que.emplace(e.second,e.first);
            }
        }
    };
    auto getval(){return res;}
};
