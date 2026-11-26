class Solution {
public:
    int tribonacci(int n) {
        int f1=0,f2=1,f3=1;
        for(int i=3;i<=n;i++)
        {
            int curr=f1+f2+f3;
            f1=f2;
            f2=f3;
            f3=curr;
        }
        if(n==0)
        return 0;
        return f3;
    }
};