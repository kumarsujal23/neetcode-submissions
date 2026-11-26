class Dsu{
    public:
        vector<int> parent;
        vector<int> rank;
        Dsu(int n){
            parent.resize(n);
            rank.resize(n,1);
            for(int i=0;i<n;i++)
            parent[i]=i;
        }
        int find(int node)
        {
            if(parent[node]==node)
            return node;
            return parent[node]=find(parent[node]);
        }
        void unionset(int u,int v)
        {
            u=find(u);
            v=find(v);
            if(rank[u]>=rank[v])
            {
                parent[v]=u;
                rank[u]+=rank[v];
            }
            else
            {
                parent[u]=v;
                rank[v]+=rank[u];
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
        int minwt=0;
        Dsu dsu1(n);
        for(auto it:edgelist)
        {
            int u=dsu1.find(it[1]);
            int v=dsu1.find(it[2]);
            if(u!=v)
            {
                minwt+=it[0];
                dsu1.unionset(u,v);
            }
        }
        vector<vector<int>> res(2);
        for(auto edge:edgelist)
        {
            Dsu dsu2(n);
            int wt=0;
            for(auto it:edgelist)
            {
                if(it==edge)
                continue;
                int u=dsu2.find(it[1]);
                int v=dsu2.find(it[2]);
                if(u!=v)
                {
                    wt+=it[0];
                    dsu2.unionset(u,v);
                }
            }
            int maxi=*max_element(dsu2.rank.begin(),dsu2.rank.end());
            if(wt>minwt || maxi!=n)
            {
                res[0].push_back(edge[3]);
                continue;
            }
            Dsu dsu3(n);
            wt=edge[0];
            dsu3.unionset(edge[1],edge[2]);
            for(auto it:edgelist)
            {
                if(it==edge)
                continue;
                int u=dsu3.find(it[1]);
                int v=dsu3.find(it[2]);
                if(u!=v)
                {
                    wt+=it[0];
                    dsu3.unionset(u,v);
                }
            }
            if(wt==minwt)
            res[1].push_back(edge[3]);
        }
        return res;
    }
};