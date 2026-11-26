class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int INF=2147483647;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                pair<int,int> f=q.front();
                q.pop();
                int row=f.first,col=f.second;
                if(row<n-1 && grid[row+1][col]!=-1 && grid[row+1][col]==INF)
                {
                    grid[row+1][col]=min(grid[row+1][col],grid[row][col])+1;
                    q.push({row+1,col});
                }
                if(col<m-1 && grid[row][col+1]!=-1 && grid[row][col+1]==INF)
                {
                    grid[row][col+1]=min(grid[row][col+1],grid[row][col])+1;
                    q.push({row,col+1});
                }
                if(row>0 && grid[row-1][col]!=-1 && grid[row-1][col]==INF)
                {
                    grid[row-1][col]=min(grid[row-1][col],grid[row][col])+1;
                    q.push({row-1,col});
                }
                if(col>0 && grid[row][col-1]!=-1 && grid[row][col-1]==INF)
                {
                    grid[row][col-1]=min(grid[row][col-1],grid[row][col])+1;
                    q.push({row,col-1});
                }
            }
            
        }
    }
};
