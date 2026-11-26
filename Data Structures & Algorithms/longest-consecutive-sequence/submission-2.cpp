class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        sort(nums.begin(),nums.end());
        int ans=1,a=1;
        int i=1;
        while(i<nums.size())
        {
            if((nums[i]-nums[i-1])==0)
            i++;
            else if((nums[i]-nums[i-1])==1)
            {
                a++;
                i++;
            }
            else
            {
                ans=max(ans,a);
                a=1;
                i++;
            }

        }
        ans=max(ans,a);
        return ans;
        
    }
};
