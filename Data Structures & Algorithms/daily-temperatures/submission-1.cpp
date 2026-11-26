class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int,int>> st;
        st.push({temperatures[0],0});
        for(int i=1;i<temperatures.size();i++)
        {
            pair<int,int> p={temperatures[i],i};
            while(!st.empty() && st.top().first<temperatures[i])
            {
                res[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.push(p);
        }
        return res;
    }
};
