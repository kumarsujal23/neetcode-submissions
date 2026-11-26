class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        if(stones.size()==1)
        return stones[0];
        for(int i=0;i<stones.size();i++)
        pq.push(stones[i]);
      while(pq.size()>1)
    {
        int top1=pq.top();
        pq.pop();
        int top2=pq.top();
        pq.pop();
        pq.push(abs(top1-top2));

    }
    if(!pq.empty())
    return pq.top();
    return 0;

    }
};
