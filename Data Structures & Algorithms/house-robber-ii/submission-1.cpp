class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=nums[0];
        dp[1]=dp[0];
        for(int i=2;i<n-1;i++)
        {
            int take=dp[i-2]+nums[i];
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        int m=dp[n-2];
        dp={0};
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int take=(i-2>=0?dp[i-2]:0)+nums[i];
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        return max(dp[n-1],m);
    }
};
