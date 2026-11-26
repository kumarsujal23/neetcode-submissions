class Solution {
public:
    // int solve(int i,int buy,vector<int> &p,vector<vector<int>> &dp)
    // {
    //     if(i>=p.size())
    //     return 0;
    //     if(dp[i][buy]!=-1)
    //     return dp[i][buy];
    //     if(buy)
    //     return dp[i][buy]=max(-1*p[i]+solve(i+1,0,p,dp),solve(i+1,1,p,dp));
    //     else
    //     return dp[i][buy]=max(p[i]+solve(i+2,1,p,dp),solve(i+1,0,p,dp));
    // }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // return solve(0,1,prices,dp);
        int n=prices.size();
         vector<vector<int>> dp(n,vector<int>(2,0));
         for(int i=n-1;i>=0;i--)
         {
            for(int buy=1;buy>=0;buy--)
            {
                if(buy)
                {
                    int b=-1*prices[i]+((i+1<n)?dp[i+1][0]:0);
                    int notb=((i+1<n)?dp[i+1][1]:0);
                    dp[i][buy]=max(b,notb);
                }
                else 
                {
                    int s=prices[i]+((i+2<n)?dp[i+2][1]:0);
                    int nots=((i+1<n)?dp[i+1][0]:0);
                    dp[i][buy]=max(s,nots);
                }
            }
         }
         return dp[0][1];
    }
};
