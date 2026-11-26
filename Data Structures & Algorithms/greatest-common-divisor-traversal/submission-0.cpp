class Solution {
public:
    int maxi;
    vector<int> spf;
    void seive()
    {
        spf.resize(maxi+1,0);
        for(int i=2;i<=maxi;i++)
        {
            if(spf[i]==0)
            {
                spf[i]=i;
                for(int p=2*i;p<=maxi;p+=i)
                {
                    if(spf[p]==0)
                    spf[p]=i;
                }

            }
        }
    }
    vector<int> getprimefactor(int x)
    {
        unordered_map<int,int> mp;
        vector<int> res;
        while(x!=1)
        {
            if(mp.find(spf[x])==mp.end())
            {
                res.push_back(spf[x]);
                mp[spf[x]]++;
            }
            x=x/spf[x];
        }
        return res;
    }
    void dfs(int node,vector<int> &vis,vector<vector<int>> &adj,int &c)
    {
        vis[node]=1;
        c=c+1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            dfs(it,vis,adj,c);
        }
        return ;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        if(mini==1)
        return false;
        seive();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[i]=getprimefactor(nums[i]);
        }
        unordered_map<int,vector<int>> reversemp;
        for(auto it:mp)
        {
            for(int i=0;i<it.second.size();i++)
            {
                reversemp[it.second[i]].push_back(it.first);
            }
        }
        vector<vector<int>> adj(nums.size());
        for(auto it:reversemp)
        {
            for(int i=0;i<it.second.size();i++)
            {
                if(i>0)
                {
                    int u=it.second[i];
                    int v=it.second[i-1];
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        vector<int> vis(nums.size());
        int cnt=0;
        dfs(0,vis,adj,cnt);
        if(cnt==nums.size())
        return true;
        else
        return false;

    }
};