class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(auto it:s)
        mp[it]++;
        int l1=0,l=0,r=0;
        vector<int> ans;
        while(r<s.size())
        {
            if(mp[s[l]]!=0)
            {
                mp[s[r]]--;
                r++;
            }
            else if(mp[s[l]]==0 && l<r)
            {
                l++;
                if(l==r)
                {
                    ans.push_back(r-l1);
                    l=r;
                    l1=r;
                }
            }
            
        }
        ans.push_back(r-l1);
        return ans;
    }
};
