class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot=-1;
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(nums[m]>nums[nums.size()-1])
            l=m+1;
            else
            r=m-1;
        }
        pivot=l;
        if(nums[0]==target)
        return 0;
        else if(nums[0]<target)
        {
            l=0,r=pivot-1;
        }
        else 
        {
            r=nums.size()-1;
            l=pivot;
        }
        if(nums[0]<nums[nums.size()-1])
        {
            l=0;
            r=nums.size()-1;
        }
        while(l<=r)
        {
            int m=(l+r)/2;
            if(nums[m]==target)
            return m;
            else if(nums[m]>target)
            r=m-1;
            else
            l=m+1;
        }
        return -1;


    }
};
