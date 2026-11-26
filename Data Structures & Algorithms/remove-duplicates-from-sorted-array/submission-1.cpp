class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0,i=0;
        while(i<nums.size())
        {
            if(i<nums.size()-1 && nums[i]!=nums[i+1])
            {
                nums[k]=nums[i];
                k++;
                i++;
            }
            else
            {
                int a=nums[i];
                nums[k]=nums[i];
                k++;
                while(i<nums.size() && a==nums[i])
                i++;
            }
        }
        return k;
    }
};