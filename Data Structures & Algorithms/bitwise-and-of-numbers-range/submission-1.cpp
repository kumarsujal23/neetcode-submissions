class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=left;
        int c=0;
        for(int i=0;i<32;i++)
        {
            if(left<=(1<<i) && right>=(1<<i))
            c++;
            if(c>1)
            return 0;
        }
        for(int i=left+1;i<=right;i++)
        {
            ans&=i;
        }
        return ans;
    }
};