class Solution {
public:
    set<vector<int>> st;
    void solve(vector<int> &ans,int mask,vector<int> &nums)
    {
        if(ans.size()==nums.size())
        {
            st.insert(ans);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!(mask&(1<<i)))
            {
                ans.push_back(nums[i]);
                solve(ans,mask|(1<<i),nums);
                ans.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ans;
        solve(ans,0,nums);
        vector<vector<int>> res;
        for(auto it:st)
        {
            res.push_back(it);
        }
        return res;
    }
};