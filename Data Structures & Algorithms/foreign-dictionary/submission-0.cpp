class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<int,int> mp;
        for(auto it:words)
        {
            for(auto c:it)
            mp[c-'a']++;
        }
        vector<vector<int>> adj(26);
        vector<int> indeg(26);
        for(int i=0;i<words.size()-1;i++)
        {
            int j=0;
            while(j<words[i].size() && j<words[i+1].size() && words[i][j]==words[i+1][j])
            j++;
            if(j>=words[i+1].size() && j<words[i].size())
            return "";
            else if(j>=words[i].size() && j<=words[i+1].size())
            continue;
            adj[words[i][j]-'a'].push_back(words[i+1][j]-'a');
            indeg[words[i+1][j]-'a']++;
        }
        string ans="";
        queue<int> q;
        for(int i=0;i<26;i++)
        {
            if(mp.find(i)!=mp.end() && indeg[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            ans+=(char)('a'+f);
            for(auto it:adj[f])
            {
                indeg[it]--;
                if(indeg[it]==0)
                q.push(it);
            }
        }
        if(ans.size()!=mp.size())
        return "";
        else
        return ans;
    }
};
