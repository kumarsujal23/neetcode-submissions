class Solution {
public:
    int solve(int i,string &s,vector<int> &dp,map<string,char> &mp)
    {
        if(i==s.size())
        return 1;
        if(s[i]==0)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans=0;
        if(mp.find(s.substr(i,1))!=mp.end())
        ans+=solve(i+1,s,dp,mp);
        if(i+1<s.size() && mp.find(s.substr(i,2))!=mp.end())
        ans+=solve(i+2,s,dp,mp);
        return dp[i]=ans;
        

    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        map<string,char> mp;
        for(char ch='A';ch<='Z';ch++)
        mp[to_string(ch-'A'+1)]=ch;
        int ans=solve(0,s,dp,mp);
        return ans;
    }
};
