class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<vector<int>> v(nums.size()+1);
        unordered_map<int,int> mp;
    for(auto x:nums)
    {
        mp[x]++;
    }
    for(auto it:mp)
    {
        v[it.second].push_back(it.first);
    }
    vector<int> res;
    for(int i=nums.size();i>=0;i--)
    {
        if(v[i].size()==0)
        continue;
        for(auto x:v[i])
        {
            res.push_back(x);
            k--;
            if(k==0)
            break;
        }
        if(k==0)
        break;
    }
    return res;
    }
};
