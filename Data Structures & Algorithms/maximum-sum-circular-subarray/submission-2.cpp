class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //non Wrapping case, simple Kadane algo
        int n=nums.size();
        int maxi=nums[0],sum=nums[0];
        for(int i=1;i<n;i++)
        {
            sum=max(sum+nums[i],nums[i]);
            maxi=max(maxi,sum);
        }
        // wrapping case
        vector<int> rightmax(n);
        rightmax[n-1]=nums[n-1];
        int right=rightmax[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right+=nums[i];
            rightmax[i]=max(rightmax[i+1],right);
        }
        int currsum=0,best=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            currsum+=nums[i];
            best=max(best,currsum+rightmax[i+1]);
        }
        return max(best,maxi);
    }
};