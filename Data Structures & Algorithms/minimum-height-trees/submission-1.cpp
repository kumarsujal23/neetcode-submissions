class Solution {
public:
    int dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;
        int h=0;
        for(auto it:adj[node])
        {
            if(!vis[it])
            h=max(h,1+dfs(it,adj,vis));
        }
        return h;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<pair<int,int>> h(n);
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n);
            int ans=dfs(i,adj,vis);
            h[i]={ans,i};
        }
        sort(h.begin(),h.end());
        int a=h[0].first;
        vector<int> res;
        for(int i=0;i<h.size();i++)
        {
            if(h[i].first==a)
            res.push_back(h[i].second);
            else
            break;
        }
        return res;

    }
};