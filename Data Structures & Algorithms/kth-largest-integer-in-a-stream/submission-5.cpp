class KthLargest {
public:
    int kth=0;
    vector<int> v;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->kth=k;
        this->v=nums;
        if(nums.size()>0)
        {
        for(int i=0;(i<k && i<nums.size());i++)
        pq.push(nums[i]);
        for(int i=k;i<nums.size();i++)
        {
            if(pq.top()<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        }
    }
    
    int add(int val) {
        if(v.size()<kth)
        {
            pq.push(val);
        }
        else if(!pq.empty() && val>pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        v.push_back(val);
        return pq.top();
    }
};
