class Solution {
public:
    bool solve(int i,int currsum,vector<int>& nums,int mask,int k,int &target)
    {
        if(k==0)
        return true;
        if(currsum==target)
        {
            return solve(0,0,nums,mask,k-1,target);
        }
        if(i>=nums.size())
        return false;
        for(int j=i;j<nums.size();j++)
        {
            if((mask & (1<<j))|| currsum+nums[j]>target)
            continue;
            if(solve(j+1,currsum+nums[j],nums,mask|(1<<j),k,target))
            return true;
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
        sort(nums.rbegin(),nums.rend());
        // vector<int> vis(nums.size(),0);
        return solve(0,0,nums,0,k,target);
    }
};