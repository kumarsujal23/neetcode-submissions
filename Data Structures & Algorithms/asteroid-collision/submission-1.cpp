class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto a:asteroids)
        {
            bool flag=true;
            while(!st.empty() && st.top()>0 && a<0)
            {
                flag=false;
                if(abs(st.top())==abs(a))
                {
                    st.pop();
                    break;
                }
                else if(abs(st.top())>abs(a))
                break;
                else
                {
                    st.pop();
                    flag=true;
                }
            }
            if(flag)
            st.push(a);
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};