class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> l(n,1);
        vector<int> r(n,1);
        int p=1;
        for(int i=0;i<n;i++)
        {
            if(!i)
            continue;
            p=p*nums[i-1];
            l[i]=p;
        }
        p=1;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            continue;
            p=p*nums[i+1];
            r[i]=p;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(l[i]*r[i]);
        }
    return ans;
    }
};
