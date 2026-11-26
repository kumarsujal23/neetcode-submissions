class Solution {
public:
    int target;
    bool solve(int i,vector<int>& sq,vector<int>& m)
    {
        if(i==m.size())
        {
            return (sq[0]==sq[1] && sq[1]==sq[2] && sq[2]==sq[3]);
        }
        for(int j=0;j<4;j++)
        {
            if(sq[j]>target)
            return false;

        }
        for(int j=0;j<4;j++)
        {
            sq[j]+=m[i];
            if(solve(i+1,sq,m))
            return true;
            sq[j]-=m[i];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(auto m: matchsticks)
        sum+=m;
        if(sum%4!=0)
        return false;
        target=sum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<int> sq(4);
        return solve(0,sq,matchsticks);
    }
};