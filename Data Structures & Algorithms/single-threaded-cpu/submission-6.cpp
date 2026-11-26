class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        int time=0,j=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> res;
        while(!pq.empty()||j<n)
        {
          if(pq.empty())
          {
            time=max(time,tasks[j][0]);
          }
          while(j<n && tasks[j][0]<=time)
          {
            pq.push({tasks[j][1],tasks[j][2]});
            j++;
          }
           auto topi=pq.top();
           res.push_back(topi.second);
           pq.pop();
           time+=topi.first;
        }
        return res;
    }
};