class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &v,vector<vector<int>>& h)
    {
        int n=v.size(),m=v[0].size();
        if(r<n-1 && !v[r+1][c] && h[r+1][c]>=h[r][c])
        {
            v[r+1][c]=1;
            dfs(r+1,c,v,h);
        }
        if(r>0 && !v[r-1][c] && h[r-1][c]>=h[r][c])
        {
            v[r-1][c]=1;
            dfs(r-1,c,v,h);
        }
        if(c<m-1 && !v[r][c+1] && h[r][c+1]>=h[r][c])
        {
            v[r][c+1]=1;
            dfs(r,c+1,v,h);
        }
        if(c>0 && !v[r][c-1] && h[r][c-1]>=h[r][c])
        {
            v[r][c-1]=1;
            dfs(r,c-1,v,h);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> pan(n,vector<int>(m));
        vector<vector<int>> atl(n,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            pan[0][i]=1;
            atl[n-1][i]=1;
        }
        for(int i=0;i<n;i++)
        {
            pan[i][0]=1;
            atl[i][m-1]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pan[i][j]==1)
                dfs(i,j,pan,heights);
                if(atl[i][j]==1)
                dfs(i,j,atl,heights);
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pan[i][j] && atl[i][j])
                res.push_back({i,j});
            }
        }
        return res;
    }
};
