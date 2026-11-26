class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod=1,minprod=1,best=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int a=minprod;
            int b=maxprod;
            minprod=min(nums[i],min(a*nums[i],b*nums[i]));
            maxprod=max(nums[i],max(a*nums[i],b*nums[i]));
            best=max(best,max(maxprod,minprod));
        }
        return best;
    }
};
