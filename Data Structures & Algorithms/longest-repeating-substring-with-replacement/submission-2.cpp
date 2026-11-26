class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0,l=0,r=0;
        unordered_map<int,int> mp;
        int len=0;
        while(r<s.size())
        {
            mp[s[r]]++;
            len=max(len,mp[s[r]]);
            if(r-l+1-len<=k)
            {
                ans=max(ans,r-l+1);
                r++;
            }
            else
            {
                ans=max(ans,r-l);
                if(len==mp[s[l]])
                len--;
                mp[s[l]]--;
                l++;
                r++;
            }

        }
        return ans;
    }
};
