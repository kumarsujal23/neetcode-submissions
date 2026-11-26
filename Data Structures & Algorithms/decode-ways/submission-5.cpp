class Solution {
public:
    int numDecodings(string s) {
        map<string,char> mp;
        for(char ch='A';ch<='Z';ch++)
        mp[to_string(ch-'A'+1)]=ch;
       
        // vector<int> dp(s.size()+1);
        // dp[s.size()]=1;
        // for(int i=s.size()-1;i>=0;i--)
        // {
        //     if(mp.find(s.substr(i,1))!=mp.end())
        //     dp[i]=dp[i+1];
        //     if(i+1<s.size() && mp.find(s.substr(i,2))!=mp.end())
        //     dp[i]+=dp[i+2];
        // }
        // return dp[0];
        int next1=1,next2=0,curr=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            curr=0;
            if(mp.find(s.substr(i,1))!=mp.end())
            curr=next1;
            if(i+1<s.size() && mp.find(s.substr(i,2))!=mp.end())
            curr+=next2;
            next2=next1;
            next1=curr;
        }
        return curr;

    }
};
