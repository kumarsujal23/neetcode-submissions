class DSU{
    public:
        int n;
        vector<int> parent;
        vector<int> rank;
        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n);
            for(int i=0;i<n;i++)
            parent[i]=i;
        }
        int findparent(int node)
        {
            if(node==parent[node])
            return node;
            return parent[node]=findparent(parent[node]);
        }
        void unionset(int i,int j)
        {
            i=findparent(i);
            j=findparent(j);
            if(rank[i]>rank[j])
            parent[j]=i;
            else if(rank[j]>rank[i])
            parent[i]=j;
            else
            {
                rank[i]++;
                parent[j]=i;
            }
        }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int cost=0;
        DSU dsu(points.size());
        for(int i=0;i<edges.size();i++)
        {
            int c=edges[i][0];
            int u=edges[i][1];
            int v=edges[i][2];
            u=dsu.findparent(u);
            v=dsu.findparent(v);
            if(u!=v){
                cost+=c;
                dsu.unionset(u,v);
            }
        }
        return cost;
    }
};
