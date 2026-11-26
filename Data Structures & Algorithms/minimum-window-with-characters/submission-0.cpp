class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()==0)
        return "";
        unordered_map<char,int> tcount,win;
        int res=INT_MAX;
        pair<int,int> p={-1,-1};
        for(auto it:t)
        tcount[it]++;
        int need=tcount.size(),have=0;
        int l=0;
        for(int r=0;r<s.size();r++)
        {
            win[s[r]]++;
            if(tcount.find(s[r])!=tcount.end() && win[s[r]]==tcount[s[r]])
            have++;
            while(need==have)
            {
                if((r-l+1)<res)
                {
                    res=r-l+1;
                     p={l,r};
                }
                win[s[l]]--;
                if(tcount.find(s[l])!=tcount.end() && win[s[l]]<tcount[s[l]])
                have--;
               
                l++;
            }
            
          
        }
        if(res==INT_MAX)
            return "";
            else
            return s.substr(p.first,res);

    }
};
