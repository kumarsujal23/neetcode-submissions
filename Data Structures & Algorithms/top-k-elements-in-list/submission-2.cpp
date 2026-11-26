class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<pair<int,int>> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            ans.push_back({it.second,it.first});
            
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        vector<int> res;
        for(int i=0;i<k;i++)
        {
            res.push_back(ans[i].second);
        }
        return res;
    }
};
