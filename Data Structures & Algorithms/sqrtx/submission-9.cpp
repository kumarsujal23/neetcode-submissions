class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x;
        int ans=0;
        while(l<=h)
        {
            int m=(l+h)/2;
            if((long long)m*m==x)
            return m;
            else if((long long)m*m>x)
            h=m-1;
            else 
            {
                ans=m;
                l=m+1;
            }
        }
        return ans;
    }
};