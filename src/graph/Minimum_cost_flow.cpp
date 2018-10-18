struct Edge{
    int to,cap,cost,rev;
};
class MCF{    //Minimum Cost Flow
public:
    using pii = pair<int, int>;
    using ve =  vector<Edge>;
    using vve = vector<ve>;
    int n;
    vve G;
    vector<int> h,dist,prev,pree;
    MCF(int size){
        n=size;
        G=vve(n);
        h=dist=prev=pree=vector<int>(n);
    }
    void add_edge(int s,int t,int ca,int co){
        Edge e={t,ca,co,(int)G[t].size()};
        G[s].push_back(e);
        Edge ee={s,0,-co,(int)G[s].size()-1};
        G[t].push_back(ee);
    }
    int mcf(int s,int t,int f){
        int out=0;
        h=vector<int>(n);
        while(f>0){
            priority_queue<pii,vector<pii> >q;
            dist=vector<int>(n,INF);
            dist[s]=0;
            q.push(pii(0,s));
            while(!q.empty()){
                pii p=q.top();q.pop();
                int v=p.second;
                if(dist[v]<-p.first)continue;
                for(int i=0;i<G[t].size();i++){
                    Edge &e=G[v][i];
                    if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                        dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                        prev[e.to]=v;
                        pree[e.to]=i;
                        q.push(pii(-dist[e.to],e.to));
                    }
                }
            }
            if(dist[t]==INF)return -1;
            for(int i=0;i<n;i++)h[i]+=dist[i];
            int d=f;
            for(int v=t;v!=s;v=prev[v])d=min(d,G[prev[v]][pree[v]].cap);
            f-=d;
            out+=d*h[t];
            for(int v=t;v!=s;v=prev[v]){
                Edge &e=G[prev[v]][pree[v]];
                e.cap-=d;
                G[v][e.rev].cap+=d;
            }
        }
        return out;
    }
};
