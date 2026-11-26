class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        //making the first window deque
        for(int i=0;i<k;i++)
        {
            //if greater element then remove smaller previous element
            while(!dq.empty() && nums[dq.back()]<=nums[i])
            dq.pop_back();
            dq.push_back(i);
        }
        vector<int> res;
        for(int i=k;i<nums.size();i++)
        { 
            res.push_back(nums[dq.front()]);
            //checking if front part of current wnidow
            while(!dq.empty() && dq.front()<=(i-k))
            dq.pop_front();
            //if greater element then remove smaller previous element
            while(!dq.empty() && nums[dq.back()]<=nums[i])
            dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};
