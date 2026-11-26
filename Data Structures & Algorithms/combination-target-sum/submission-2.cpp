class Solution {
public:
    vector<vector<int>> res;
    void solve(int i,vector<int> curr,int sum,vector<int> &nums,int &target)
    {
        if(sum==target)
        {
            res.push_back(curr);
            return;
        }
        if(i>=nums.size() || sum>target)
        return;
        for(int j=i;j<nums.size();j++)
        {
            if(sum+nums[j]>target)
            return;
            curr.push_back(nums[j]);
            solve(j,curr,sum+nums[j],nums,target);
            curr.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(0,curr,0,nums,target);
        return res;
    }
};
