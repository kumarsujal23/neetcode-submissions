class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            
            int target=-1*nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if((nums[j]+nums[k])==target)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while((j<nums.size()) && (nums[j]==nums[j-1]))
                    j++;
                    while((k>=0) && (nums[k]==nums[k+1]))
                    k--;
                }
                else if((nums[j]+nums[k])>target)
                k--;
                else
                j++;
            }
            while(((i+1)<nums.size()) && (nums[i]==nums[i+1]))
            i++;

        }
        return ans;
        
    }
};
