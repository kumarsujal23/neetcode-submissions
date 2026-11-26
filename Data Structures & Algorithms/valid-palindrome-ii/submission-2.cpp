class Solution {
public:
    bool solve(int i,int j,bool can,string &s)
    {
        if(i==j || i>j)
        return true;
        if(s[i]==s[j] && can)
        {
            return solve(i+1,j-1,can,s)||solve(i,j-1,false,s)||solve(i+1,j,false,s);
        }
        else if(s[i]==s[j])
        {
            return solve(i+1,j-1,can,s);
        }
        else if(s[i]!=s[j] && can)
        {
            return solve(i,j-1,false,s)||solve(i+1,j,false,s);
        }
        else 
        return false;
    }
    bool validPalindrome(string s) {
        return solve(0,s.size()-1,true,s);
    }
};