class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int node=it.second.first;
            int cost=it.second.second;
            int stops=it.first;
            if(stops>k)
            continue;
            for(auto it:adj[node])
            {
                int nextnode=it.first;
                int nextcost=it.second;
                if(dist[nextnode]>cost+nextcost && stops<=k)
                {
                    dist[nextnode]=cost+nextcost;
                    q.push({stops+1,{nextnode,dist[nextnode]}});
                }
            }
        }
        if(dist[dst]==INT_MAX)
        return -1;
        else
        return dist[dst];
    }
};
