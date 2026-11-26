class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans; 
        for(int i=0;i<=n;i++)
        {
            int a=0,b=i;
         while(b)
        {
            b&=(b-1);
            a++;
        }
        ans.push_back(a);
        }
        return ans;
    }
};
