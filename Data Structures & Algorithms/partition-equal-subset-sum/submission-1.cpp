class Solution {
public:
    int total=0;
    bool solve(vector<int>& nums,int i,int sum1,vector<vector<int>> &dp)
    {
        if(i==nums.size())
        {
            if(sum1==(total-sum1))
            return true;
            else 
            return false;
        }
        if(dp[i][sum1]!=-1)
        return dp[i][sum1];

        bool cond1=solve(nums,i+1,sum1+nums[i],dp);
        bool cond2=solve(nums,i+1,sum1,dp);
        return dp[i][sum1] =(cond1||cond2);
    }
    bool canPartition(vector<int>& nums) {
        for(auto it:nums)
        total+=it;
        if(total%2!=0)
        return false;
        vector<vector<int>> dp(nums.size(),vector<int>(total+1,-1));
        return solve(nums,0,0,dp);
    }
};
