class Solution {
public:
    // bool solve(int i,int j,string &s1, string &s2, string &s3,vector<vector<int>> &dp)
    // {
    //     if((i+j)==s3.size())
    //     {
    //         return ((i==s1.size()) && (j==s2.size()));
    //     }
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     bool res=false;
    //     if(i<s1.size() && s1[i]==s3[i+j])
    //     {
    //         res=solve(i+1,j,s1,s2,s3,dp);
    //     }
    //     if(j<s2.size() && s2[j]==s3[i+j])
    //     {
    //        res=solve(i,j+1,s1,s2,s3,dp);
    //     }
    //     return dp[i][j]=res;
    // }
    bool isInterleave(string s1, string s2, string s3) {
        // vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        // return solve(0,0,s1,s2,s3,dp);
        int n=s1.size(),m=s2.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        if((m+n)!=s3.size())
        return false;
        dp[n][m]=true;
        for(int i=n;i>=0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                if(i<n && s1[i]==s3[i+j] && dp[i+1][j])
                dp[i][j]=true;
                if(j<m && s2[j]==s3[i+j] && dp[i][j+1])
                dp[i][j]=true;
            }
        }
        return dp[0][0];
    }
};
