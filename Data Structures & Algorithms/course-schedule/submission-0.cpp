class Solution {
public:
    bool con=true;
    void dfscall(int node,vector<int> &vis,vector<int> &dfs,vector<vector<int>> &adj)
    {
        vis[node]=1;
        dfs[node]=1;
        for(auto it:adj[node])
        {
            if(dfs[it])
            {
                con=false;
                break;
            }
            else if(!vis[it])
            dfscall(it,vis,dfs,adj);
        }
        dfs[node]=0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int> vis(numCourses);
        vector<int> dfs(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                dfscall(i,vis,dfs,adj);
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                con=false;
                break;
            }
        }
        return con;
    }
};
