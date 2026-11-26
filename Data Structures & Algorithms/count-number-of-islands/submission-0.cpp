class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        int n=vis.size(),m=vis[0].size();
        vis[row][col]=1;
        if(row>0 && grid[row-1][col]=='1' && !vis[row-1][col])
        dfs(row-1,col,grid,vis);
        if(col>0 && grid[row][col-1]=='1' && !vis[row][col-1] )
        dfs(row,col-1,grid,vis);
        if(row<n-1 && grid[row+1][col]=='1' && !vis[row+1][col])
        dfs(row+1,col,grid,vis);
        if(col<m-1 && grid[row][col+1]=='1' && !vis[row][col+1])
        dfs(row,col+1,grid,vis);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
