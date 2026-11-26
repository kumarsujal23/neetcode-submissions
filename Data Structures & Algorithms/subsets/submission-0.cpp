class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int limit=1<<nums.size();
        res.push_back({});
        for(int mask=1;mask<limit;mask++)
        {
            vector<int> ans;
            for(int i=0;i<nums.size();i++)
            {
                if(mask & (1<<i))
                ans.push_back(nums[i]);
            }
            res.push_back(ans);
        }
        return res;
    }
};
