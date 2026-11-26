class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int min1=INT_MAX;
        for(auto i:prices)
        {
            min1=min(min1,i);
            if(i>=min1)
            res=max(res,i-min1);
        }
        return res;
    }
};
