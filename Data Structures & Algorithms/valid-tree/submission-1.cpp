class Solution {
public:
    void dfs(int node,vector<int> &vis,map<int ,vector<int>> &adj )
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            dfs(it,vis,adj);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
            map<int ,vector<int>> adj;
            for(int i=0;i<edges.size();i++)
            {
                int u=edges[i][0];
                int v=edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            vector<int> parent(n);
            vector<int> vis(n);
            parent[0]=-1;
            queue<int> q;
            q.push(0);
            vis[0]=1;
            while(!q.empty())
            {
                int f=q.front();
                q.pop();
                for(auto neigh:adj[f])
                {
                    if(vis[neigh]==1 && parent[f]!=neigh)
                    return false;
                    else if(!vis[neigh])
                    {
                        q.push(neigh);
                        vis[neigh]=1;
                        parent[neigh]=f;
                    }

                }
            }
            vis={0};
            int c=0;
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    dfs(i,vis,adj);
                    c++;
                }
            }
    if(c>1)
    return false;
    else
    return true;
    }
};
