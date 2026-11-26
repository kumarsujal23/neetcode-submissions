class Solution {
public:
    vector<vector<string>> res;
    bool palindrome(int i,int j,string s)
    {
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            return false;
        }
        return true;
    }
    void solve(int i,string &s,vector<string> &ans)
    {
        if(i>=s.size())
        {
            res.push_back(ans);
        }
        for(int j=i;j<s.size();j++)
        {
            if(palindrome(i,j,s))
            {
                ans.push_back(s.substr(i,j-i+1));
                solve(j+1,s,ans);
                ans.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        solve(0,s,ans);
        return res;  
    }
};
