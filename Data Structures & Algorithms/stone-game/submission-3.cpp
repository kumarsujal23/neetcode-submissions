class Solution {
public:
    int total;
    bool solve(int i,int j,int alicesum,bool alice,vector<int>& piles)
    {
        if(i==j)
        {
            if(alice)
            alicesum+=piles[i];
            int bobsum=total-alicesum;
            if(alicesum>bobsum)
            return true;
            else
            return false;
        }
        int sum1=alice?piles[i]:0;
        bool cond1=solve(i+1,j,alicesum+sum1,!alice,piles);
        if(cond1)
        return true;
        int sum2=alice?piles[j]:0;
        bool cond2=solve(i,j-1,alicesum+sum2,!alice,piles);
        return cond1||cond2;

    }
    bool stoneGame(vector<int>& piles) {
        total=0;
        for(auto it:piles)
        total+=it;
        return solve(0,piles.size()-2,piles[piles.size()-1],false,piles)||solve(1,piles.size()-1,piles[0],false,piles);
    }
};