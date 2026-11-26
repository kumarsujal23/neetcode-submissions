class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<pair<int,int>>> adj(n*m);
        vector<int> drx={1,-1,0,0};
        vector<int> dry={0,0,1,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int node=i*m+j;
                for(int k=0;k<4;k++)
                {
                    int r=drx[k]+i;
                    int c=dry[k]+j;
                    if(r<0 || c<0 || r>=n || c>=m)
                    continue;
                    int diff=abs(heights[i][j]-heights[r][c]);
                    int nextnode=r*m+c;
                    adj[node].push_back({nextnode,diff});
                    adj[nextnode].push_back({node,diff});
                }
            }
        }
        vector<int> disteff(n*m,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto f=pq.top();
            pq.pop();
            int node=f.second;
            int effort=f.first;
            if(effort>disteff[node])
            continue;
            if(node==n*m-1)
            return effort;
            for(auto it:adj[node])
            {
                int nexteffort=max(effort,it.second);
                int nextnode=it.first;
                if(nexteffort<disteff[nextnode])
                {
                    disteff[nextnode]=nexteffort;
                    pq.push({nexteffort,nextnode});
                }
            }
        }
        return 0;
    }
};