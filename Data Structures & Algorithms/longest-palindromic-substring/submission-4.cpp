class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string t="";
        for(int i=0;i<n;i++)
            t+="#"+string(1,s[i]);
        t+="#";
        int n1=t.size(),l=0,r=0;
        vector<int> p(n1,1);
        for(int i=0;i<n1;i++)
        {
            p[i]=(i<r?min(r-i,p[l+r-i]):1);
            while(i+p[i]<n1 && i-p[i]>=0 && t[i+p[i]]==t[i-p[i]])
            p[i]++;
            if(r<i+p[i])
            {
                r=i+p[i];
                l=i-p[i];
            }
        }
        int reslen=0,resindx=0,cenindx=0;
        for(int i=0;i<p.size();i++)
        {
            
            if(reslen<p[i])
            {
                reslen=p[i]-1;
                cenindx=i;
            }
        }
        resindx=(cenindx-reslen)/2;
        return s.substr(resindx,reslen);
    }
};
