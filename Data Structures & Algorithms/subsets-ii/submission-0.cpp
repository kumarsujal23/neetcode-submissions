class Solution {
public:
    vector<vector<int>> res;
    void solve(int i,vector<int> ans,vector<int>& nums)
    {
        if(i==nums.size())
        {
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        solve(i+1,ans,nums);
        ans.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1])
        i++;
        solve(i+1,ans,nums);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,{},nums);
        return res;
    }
};
