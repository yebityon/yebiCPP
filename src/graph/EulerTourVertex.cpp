#include<bits/stdc++.h>


//not verifyed yet....
template<typename T>
class EulerTourVertex{
    std::vector<T>ls,rs;
    std::vector<std::vector<T>>&tree;
    int v_size,root = 0;
    int& idx;
    void visitor(int parent,int v){
        ls[v] = idx++;
        for(auto u : tree[v]){
            if(u not_eq parent)
                visitor(v,u);
        }
        rs[v] = idx;
    }
    
public:
    
    EulerTourVertex(std::vector<std::vector<T>>_tree,int root = 0)
    : v_size(_tree.size()),tree(_tree){};
    void build(){
        rs = std::vector<int>(v_size,-1);
        ls = std::vector<int>(v_size,-1);
        visitor(-1,root);
    }
    void index(int v) {return ls[v];};
    
    struct F{
        auto operator ()(int lv,int rv){
            return lv + rv;
        };
    };
    void exec(int v, F f){
        f(ls[v],rs[v]);
    };
};
signed main(){
}

