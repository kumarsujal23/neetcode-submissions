class Solution {
public:
    unordered_map<char,vector<char>> mp;
    vector<string> res;
    void solve(int i,string ans,string digits)
    {
        if(i>=digits.size())
        {
            res.push_back(ans);
            return;
        }
        for(auto it:mp[digits[i]])
        {
            ans.push_back(it);
            solve(i+1,ans,digits);
            ans.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        return {};
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        string ans="";
        solve(0,ans,digits);
        return res;
    }
};
