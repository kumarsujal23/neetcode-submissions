class Solution {
public:
    bool solve(int i,int currsum,vector<int>& nums,vector<int>& vis,int k,int &target)
    {
        if(k==0)
        return true;
        // if(i>=nums.size())
        // return false;
        if(currsum==target)
        {
            return solve(0,0,nums,vis,k-1,target);
        }
        for(int j=i;j<nums.size();j++)
        {
            if(vis[j] || currsum+nums[j]>target)
            continue;
            vis[j]=1;
            if(solve(j+1,currsum+nums[j],nums,vis,k,target))
            return true;
            vis[j]=0;
        }
        return false;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto num:nums)
        sum+=num;
        if(sum%k!=0)
        return false;
        int target=sum/k;
        // sort(nums.rbegin(),nums.rend());
        vector<int> vis(nums.size(),0);
        return solve(0,0,nums,vis,k,target);
    }
};