class Solution {
public:
    bool check(int &wcap,int d,vector<int>& w)
    {
        int sum=w[0];
        for(int i=0;i<w.size();i++)
        {
            if(wcap<w[i])
            return false;
        }
        for(int i=0;i<w.size();i++)
        {
            if(i+1<w.size() && sum+w[i+1]<=wcap)
            sum+=w[i+1];
            else
            {
                d--;
                if(i+1<w.size())
                sum=w[i+1];
                else
                sum=0;
            }
        }
        return d>=0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int r=0;
        for(auto w:weights)
        {
            r+=w;
        }
        int l=0;
        int ans=0;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(check(m,days,weights))
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