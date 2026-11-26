class Solution {
public:
    double dfs(string src,string target,unordered_map<string,vector<pair<string,double>>> &adj,unordered_map<string,int> &vis)
    {
        if(adj.find(src)==adj.end() || adj.find(target)==adj.end())
        return -1.0;
        if(src==target)
        return 1.0;
        vis[src]=1;
        for(auto it:adj[src])
        {
            string next=it.first;
            double weight=it.second;
            if(vis.find(next)==vis.end())
            {
                double res=dfs(next,target,adj,vis);
                if(res!=-1)
                return weight*res;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<values.size();i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            adj[u].push_back({v,values[i]});
            adj[v].push_back({u,1/values[i]});
        }
        vector<double> res(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            string u=queries[i][0];
            string v=queries[i][1];
            unordered_map<string,int> vis;
            res[i]=dfs(u,v,adj,vis);
        }
        return res;
    }
};