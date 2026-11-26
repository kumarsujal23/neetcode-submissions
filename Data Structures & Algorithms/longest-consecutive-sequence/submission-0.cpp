class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int ans=0;
        for(int num:s)
        {
            if(s.find(num-1)==s.end())
            {
                int l=1;
                while(l<nums.size() && s.find(num+l)!=s.end())
                l++;
                ans=max(ans,l);
            }
        }
        return ans;
        
    }
};
