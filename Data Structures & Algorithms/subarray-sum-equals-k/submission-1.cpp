class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int curr=0,res=0;
        for(auto num:nums)
        {
            curr+=num;
            int diff=curr-k;
            if(mp.find(diff)!=mp.end())
            res+=mp[diff];
            mp[curr]++;
        }
        return res;
    }
};