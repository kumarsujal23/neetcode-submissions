class Solution {
public:
    void dfs(string s,vector<string> &ans,unordered_map<string,vector<string>> &adj)
    {
        while(!adj[s].empty())
        {
            string v=adj[s].back();
            adj[s].pop_back();
            dfs(v,ans,adj);
        }
        ans.push_back(s);

    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(auto it:tickets)
        {
            adj[it[0]].push_back(it[1]);
        }
        for(auto &it:adj)
        {
            sort(it.second.rbegin(),it.second.rend());
        }
        vector<string> ans;
        dfs("JFK",ans,adj);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
