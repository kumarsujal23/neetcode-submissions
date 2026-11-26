class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i-1]==nums[i])
            continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                continue;
                int left=j+1,right=n-1;
                while(left<right)
                {
                    long long sum=(long long )nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target)
                    {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left<right && nums[left-1]==nums[left])
                        left++;
                        while(left<right && nums[right+1]==nums[right])
                        right--;
                    }
                    else if(sum>target)
                    {
                        right--;
                        while(left<right && nums[right+1]==nums[right])
                        right--;
                    }
                    else
                    {
                        left++;
                        while(left<right && nums[left-1]==nums[left])
                        left++;
                    }

                }
            }
        }
        return res;
    }
};