class Solution {
public:
    string decodeString(string s) {
        vector<string> st;
        vector<int> num;
        string curr="";
        int k=0;
        for(auto c:s)
        {
            if(isdigit(c))
            {
                k=k*10+(c-'0');
            }
            else if(c=='[')
            {
                num.push_back(k);
                st.push_back(curr);
                curr="";
                k=0;
            }
            else if(c==']')
            {
                string temp=curr;
                curr=st.back();
                st.pop_back();
                int count=num.back();
                num.pop_back();
                for(int i=0;i<count;i++)
                curr+=temp;
            }
            else
            curr+=c;
        }
        return curr;
    }
};