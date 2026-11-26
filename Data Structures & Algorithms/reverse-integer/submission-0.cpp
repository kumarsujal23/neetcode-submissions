class Solution {
public:
    int reverse(int x) {
        long ans=0,c=0;
        if(x<0)
        {
            x=abs(x);
            c++;
        } 
        while(x)
        {
            
            ans=ans*10+x%10;
            if (ans < INT_MIN || ans > INT_MAX) 
            return 0;
            x=x/10;
        }
        if(c)
        ans*=(-1);
        return (int)ans;
    }
};
