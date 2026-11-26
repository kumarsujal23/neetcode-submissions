class Solution {
public:
    bool check(int sum,vector<int>& nums, int k)
    {
        int c=1,s=0;
        for(auto it:nums)
        {
            if(s+it<=sum)
            s+=it;
            else
            {
                c++;
                s=it;
            }
            if(c>k)
            return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=0;
        for(auto it:nums)
        r+=it;
        int res=r;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(check(m,nums,k))
            {
                res=m;
                r=m-1;
            }
            else
            l=m+1;
        }
        return res;
    }
};