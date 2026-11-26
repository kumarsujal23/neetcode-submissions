class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp)
    {
        if(j==t.size())
        return 1;
        if(i>=s.size() || j>=t.size())
        return 0;
        int res=0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==t[j])
        {
            res+=solve(i+1,j+1,s,t,dp)+solve(i+1,j,s,t,dp);
        }
        else
        res+=solve(i+1,j,s,t,dp);
        return dp[i][j]=res;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return solve(0,0,s,t,dp);
    }
};
