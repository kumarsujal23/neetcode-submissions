class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        bool ans=false;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                ans=true;
                break;
            }
            else
            {
                mp[nums[i]]++;

            }
        }
        return ans;
    }
};