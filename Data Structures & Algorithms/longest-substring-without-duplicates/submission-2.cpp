class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        if(s.size()==0)
        return 0;
        int ans=1;
        int l=0,r=0;
        while(r<s.size())
        {
            if(mp.find(s[r])==mp.end())
            {
                mp[s[r]]=r;
                ans=max(ans,r-l);
                r++;
            }
            else
            {
                ans=max(ans,r-l);
                int j=mp[s[r]];
                while(l<=j)
                {
                    mp.erase(s[l]);
                    l++;
                }
                mp[s[r]]=r;
                r++;
            }
        }
        ans=max(ans,r-l);
        return ans;
    }
};
