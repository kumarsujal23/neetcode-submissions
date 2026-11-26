class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord || find(wordList.begin(),wordList.end(),endWord)==wordList.end())
        return 0;
        int n=wordList.size(),m=beginWord.size();
        vector<vector<int>> adj(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        mp[wordList[i]]=i;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int cnt=0;
                for(int k=0;k<m;k++)
                {
                    if(wordList[i][k]!=wordList[j][k])
                    cnt++;
                }
                if(cnt==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int> q;
        vector<int> vis(n);
        for(int i=0;i<m;i++)
        {
            for(char ch='a';ch<='z';ch++)
            {
                if(ch==beginWord[i])
                continue;
                string word= beginWord.substr(0,i)+ch + beginWord.substr(i+1);
                if(mp.find(word)!=mp.end())
                {
                    q.push(mp[word]);
                    vis[mp[word]]=1;
                }
                
            }
        }
        int res=1;
        while(!q.empty())
        {
            res++;
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int f=q.front();
                q.pop();
                if(endWord==wordList[f])
                return res;
                for(auto neigh:adj[f])
                {
                    if(!vis[neigh])
                    {
                        vis[neigh]=1;
                        q.push(neigh);
                    }
                }
            }
        }
        return 0;
    }
};
