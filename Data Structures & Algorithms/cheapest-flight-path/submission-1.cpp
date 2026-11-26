class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            pair<int,pair<int,int>> f=q.front();
            q.pop();
            int stops=f.first;
            int node=f.second.first;
            int cost=f.second.second;
            if(stops>k)
            continue;
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjdist=it.second;
                if(cost+adjdist<dist[adjnode] && stops<=k)
                {
                    dist[adjnode]=cost+adjdist;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==INT_MAX)
        return -1;
        else
         return dist[dst];

    }
};
