class Solution {
public:
    vector<int> prefix;
    int solve(int Alice,int i,int m,vector<int>& p,vector<vector<vector<int>>> &dp)
    {
        if(i==p.size())
        {
            return 0;
        }
        if(dp[Alice][i][m]!=-1)
        return dp[Alice][i][m];
        int res=Alice?0:INT_MAX;
        for(int j=1;j<=2*m;j++)
        {
            if(i+j>p.size())
            break;
            if(Alice)
            {
                int ans=((i-1>=0)?(prefix[i+j-1]-prefix[i-1]):prefix[i+j-1]);
                res=max(res,solve(0,i+j,max(j,m),p,dp)+ans);
            }
            else
            res=min(res,solve(1,i+j,max(j,m),p,dp));
        }
        return dp[Alice][i][m]=res;
    }
    int stoneGameII(vector<int>& piles) {
        prefix.resize(piles.size());
        prefix[0]=piles[0];
        for(int i=1;i<piles.size();i++)
        prefix[i]=prefix[i-1]+piles[i];
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(piles.size(),vector<int>(piles.size()+1,-1)));
        return solve(1,0,1,piles,dp);
    }
};