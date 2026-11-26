class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto str:strs)
        s+=to_string(str.size())+",";
        s+="#";
        for(auto str:strs)
        s+=str;
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if(s.empty())
        return {};
        vector<int> sizes;
        int a=0;
        string ch="";
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]=='#')
            {
                a=i;
                break;
            }
            if(s[i]==',')
            {
                int num=stoi(ch);
                ch="";
                sizes.push_back(num);
            }
            else
            ch+=s[i];
        }
        int i=a+1;
        for(auto n1:sizes)
        {
            ans.push_back(s.substr(i,n1));
            i+=n1;
        }
        return ans;

    }
};
