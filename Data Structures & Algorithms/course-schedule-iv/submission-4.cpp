class Solution {
public:
    bool dfs(int node,int target,vector<vector<int>> &adj,vector<vector<int>> &cache)
    {
        if(cache[node][target]!=0)
        return cache[node][target]==1;
        if(node==target)
        {
          cache[node][target]=1;  
          return true;
        }
        for(auto it:adj[node])
        {
            if(dfs(it,target,adj,cache))
            {
                cache[node][target]=1;
                return true;
            }
        }
        cache[node][target]=2;
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<vector<int>> cache(numCourses,vector<int>(numCourses,0));
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> ans(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            int u=queries[i][0];
            int v=queries[i][1];
            ans[i]=dfs(u,v,adj,cache);
        }
        return ans;
    }
};