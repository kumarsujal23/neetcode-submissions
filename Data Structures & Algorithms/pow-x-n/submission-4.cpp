class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        bool con=false;
        if(n<0)
        {
            n=abs(n);
            con=true;
        }
        while(n)
        {
            if(n%2==1)
            ans=ans*x;
            x=x*x;
            n=n/2;
        }
        if(con)
        return 1/ans;
        else
        return ans;
    }
};
