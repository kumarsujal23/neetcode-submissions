class Solution {
public:
    int numSquares(int n) {
        vector<int> perfect;
        int i=1;
        while(i*i<=10000)
        {
            perfect.push_back(i*i);
            i++;
        }
        vector<int> dp(n+1,INT_MAX);
        for(auto p:perfect)
        {
            if(p<=n)
            dp[p]=1;
            else 
            break;
        }
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(auto p:perfect)
            {
                if(p<=n && i-p>=0)
                dp[i]=min(dp[i],dp[i-p]+1);
                else
                break;
            }
        }
        return dp[n];
    }
};