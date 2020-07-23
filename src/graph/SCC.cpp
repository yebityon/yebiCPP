#include<bits/stdc++.h>
using namespace std;
// verifyed @AOJ http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3871163#1
//
template<class T>
class StronglyConnectedComponents{
    vector<vector<T>>edge,rev_edge,compressed_edge,point_set;
    vector<int>order,vcomp,sort_order_vec;
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
    void build_rev_edge(){
        for(int nv = 0; nv < edge.size(); ++nv)
            for(auto v : edge[nv])
                rev_edge[v].push_back(nv);
    }
    void popsort(){
        for(int v = 0; v < edge.size(); ++v)
            if(not visit[v]) dfs(v);
    }
    void compress_vertex(){
        for(auto itr = order.rbegin(); itr != order.rend();++itr ){
            auto v = *itr;
            if(vcomp[v] == -1){
                dfs_compress(v); compress_size++;
            }
        }
    }
    void construct_strcomp(){
        compress_vertex();
        //create compressed graph
        compressed_edge = vector<vector<T>>(compress_size);
        for(int frm = 0; frm < edge.size(); ++frm)
            for(auto to : edge[frm]){
                if(vcomp[frm] == vcomp[to])continue;
                compressed_edge[vcomp[frm]].push_back(vcomp[to]);
            }
    }
    void construct_point_set(){
        point_set = vector<vector<int>>(compress_size);
        for(int v = 0; v < vcomp.size(); ++v){
            point_set[vcomp[v]].push_back(v);
        }
    }
public:
    StronglyConnectedComponents(vector<vector<T>>&e)
    :v_size((int)e.size()),edge(e),order{},rev_edge(e.size()){};
    int operator [](int v){
        return vcomp[v];
    }
    void build(){
        build_rev_edge();
        visit = vector<bool>(v_size,false);
        popsort();
        vcomp = vector<int>(v_size,-1);
        construct_strcomp();
        construct_point_set();
    }
    bool isSamePointSet(int v, int u){return vcomp[v] == vcomp[u];}
    // scc_size return the size of compressed vertexs.
    int scc_size(){return compress_size;}
    
    vector<vector<int>> get_point_set(){
        return point_set;
    }
};
signed main(){
}

