class Solution {
public:
    int solve(int l,int r,vector<int> &p,vector<vector<int>> &dp)
    {
        if(l>r)
        return 0;
        if(dp[l][r]!=-1)
        return dp[l][r];
        bool flag=(r-l+1)%2==0;
        int left=flag?p[l]:0;
        int right=flag?p[r]:0;
        return dp[l][r]=max(left+solve(l+1,r,p,dp),right+solve(l,r-1,p,dp));
    }
    bool stoneGame(vector<int>& piles) {
        int total=0;
        for(auto it:piles)
        total+=it;
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
        int alicescore=solve(0,piles.size()-1,piles,dp);
        return alicescore>total-alicescore;
    }
};