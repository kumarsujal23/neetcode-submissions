class Solution {
public:
    int solve(int a,int b,string op)
    {
        if(op=="+")
        return a+b;
        else if(op=="-")
        return a-b;
        else if(op=="*")
        return a*b;
        else
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1)
        return stoi(tokens[0]);
        int res=0;
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            string ch=tokens[i];
            if(ch=="+" || ch=="-" || ch=="*" || ch=="/")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                res=solve(b,a,ch);
                st.push(res);

            }
            else
            st.push(stoi(ch));
        }
        return res;

    }
};
