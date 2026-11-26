class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord)
        return 0;
        int c=0,n=wordList.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[wordList[i]]=i;
            if(endWord==wordList[i])
            c++;
        }
        if(!c)
        return 0;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1+i;j<n;j++)
            {
                c=0;
                for(int k=0;k<wordList[i].size();k++)
                {
                    if(wordList[i][k]!=wordList[j][k])
                    c++;
                }
                if(c==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int> q;
        vector<int> vis(n);
        for(int i=0;i<beginWord.size();i++)
        {
            for(char ch='a';ch<='z';ch++)
            {
                if(ch==beginWord[i])
                continue;
                string s= beginWord.substr(0,i)+ch+beginWord.substr(i+1);
                if(mp.find(s)!=mp.end())
                {
                    q.push(mp[s]);
                    vis[mp[s]]=1;
                }
            }
        }
        int res=1;
        while(!q.empty())
        {
            res++;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int f=q.front();
                q.pop();
                if(wordList[f]==endWord)
                return res;
                for(auto it:adj[f])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }

            }
        }
        return 0;
    }
};
