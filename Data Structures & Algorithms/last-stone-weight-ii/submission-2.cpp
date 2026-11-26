class Solution {
public:
    int target;
    int total;
    int solve(int i,int sum,vector<int> &stones,vector<vector<int>> &dp)
    {
        if(i==stones.size())
        {
            return abs(total-sum-sum);
        }
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        if(sum+stones[i]>target)
        {
            return abs(total-sum-sum);
        }
        int res1=solve(i+1,sum+stones[i],stones,dp);
        int res2=solve(i+1,sum,stones,dp);
        return dp[i][sum]=min(res1,res2);
    }
    int lastStoneWeightII(vector<int>& stones) {
        target=0;
        total=0;
        for(auto it:stones)
        total+=it;
        target=total/2;
        vector<vector<int>> dp(stones.size(),vector<int>(target+1,-1));
        return solve(0,0,stones,dp);
    }
};