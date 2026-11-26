class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       queue<int> q;
       q.push(0);
       int far=0;
       while(!q.empty())
       {
            int i=q.front();
            q.pop();
            int start=max(i+minJump,far+1);
            int end=min(i+maxJump,(int)(s.size()-1));
            for(int j=start;j<=end;j++)
            {
                if(j==s.size()-1 && s[j]=='0')
                return true;
                if(s[j]=='0')
                q.push(j);
            }
            far=max(far,end);
       } 
       return false;
    }
};