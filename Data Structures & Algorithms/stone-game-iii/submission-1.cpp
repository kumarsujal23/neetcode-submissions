class Solution {
public:
    int total;
    vector<int> pref;
    int solve(int i,int alice,vector<int>& value,vector<vector<int>> &dp)
    {
        if(i==value.size())
        return 0;
        if(dp[i][alice]!=-1)
        return dp[i][alice];
        int res=alice?INT_MIN:INT_MAX;
        for(int j=1;j<=3;j++)
        {
            if(i+j>value.size())
            break;
            if(alice)
            {
                int ans=((i-1>=0)?(pref[i+j-1]-pref[i-1]):pref[i+j-1]);
                res=max(res,solve(i+j,0,value,dp)+ans);
            }
            else
            res=min(res,solve(i+j,1,value,dp));
        }
        return dp[i][alice]=res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        total=0;
        pref.resize(stoneValue.size());
        pref[0]=stoneValue[0];
        for(int i=1;i<stoneValue.size();i++)
        pref[i]=pref[i-1]+stoneValue[i];
        for(auto it:stoneValue)
        total+=it;
        vector<vector<int>> dp(stoneValue.size(),vector<int>(2,-1));
        int alicescore=solve(0,1,stoneValue,dp);
        int bobscore=total-alicescore;
        if(alicescore>bobscore)
        return "Alice";
        else if(alicescore<bobscore)
        return "Bob";
        else 
        return "Tie";
    }
};