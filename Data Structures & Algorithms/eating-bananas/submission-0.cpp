class Solution {
public:
    bool solve(int m,vector<int>& piles,int &h)
    {
        int sum=0;
        for(int i=0;i<piles.size();i++)
        {
            int a=piles[i]/m;
            sum+=(piles[i]%m==0?a:a+1);
            if(sum>h)
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(solve(m,piles,h))
            {
                ans=m;
                r=m-1;
            }
            else
            l=m+1;
        }
        return ans;
    }
};
