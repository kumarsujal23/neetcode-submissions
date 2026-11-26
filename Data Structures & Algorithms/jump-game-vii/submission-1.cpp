class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       queue<int> q;
       vector<int> vis(s.size());
       q.push(0);
       while(!q.empty())
       {
            int sz=q.size();
            for(int k=0;k<sz;k++)
            {
                int i=q.front();
                if(i==s.size()-1)
                return true;
                q.pop();
                for(int j=i+minJump;j<=min(i + maxJump, (int)(s.size() - 1));j++)
                {
                    if(s[j]=='0' && !vis[j])
                    {
                        q.push(j);
                        vis[j]=1;
                    }
                }
            }
       } 
       return false;
    }
};