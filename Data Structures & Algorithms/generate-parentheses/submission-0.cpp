class Solution {
public:
    vector<string> res;
    void solve(int &n,string s,int sum)
    {
        if(s.size()==n)
        {
            if(sum==0)
            {
                res.push_back(s);
            }
            return;
        }
        if(sum<0)
        return;
        s.push_back('(');
        solve(n,s,sum+1);
        s.pop_back();
        s.push_back(')');
        solve(n,s,sum-1);
        s.pop_back();
        return;
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        int n1=2*n;
        solve(n1,s,0);
        return res;
    }
};
