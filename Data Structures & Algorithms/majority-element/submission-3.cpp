class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(),f=n/2;
        vector<int> bit(32);
        for(int i=0;i<32;i++)
        {
            for(auto num:nums)
            bit[i]+=((num>>i)&1);
        }
        int res=0;
        for(int i=0;i<32;i++)
        {
            if(bit[i]>f)
            res|=(1<<i);
        }
        return res;
    }
};