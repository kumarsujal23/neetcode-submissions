class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001,0);
        for(int i=0;i<trips.size();i++)
        {
            auto it=trips[i];
            v[it[1]]+=it[0];
            v[it[2]]+=-1*it[0];
        }
        int sum=0;
        for(int i=0;i<=1000;i++)
        {
            if(sum+v[i]>capacity)
            return false;
            sum+=v[i];
        }
        return true;
    }
};