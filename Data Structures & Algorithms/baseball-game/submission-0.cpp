class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();i++)
        {
            string ch=operations[i];
            if(ch=="+")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.push(a);
                st.push(a+b);
            }
            else if(ch=="C")
            {
                st.pop();
            }
            else if(ch=="D")
            {
                st.push(st.top()*2);
            }
            else
            {
                st.push(stoi(ch));
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};