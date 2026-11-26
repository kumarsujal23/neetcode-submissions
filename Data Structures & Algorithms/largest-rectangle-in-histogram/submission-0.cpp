class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right(heights.size(),heights.size());
        vector<int> left(heights.size(),-1);
        stack<int> st;
        st.push(heights.size()-1);
        for(int i=heights.size()-1-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            st.pop();
            if(!st.empty() && heights[st.top()]<=heights[i] )
            right[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        st.push(0);
        for(int i=1;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            if(!st.empty() && heights[st.top()]<heights[i] )
            left[i]=st.top();
            st.push(i);
        }
        int area=0;
        for(int i=0;i<heights.size();i++)
        {
            int currarea=heights[i]*(right[i]-left[i]-1);
            area=max(area,currarea);
        }
        return area;
    }
};
