class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==0)
                cnt++;
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                int row=p.first,col=p.second;
                if(row<n-1 && grid[row+1][col]==1 && !vis[row+1][col])
                {q.push({row+1,col});
                  vis[row+1][col]=1;}
                if(col<m-1 && grid[row][col+1]==1 && !vis[row][col+1])
                {q.push({row,col+1});
                vis[row][col+1]=1;}
                if(row>0 && grid[row-1][col]==1 && !vis[row-1][col])
                {q.push({row-1,col});
                vis[row-1][col]=1;}
                if(col>0 && grid[row][col-1]==1 && !vis[row][col-1])
                {q.push({row,col-1});
                vis[row][col-1]=1;}
            }
            ans++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]!=0 && cnt!=(n*m))
                return -1;
            }
        }
        return max(ans-1,0);

    }
};
