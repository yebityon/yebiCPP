#include<bits/stdc++.h>


//not verifyed yet....
template<typename T>
class EulerTourVertex{
    std::vector<T>ls,rs;
    std::vector<std::vector<T>>tree;
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
    : v_size(_tree.size()),tree(_tree),idx(root){};
    void build(){
        rs = std::vector<int>(v_size,-1);
        ls = std::vector<int>(v_size,-1);
				int zero = 0;
				idx = zero;
        visitor(-1,root);
    }
    auto  index(int v) {return ls[v];};
    
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
	while(true){
		int N; 
		std::cin >> N;
		std::vector<std::vector<int>>edge(N);
		for(int i = 0;i < N-1; ++i){
			int s,t; std::cin >> s >> t;
			--s,--t;
			edge[s].push_back(t);
			edge[t].push_back(s);
		}
		auto E = EulerTourVertex<int>(edge);
		E.build();
		for(int i = 0; i < N; ++i )
			std::cout << E.index(i) << " ";
		std::cout << std::endl;
		
	}
}

