#include<bits/stdc++.h>
using namespace std;
template<typename T>
class StronglyConnectedComponents{
    vector<vector<T>>edge,rev_edge,compressed_edge;
    vector<int>order,vcomp;
    vector<bool>visit;
    int v_size = 0,compress_size = 0;
    void dfs(int v){
        visit[v] = true;
        for(auto nv : edge[v])
            if(not visit[nv]) dfs(nv);
        order.push_back(v);
    }
    void dfs_compress(int v){
        vcomp[v] = compress_size;
        for(auto nv : rev_edge[v])
            if(vcomp[nv] == -1) dfs_compress(nv);
    }
    void rev_edge_build(){
        for(int nv = 0; nv  < edge.size(); ++nv)
            for(auto v : edge[nv])
                rev_edge[v].push_back(nv);
    }
    void popsort(){
        for(int v = 0; v < edge.size(); ++v)
            if(not visit[v]) dfs(v);
    }
    void compress_vertex(){
        reverse(order.begin(),order.end());
        for(auto v : order){
            if(vcomp[v] == -1){
                dfs_compress(v); compress_size++;
            }
        }
    }
    
    void strcomp_construct(){
        compress_vertex();
        compressed_edge = vector<vector<T>>(compress_size + 1);
        for(int frm = 0; frm < edge.size(); ++frm)
            for(auto to : edge[frm]){
                if(vcomp[frm] == vcomp[to])continue;
                compressed_edge[vcomp[frm]].push_back(vcomp[to]);
            }
    }
public:
    StronglyConnectedComponents(vector<vector<T>>&e)
    :v_size((int)e.size()),edge(e),order(e.size()),rev_edge(e.size()){};
    
    void build(){
        rev_edge_build();
        visit   = vector<bool>(v_size,false);
        popsort();
        vcomp = vector<int>(v_size,-1);
        strcomp_construct();
    }
    bool isSamePointSet(int v, int u){return vcomp[v] == vcomp[u];}
    
};
signed main(){
}

