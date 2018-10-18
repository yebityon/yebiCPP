#include<bits/stdc++.h>
using namespace std;
#define MAX 26
#define OFFSET 'A'
#define all(in) in.begin(),in.end()
struct Node{
    int nxt[MAX+1]; // 次のalphabeteのノード番号
    int exist; // 子ども以下に存在する文字列の数の合計
    vector<int> accept; // その文字列id
    Node() : exist(0){memset(nxt, -1, sizeof(nxt));}
};
struct Trie{
    vector<Node>nodes;
    int root;
    Trie() : root(0){nodes.push_back(Node());}
    
    void update_direct(int node,int id){
        nodes[node].accept.push_back(id);
    }
    void update_child(int node,int child,int id){
        ++nodes[node].exist;
    }
    void add(const string &str,int str_index,int node_index,int id){
        if(str_index == str.size())
            update_direct(node_index, id);
        else{
            const int c = str[str_index] - OFFSET;
            if(nodes[node_index].nxt[c] == -1) {
                nodes[node_index].nxt[c] = (int) nodes.size();
                nodes.push_back(Node());
            }
            add(str, str_index + 1, nodes[node_index].nxt[c], id);
            update_child(node_index, nodes[node_index].nxt[c], id);
        }
    }
    void add(const string &str,int id){add(str, 0, 0, id);}
    void add(const string &str){add(str, nodes[0].exist);}
    int size(){return (nodes[0].exist);}
    int nodesize(){return ((int) nodes.size());}
};
struct Aho_Corasick : Trie{
    static const int FAIL = MAX;
    vector<int> correct;
    Aho_Corasick() : Trie() {}
    
    void build(){
        correct.resize(nodes.size());
        for(int i = 0; i < nodes.size();i++)
            correct[i]=(int)nodes[i].accept.size();
        
        queue<int> que;
        for(int i = 0; i < MAX; i++){
            if(~nodes[0].nxt[i]) {
                nodes[nodes[0].nxt[i]].nxt[FAIL] = 0;
                que.emplace(nodes[0].nxt[i]);
            }else nodes[0].nxt[i] = 0;
        }
        while(!que.empty()) {
            Node &now = nodes[que.front()];
            correct[que.front()] += correct[now.nxt[FAIL]];
            que.pop();
            for(int i = 0;i < MAX; i++){
                if(now.nxt[i] == -1) continue;
                int fail = now.nxt[FAIL];
                while(nodes[fail].nxt[i] == -1) {
                    fail = nodes[fail].nxt[FAIL];
                }
                nodes[now.nxt[i]].nxt[FAIL] = nodes[fail].nxt[i];
                
                auto &u = nodes[now.nxt[i]].accept;
                auto &v = nodes[nodes[fail].nxt[i]].accept;
                vector<int> accept;
                set_union(all(u),all(v),back_inserter(accept));
                u=accept;
                que.emplace(now.nxt[i]);
            }
        }
    }
    int match(const string &str,vector<int> &result,int now=0){
        result.assign(size(),0);
        int count=0;
        for(auto &c:str) {
            while(nodes[now].nxt[c-OFFSET]==-1)now=nodes[now].nxt[FAIL];
            now = nodes[now].nxt[c-OFFSET];
            count += correct[now];
            for(auto &v:nodes[now].accept)result[v]++;
        }
        return count;
    }
    int next(int now,char c){
        while(nodes[now].nxt[c-OFFSET]==-1)now=nodes[now].nxt[FAIL];
        return nodes[now].nxt[c-OFFSET];
    }
};

