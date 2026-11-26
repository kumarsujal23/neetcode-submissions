class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(int i=0;i<strs.size();i++)
        {
            s=s+strs[i]+'|';
        }
        return s;

    }

    vector<string> decode(string s) {
        vector<string> ans;
        string w="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='|')
            w+=s[i];
            else
            {
                ans.push_back(w);
                w="";
            }
        }
        return ans;
    }
};
