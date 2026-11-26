class Dsu{
    public:
        vector<int> parent;
        vector<int> rank;
        Dsu(int n){
            parent.resize(n);
            rank.resize(n,1);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
        }
        int findparent(int node)
        {
            if(parent[node]==node)
            return node;
            return parent[node]=findparent(parent[node]);
        }
        void unionset(int u,int v)
        {
            u=findparent(u);
            v=findparent(v);
            if(rank[u]<=rank[v])
            {
                parent[u]=v;
                rank[v]+=rank[u];
            }
            else
            {
                parent[v]=u;
                rank[u]+=rank[v];
            }
        }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edgelist(edges.size(),vector<int>(4));
        for(int i=0;i<edges.size();i++)
        {
            edgelist[i]={edges[i][2],edges[i][0],edges[i][1],i};
        }
        sort(edgelist.begin(),edgelist.end());
        vector<vector<int>> res(2);
        int miniwt=0;
        Dsu dsu1=Dsu(n);
        for(auto it:edgelist)
        {
            int u=dsu1.findparent(it[1]);
            int v=dsu1.findparent(it[2]);
            if(u!=v)
            {
                miniwt+=it[0];
                dsu1.unionset(u,v);
            }
        }
        for(auto edge:edgelist)
        {
            int wt=0;
            Dsu dsu2=Dsu(n);
             for(auto it:edgelist)
            {   
                if(it==edge)
                continue;
                int u=dsu2.findparent(it[1]);
                int v=dsu2.findparent(it[2]);
                if(u!=v)
                {
                wt+=it[0];
                dsu2.unionset(u,v);
                }
            
            }
            int maxi=*max_element(dsu2.rank.begin(),dsu2.rank.end());
            if(wt>miniwt || maxi!=n)
            {
                res[0].push_back(edge[3]);
                continue;
            }
            int wtnew=edge[0];
            Dsu dsu3=Dsu(n);
            dsu3.unionset(edge[1],edge[2]);
             for(auto it:edgelist)
            {   
                if(it==edge)
                continue;
                int u=dsu3.findparent(it[1]);
                int v=dsu3.findparent(it[2]);
                if(u!=v)
                {
                wtnew+=it[0];
                dsu3.unionset(u,v);
                }
            
            }
            if(wtnew==miniwt)
            res[1].push_back(edge[3]);

        }
        return res;
    }
};
