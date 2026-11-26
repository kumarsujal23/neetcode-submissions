class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=grid[0][0];
        pq.push({dist[0][0],{0,0}});
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int time=it.first;
            int r=it.second.first,c=it.second.second;
            if(dist[r][c]<time)
            continue;
            // if(r==n-1 && c==n-1)
            // return time;
            if(r+1<n)
            {
                int newtime=max(time,grid[r+1][c]);
                if(newtime<dist[r+1][c])
                {
                    dist[r+1][c]=newtime;
                    pq.push({newtime,{r+1,c}});
                }
            }
            if(r-1>=0)
            {
                int newtime=max(time,grid[r-1][c]);
                if(newtime<dist[r-1][c])
                {
                    dist[r-1][c]=newtime;
                    pq.push({newtime,{r-1,c}});
                }
            }
            if(c+1<n)
            {
                int newtime=max(time,grid[r][c+1]);
                if(newtime<dist[r][c+1])
                {
                    dist[r][c+1]=newtime;
                    pq.push({newtime,{r,c+1}});
                }
            }
            if(c-1>=0)
            {
                int newtime=max(time,grid[r][c-1]);
                if(newtime<dist[r][c-1])
                {
                    dist[r][c-1]=newtime;
                    pq.push({newtime,{r,c-1}});
                }
            }
        }
        return dist[n-1][n-1];
    }
};
