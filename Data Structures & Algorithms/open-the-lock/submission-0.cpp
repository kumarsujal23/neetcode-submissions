class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int> mp;
        for(int i=0;i<deadends.size();i++)
        {
            if(deadends[i]=="0000")
            return -1;
            mp[deadends[i]]++;
        }
        if(target=="0000")
        return 0;
        int step=0;
        queue<string> q;
        q.push("0000");
        mp["0000"]++;
        while(!q.empty())
        {
            step++;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                string f=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    for(auto it:{1,-1})
                    {
                        string nextf=f;
                        nextf[j]=char((nextf[j]-'0'+it+10)%10+'0');
                        if(mp.find(nextf)!=mp.end())
                        continue;
                        if(target==nextf)
                        return step;
                        mp[nextf]++;
                        q.push(nextf);
                    }
                }
            }
        }
        return -1;
    }
};