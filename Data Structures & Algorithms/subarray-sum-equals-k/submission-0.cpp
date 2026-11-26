class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int currsum=0,res=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            currsum+=nums[i];
            int diff=currsum-k;
            if(mp.find(diff)!=mp.end())
            res+=mp[diff];
            mp[currsum]++;
        }
        return res;
    }
};