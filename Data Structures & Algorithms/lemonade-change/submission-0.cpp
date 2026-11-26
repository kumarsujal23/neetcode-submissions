class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int curr=bills[0];
        if(curr>5)
        return false;
        vector<int> v(3);
        for(int i=0;i<bills.size();i++)
        {
            int pays=bills[i];
            if(pays==5)
            v[0]++;
            else if(pays==10)
            {
                if(!v[0])
                return false;
                else
                {
                    v[0]--;
                    v[1]++;
                }

            }
            else
            {
                if(v[1]>0 && v[0]>0)
                {
                    v[1]--;
                    v[0]--;
                    v[2]++;
                }
                else if(v[0]>=3)
                {
                    v[0]-=3;
                    v[2]++;
                }
                else 
                return false;
            }
        }
        return true;
    }
};