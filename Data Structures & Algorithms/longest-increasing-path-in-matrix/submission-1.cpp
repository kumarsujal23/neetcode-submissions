class Solution {
public:
    int solve(int r,int c,vector<vector<int>>& matrix,int prev,vector<vector<int>> &dp)
    {
        if(dp[r][c]!=-1)
        return dp[r][c];
        int ans=1,n=matrix.size(),m=matrix[0].size();
        if(r+1<n && matrix[r+1][c]>prev)
        ans=max(ans,1+solve(r+1,c,matrix,matrix[r+1][c],dp));
        if(r-1>=0 && matrix[r-1][c]>prev)
        ans=max(ans,1+solve(r-1,c,matrix,matrix[r-1][c],dp));
        if(c+1<m && matrix[r][c+1]>prev)
        ans=max(ans,1+solve(r,c+1,matrix,matrix[r][c+1],dp));
        if(c-1>=0 && matrix[r][c-1]>prev)
        ans=max(ans,1+solve(r,c-1,matrix,matrix[r][c-1],dp));
        return dp[r][c]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,solve(i,j,matrix,matrix[i][j],dp));
            }
        }
        return ans;
    }
};
