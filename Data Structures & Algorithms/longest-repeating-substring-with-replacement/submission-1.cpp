class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0,l=0;
        unordered_map<char,int> mp;
        int ans=0,a=0;
        while(r<s.size())
        {
            mp[s[r]]++;
            a=max(a,mp[s[r]]);
            if((r-l+1-a)<=k)
            {
                ans=max(ans,r-l+1);
                r++;
            }
            else
            {
                ans=max(ans,r-l);
                mp[s[l]]--;
                l++;
                r++;
            }
        }
        return ans;
    }
};
