class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),l=n-1;
        if(n==1)
        return true;
        for(int i=n-2;i>=0;i--)
        {
            if(l-i<=nums[i])
            {
                l=i;
            }
        }
        if(!l)
        return true;
        else
        return false;
    }
};
