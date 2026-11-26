class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> indeg(n+1);
        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indeg[u]++;
            indeg[v]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]==1)
            q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            indeg[node]--;
            for(auto neigh:adj[node])
            {
                indeg[neigh]--;
                if(indeg[neigh]==1)
                q.push(neigh);
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            int u=edges[i][0],v=edges[i][1];
            if(indeg[u]>0 && indeg[v]>0)
            return {u,v};
        }
    }
};
