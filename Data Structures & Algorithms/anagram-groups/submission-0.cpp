class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string u=strs[i];
            sort(u.begin(),u.end());
            mp[u].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            vector<string> v=it.second;
            ans.push_back(v);
        }
        return ans;
    }
};
