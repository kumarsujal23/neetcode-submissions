class Solution {
public:
    void solve(int r,int col,int &c,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        vis[r][col]=1;
        int n=grid.size(),m=grid[0].size();
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int row=r+dx[i];
            int colum=col+dy[i];
            if(row>=0 && row<n && colum>=0 && colum<m)
            {
                if(!vis[row][colum] && grid[row][colum])
                solve(row,colum,c,grid,vis);
                else if(!grid[row][colum])
                c++;
                
            }
            else 
            c++;
        }
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
       int c=0,n=grid.size(),m=grid[0].size();
       vector<vector<int>> vis(n,vector<int>(m));
       for(int i=0;i<n;i++)
       {
            for(int j=0;j<m;j++)
            {
                    if(!vis[i][j] && grid[i][j])
                    {
                        solve(i,j,c,grid,vis);
                        break;
                    }
            }
       } 
        return c;
    }
};