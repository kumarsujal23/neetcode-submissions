class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> bucket(3);
        for(int i=0;i<nums.size();i++)
        {
            bucket[nums[i]]++;
        }
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(bucket[k]!=0)
            {
                nums[i]=k;
                bucket[k]--;
            }
            else
            {
                k++;
                i--;
            }
        }
    }
};