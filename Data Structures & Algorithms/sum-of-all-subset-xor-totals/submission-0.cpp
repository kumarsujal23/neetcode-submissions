class Solution {
public:
    int res;
    void solve(int i,int x,vector<int>& nums)
    {
        if(i==nums.size())
        {
            res+=x;
            return;
        }
        solve(i+1,x^nums[i],nums);
        solve(i+1,x,nums);
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        res=0;
        solve(0,0,nums);
        return res;
    }
};