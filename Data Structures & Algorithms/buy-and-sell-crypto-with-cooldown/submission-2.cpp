class Solution {
public:
    int solve(int i,int buy,vector<int> &p,vector<vector<int>> &dp)
    {
        if(i>=p.size())
        return 0;
        if(dp[i][buy]!=-1)
        return dp[i][buy];
        if(buy)
        return dp[i][buy]=max(-1*p[i]+solve(i+1,0,p,dp),solve(i+1,1,p,dp));
        else
        return dp[i][buy]=max(p[i]+solve(i+2,1,p,dp),solve(i+1,0,p,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};
