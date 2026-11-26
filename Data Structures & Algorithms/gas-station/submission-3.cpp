class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas=0,needed=0;
        for(int i=0;i<gas.size();i++)
        {
            totgas+=gas[i];
            needed+=cost[i];
        }
        if(needed>totgas)
        return -1;
        int res=0,sum=0;
        for(int i=0;i<gas.size()-1;i++)
        {
            sum+=gas[i];
            sum-=cost[i];
            if(sum<0)
            {
                res=i+1;
                sum=0;
            }
        }
        return res;
    }
};
