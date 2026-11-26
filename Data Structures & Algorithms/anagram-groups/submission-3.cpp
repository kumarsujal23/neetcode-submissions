class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++)
        {
            vector<char> freq(26,0);
            for(auto ch:strs[i])
            {
                freq[ch-'a']++;
            }
            string key="";
            for(auto f:freq)
            {
                key+='#'+f;
            }
            mp[key].push_back(strs[i]);
        }
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
