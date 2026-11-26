class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;
        vector<int> ans;
        vector<pair<int,int>> p;
        for(auto it:mp)
        p.push_back({it.second,it.first});
        sort(p.rbegin(),p.rend());
        for(int i=0;i<k;i++)
        ans.push_back(p[i].second);
        return ans;
    }
};
