class Solution {
public:
    string longestPalindrome(string s) {
        int reslen=0,l=0,r=0,n=s.size(),resl=0;
        for(int i=0;i<n;i++)
        {
            l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                if(reslen<(r-l+1))
                {
                    reslen=r-l+1;
                    resl=l;

                }
                l--;
                r++;
            }
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                if(reslen<(r-l+1))
                {
                    reslen=r-l+1;
                    resl=l;

                }
                l--;
                r++;
            }
        }
        return s.substr(resl,reslen);
    }
};
