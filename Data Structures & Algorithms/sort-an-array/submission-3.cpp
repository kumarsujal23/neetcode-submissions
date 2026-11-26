class Solution {
public:
    void merge(int i,int j,int k,vector<int>& nums)
    {
        vector<int> v(k-i+1);
        int a=0;
        int l=i,m=j+1;
        while(l<j+1 && m<=k)
        {
            if(nums[l]<=nums[m])
            {
                v[a]=nums[l];
                l++;
                a++;
            }
            else
            {
                v[a]=nums[m];
                m++;
                a++;
            }
        }
        while(l<j+1)
        {
            v[a]=nums[l];
            a++;
            l++;
        }
        while(m<=k)
        {
            v[a]=nums[m];
            a++;
            m++;
        }
        for(int p=0;p<v.size();p++)
        {
            nums[i]=v[p];
            i++;
        }
        return;
    }
    void mergesort(int l,int r,vector<int>& nums)
    {
        if(l<r)
        {
            int m=(l+r)/2;
            mergesort(l,m,nums);
            mergesort(m+1,r,nums);
            merge(l,m,r,nums);
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(0,nums.size()-1,nums);
        return nums;
    }
};