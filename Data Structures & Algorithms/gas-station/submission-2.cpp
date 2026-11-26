class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int totgas=0,totcost=0,n=gas.size();
     for(int i=0;i<n;i++)
     {
        totgas+=gas[i];
        totcost+=cost[i];
     }
     if(totgas<totcost)
     return -1;
     int start=0,sum=0;
     for(int i=0;i<n-1;i++)
     {
        sum+=gas[i];
        sum-=cost[i];
        if(sum<0)
        {
            start=i+1;
            sum=0;
        }

     }
     return start;

    }
};
