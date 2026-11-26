class Solution {
public:
    int solve(int i,int sum,vector<int>& nums, int &target,vector<vector<int>> &dp,int offset)
    {
        if(i==(nums.size()))
        return sum==target;
        if(dp[i][sum+offset]!=-1)
        return dp[i][sum+offset];
     return dp[i][sum+offset] =solve(i+1,-1*nums[i]+sum,nums,target,dp,offset)+solve(i+1,nums[i]+sum,nums,target,dp,offset);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it:nums)
        sum+=it;
        vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1,-1));
        return solve(0,0,nums,target,dp,sum);
    }
};
