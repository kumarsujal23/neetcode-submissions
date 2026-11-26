class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int &c)
    {
        int n=grid.size(),m=grid[0].size();
        vis[row][col]=1;
        c++;

        if(row>0 && grid[row-1][col] && !vis[row-1][col])
        dfs(row-1,col,grid,vis,c);
        if(col>0 && grid[row][col-1] && !vis[row][col-1])
        dfs(row,col-1,grid,vis,c);
        if(col<m-1 && grid[row][col+1] && !vis[row][col+1])
        dfs(row,col+1,grid,vis,c);
        if(row<n-1 && grid[row+1][col] && !vis[row+1][col])
        dfs(row+1,col,grid,vis,c);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int ans=0,c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] && !vis[i][j])
                {
                    c=0;
                    dfs(i,j,grid,vis,c);
                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
};
