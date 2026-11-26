class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums,vector<int> &ans,int mask)
    {
        if(ans.size()==nums.size())
        {
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!(mask & (1<<i)))
            {
                ans.push_back(nums[i]);
                solve(nums,ans,mask|(1<<i));
                ans.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        solve(nums,ans,0);
        return res;
        
    }
};
