class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        st.push({temp[0],0});
        vector<int> res(temp.size(),0);
        for(int i=1;i<temp.size();i++)
        {
            pair<int,int> p={temp[i],i};
            while(!st.empty() && st.top().first<p.first)
            {
                pair<int,int> t=st.top();
                res[t.second]=p.second-t.second;
                st.pop();
            }
            st.push(p);
        }
        return res;
    }
};
