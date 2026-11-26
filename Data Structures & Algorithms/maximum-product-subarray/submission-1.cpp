class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minp=1,maxp=1,best=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int a=minp;
            int b=maxp;
            minp=min(nums[i],min(a*nums[i],b*nums[i]));
            maxp=max(nums[i],max(a*nums[i],b*nums[i]));
            best=max(best,max(maxp,minp));
        }
        return best;
    }
};
