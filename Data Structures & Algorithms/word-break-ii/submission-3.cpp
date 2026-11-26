class Solution {
public:
    vector<string> res;
    void solve(string &curr,string &sofar,int i,string &s,unordered_map<string,int> &mp)
    {
        if(i==s.size())
        {
            if(curr=="")
            res.push_back(sofar);
            return;
        }
        curr+=s[i];
        if(mp.find(curr)!=mp.end())
        {
            string here=sofar;
            string herecurr="";
            if(sofar.size()>0)
            sofar+=" "+curr;
            else 
            sofar+=curr;
            solve(herecurr,sofar,i+1,s,mp);
            solve(curr,here,i+1,s,mp);
        }
        else
        solve(curr,sofar,i+1,s,mp);
        return;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto it:wordDict)
        {
            mp[it]++;
        }
        string curr="";
        string sofar="";
        solve(curr,sofar,0,s,mp);
        return res;
    }
};