class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,double>> st;
        vector<pair<int,double>> v;
        for(int i=0;i<speed.size();i++)
        {
            pair<int,double> p={position[i],((double)(target-position[i]))/speed[i]};
            v.push_back(p);
        }
        sort(v.rbegin(),v.rend());
        st.push(v[0]);
        for(int i=1;i<speed.size();i++)
        {
            pair<int,double> p=st.top();
            if(p.second>=v[i].second)
            {
                st.pop();
                v[i].second=p.second;
                st.push(v[i]);
            }
            else
            st.push(v[i]);
        }
        return st.size();
        
    }
};
