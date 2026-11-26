class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        while(n!=1)
        {
            int a=n;
            int sum=0;
            if(mp.find(n)!=mp.end())
            return false;
            mp[a]++;
            while(a)
            {
                int d=a%10;
                sum+=d*d;
                a/=10;
            }
            n=sum;
            
        }
        return true;
    }
};
