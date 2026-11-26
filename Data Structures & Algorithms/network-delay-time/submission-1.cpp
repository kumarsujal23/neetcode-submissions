class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        } 
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto f=pq.top();
            pq.pop();
            int node=f.second;
            int cost=f.first;
            if(cost>dist[node])
            continue;
            for(auto it:adj[node])
            {
                if(cost+it.second<dist[it.first])
                {
                    dist[it.first]=cost+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int mini=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
            return -1;
            mini=max(mini,dist[i]);
        }
        return mini;
    }
};
