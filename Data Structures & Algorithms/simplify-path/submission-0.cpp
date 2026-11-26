class Solution {
public:
    string simplifyPath(string path) {
        string curr="";
        vector<string> st;
        path+='/';
        for(auto c:path)
        {
            if(c=='/')
            {
                if(curr=="..")
                {
                    if(!st.empty())
                    st.pop_back();
                }
                else
                {
                    if(!curr.empty() && curr!=".")
                    st.push_back(curr);
                }
                curr="";
            }
            else
            curr+=c;
        }
        string result="/";
        for(int i=0;i<st.size();i++)
        {
            if(i>0)
            result+="/";
            result+=st[i];
        }
        return result;
    }
};