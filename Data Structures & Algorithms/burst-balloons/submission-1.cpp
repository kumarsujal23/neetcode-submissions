class Solution {
public:
    int solve(int i,int j,vector<int>& nums,vector<vector<int>> &dp)
    {
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int maxi=0;
        for(int k=i;k<=j;k++)
        {
            maxi=max(maxi,nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp));
        }
        return dp[i][j]=maxi;

    }
    int maxCoins(vector<int>& nums) {
        vector<int> a(nums.size()+2,1);
        for(int i=0;i<nums.size();i++)
        a[i+1]=nums[i];
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(1,nums.size(),a,dp);
    }
};
