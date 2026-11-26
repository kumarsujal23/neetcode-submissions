class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(),-1);
        vector<int> right(heights.size(),heights.size());
        stack<int> st;
        st.push(0);
        for(int i=1;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            if(!st.empty() && heights[st.top()]<heights[i])
            left[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        st.push(heights.size()-1);
        for(int i=heights.size()-2;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            if(!st.empty() && heights[st.top()]<heights[i])
            right[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<heights.size();i++)
        {
            int curr=heights[i]*(right[i]-left[i]-1);
            ans=max(curr,ans);
        }
        return ans;
    }
};
