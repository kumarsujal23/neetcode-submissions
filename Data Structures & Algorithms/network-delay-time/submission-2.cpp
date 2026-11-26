class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int time=it.first;
            for(auto neigh:adj[node])
            {
                int nextnode=neigh.first;
                int t=neigh.second;
                if(dist[nextnode]>t+time)
                {
                    dist[nextnode]=t+time;
                    pq.push({dist[nextnode],nextnode});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            maxi=max(maxi,dist[i]);
        }
        if(maxi==INT_MAX)
        return -1;
        else
        return maxi;
    }
};
