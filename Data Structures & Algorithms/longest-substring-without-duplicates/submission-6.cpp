class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int res=0,l=0,r=0;
        while(r<s.size())
        {
            if(mp.find(s[r])!=mp.end())
            {
                res=max(res,r-l);
                l=max(l,mp[s[r]]+1);
                mp[s[r]]=r;
                r++;
            }
            else
            {
                mp[s[r]]=r;
                r++;
            }
        }
        res=max(res,r-l);
        return res;
    }
};
