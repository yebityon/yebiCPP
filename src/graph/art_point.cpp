#include<bits/stdc++.h>
using namespace std;
class art_point {
    
private:
    void dfs(int crt,int prev){
        prenum[crt] = lowest[crt] = timer;
        timer++;
        visited[crt] = true;
        int next;
        for(int i = 0; i < edge[crt].size();i++){
            next = edge[crt][i];
            if(!visited[next]){
                parent[next ]= crt;
                dfs(next,crt);
                lowest[crt] = min(lowest[crt],lowest[next]);
            }else if(next != prev){
                lowest[crt] = min(lowest[crt],prenum[next]);
            }
        }
    }
    void build(){
        dfs(0,-1);
        int np = 0;
        for(int i = 1;i < N;i++){
            int p = parent[i];
            if(p == 0)np++;
            else if(prenum[p] <= lowest[i])Mp[p]++;
            if(np > 1) Mp[0]++;
        }
    }
public:
    vector<bool>visited;
    vector<int>prenum,parent,lowest;
    int timer,N;
    map<int,int>Mp;
    vector<vector<int>>edge;
    
    art_point(int v_size,vector<vector<int>>&Edge) : prenum(v_size,-1),parent(v_size,-1),lowest(v_size,-1),timer(1),visited(v_size,false),N(v_size){
        edge = Edge;
        build();
    }
    
    void show_art_point(){
        for(auto& itr : Mp) cout<< itr.first << endl;
    }
    map<int,int>&get(){ return Mp;}
};

