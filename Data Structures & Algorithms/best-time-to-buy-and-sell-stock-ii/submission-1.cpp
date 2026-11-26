class Solution {
public:
    // int solve(int i,int buy,vector<int>& prices,vector<vector<int>> &dp)
    // {
    //     if(i==prices.size())
    //     return 0;
    //     if(dp[i][buy]!=-1)
    //     return dp[i][buy];
    //     int ignore=solve(i+1,buy,prices,dp);
    //     int buying=0;
    //     if(buy)
    //     buying=-prices[i]+solve(i+1,0,prices,dp);
    //     int selling=0;
    //     if(!buy)
    //     selling=prices[i]+solve(i+1,1,prices,dp);
    //     return dp[i][buy]=max(ignore,max(buying,selling));

    // }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        // return solve(0,1,prices,dp);
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                int ignore=dp[i+1][buy];
                int buying=0;
                if(buy)
                buying=-prices[i]+dp[i+1][0];
                int selling=0;
                if(!buy)
                selling=prices[i]+dp[i+1][1];
                dp[i][buy]=max(ignore,max(buying,selling));
            }
        }
        return dp[0][1];
    }
};