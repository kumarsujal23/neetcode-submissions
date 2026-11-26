class Solution {
public:
    void dfs(string node,unordered_map<string,vector<string>> &adj,vector<string> &res)
    {
        while(!adj[node].empty())
        {
            string nextnode=adj[node].back();
            adj[node].pop_back();
            dfs(nextnode,adj,res);
        }
        res.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(auto it:tickets)
        {
            adj[it[0]].push_back(it[1]);
        }
        for(auto &[key,val]:adj)
        {
            sort(val.rbegin(),val.rend());
        }
        vector<string> res;
        dfs("JFK",adj,res);
        reverse(res.begin(),res.end());
        return res;
    }
};
