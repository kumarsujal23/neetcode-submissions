class Solution {
public:
    bool checkValidString(string s) {
        int lmin=0,lmax=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                lmin++;
                lmax++;
            }
            else if(s[i]==')')
            {
                lmin--;
                lmax--;
            }
            else
            {
                lmax++;
                lmin--;
            }
            if(lmin<0)
            lmin=0;
            if(lmax<0)
            return false;
        }
        return lmin==0;

    }
};
