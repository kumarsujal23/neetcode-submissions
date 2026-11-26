class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int i=0;
        for(i=0;i<=k && i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            return true;
            mp[nums[i]]++;
        }
        mp.erase(nums[0]);
        int l=1;
        while(i<n)
        {
            if(mp.find(nums[i])!=mp.end())
            return true;
            else
            {
                mp[nums[i]]++;
                i++;
                mp.erase(nums[l]);
                l++;
            }
        }
        return false;
    }
};