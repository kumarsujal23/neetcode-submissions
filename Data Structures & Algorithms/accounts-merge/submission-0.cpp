class Solution {
public:
    vector<string> email;
    unordered_map<string,int> emailindx;
    vector<vector<int>> adj;
    unordered_map<int,int> emailacctid;
    unordered_map<int,vector<string>> emailgroup;
    vector<bool> vis;
    void dfs(int &node,int &acctid)
    {
        vis[node]=true;
        emailgroup[acctid].push_back(email[node]);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,acctid);
            }
        }
        return ;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int m=0;
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(emailindx.find(accounts[i][j])==emailindx.end())
                {
                    email.push_back(accounts[i][j]);
                    emailindx[accounts[i][j]]=m;
                    emailacctid[m]=i;
                    m++;
                }
            }
        }
        adj.resize(m);
        vis.resize(m,false);
        for(auto acct:accounts)
        {
            for(int j=2;j<acct.size();j++)
            {
                int ind1=emailindx[acct[j]];
                int ind2=emailindx[acct[j-1]];
                adj[ind1].push_back(ind2);
                adj[ind2].push_back(ind1);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[i])
            {
                int acctid=emailacctid[i];
                dfs(i,acctid);
            }
        }
        vector<vector<string>> res;
        for(auto it:emailgroup)
        {
            vector<string> v=it.second;
            string name=accounts[it.first][0];
            sort(v.begin(),v.end());
            vector<string> merged;
            merged.push_back(name);
            for(int i=0;i<v.size();i++)
            {
                merged.push_back(v[i]);
            }
            res.push_back(merged);
        }
        return res;
    }
};