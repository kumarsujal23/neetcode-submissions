class Solution {
public:
    string minWindow(string s, string t) {
        int ans=INT_MAX;
        if(t.size()==0)
        return "";
        unordered_map<int,int> tcount,win;
        for(auto it:t)
        tcount[it]++;
        int l=0,r=0;
        pair p={-1,-1};
        int need=tcount.size(),have=0;
        while(r<s.size())
        {
            win[s[r]]++;
            if(tcount.find(s[r])!=tcount.end() && win[s[r]]==tcount[s[r]])
            have++;
            while(need==have)
            {
                if(r-l+1<=ans)
                {
                    ans=r-l+1;
                    p={l,r};
                }
                win[s[l]]--;
                if(tcount.find(s[l])!=tcount.end() && win[s[l]]<tcount[s[l]])
                have--;
                l++;
            }
            r++;
        }
        if(ans==INT_MAX)
        return "";
        else
        return s.substr(p.first,ans);
    }
};
