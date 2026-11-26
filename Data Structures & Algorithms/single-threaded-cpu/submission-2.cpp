class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        int time=tasks[0][0],j=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({tasks[0][1],tasks[0][2]});
        vector<int> res;
        while(!pq.empty()||j<n)
        {
            if(!pq.empty())
            {
            auto topi=pq.top();
            pq.pop();
            res.push_back(topi.second);
            time+=topi.first;
            }
            while(j<n && tasks[j][0]<=time)
            {
                pq.push({tasks[j][1],tasks[j][2]});
                j++;
            }
            time++;
        }
        return res;
    }
};