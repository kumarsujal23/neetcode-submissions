class Solution {
public:
    int solve(int i,int j,vector<int> &a,vector<vector<int>> &dp)
    {
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int res=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            res=max(res,a[i-1]*a[k]*a[j+1]+solve(i,k-1,a,dp)+solve(k+1,j,a,dp));
        }
        return dp[i][j]=res;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> a(nums.size()+2,1);
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        for(int i=0;i<nums.size();i++)
        {
            a[i+1]=nums[i];
        }
        return solve(1,nums.size(),a,dp);
    }
};
