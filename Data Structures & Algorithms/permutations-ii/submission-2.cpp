class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &ans,int mask,vector<int> &nums)
    {
        if(ans.size()==nums.size())
        {
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mask&(1<<i))
            continue;
            if(i>0 && nums[i-1]==nums[i] && !(mask&(1<<(i-1))))
            continue;
            ans.push_back(nums[i]);
            solve(ans,mask|(1<<i),nums);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        solve(ans,0,nums);
        return res;
    }
};