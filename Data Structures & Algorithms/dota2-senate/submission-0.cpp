class Solution {
public:
    string predictPartyVictory(string senate) {
       queue<int> r,d;
       int n=senate.size();
       for(int i=0;i<n;i++)
       {
            if(senate[i]=='R')
            r.push(i);
            else
            d.push(i);
       } 
        while(!r.empty() && !d.empty())
        {
            int rturn=r.front();
            int dturn=d.front();
            r.pop();
            d.pop();
            if(rturn<dturn)
            r.push(rturn+n);
            else
            d.push(dturn+n);
        }
        if(r.empty())
        return "Dire";
        else
        return "Radiant";
    }
};