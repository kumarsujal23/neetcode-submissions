class Solution {
public:
    vector<vector<string>> res;
    void solve(int i,vector<string> ans,string &s)
    {
        if(i>=s.size())
        {
            res.push_back(ans);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(pal(i,j,s))
            {
                ans.push_back(s.substr(i,j-i+1));
                solve(j+1,ans,s);
                ans.pop_back();
            }
        }
        return;
    }
    bool pal(int i,int j,string s)
    {
        int l=i,r=j;
        while(l<r)
        {
            if(s[l]!=s[r])
            return false;
            l++;
            r--;
        }
        return true;
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        solve(0,ans,s);
        return res;
    }
};
