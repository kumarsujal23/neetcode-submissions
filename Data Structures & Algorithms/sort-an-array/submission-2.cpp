class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> freq(100001,0);
        int offset=50000;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]+offset]++;
        }
        int l=0;
        for(int i=0;i<freq.size();i++)
        {
            while(freq[i]>0)
            {
                nums[l]=i-offset;
                l++;
                freq[i]--;
                if(l>=nums.size())
            break;
            }
            if(l>=nums.size())
            break;
        }
        return nums;
    }
};