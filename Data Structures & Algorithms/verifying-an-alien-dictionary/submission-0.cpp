class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char> mp;
        char ch='a';
        for(auto c:order)
        {
            mp[c]=ch;
            ch++;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            string s1=words[i];
            string s2=words[i+1];
            int j=0;
            while(j<min(s1.size(),s2.size()) && s1[j]==s2[j])
            {
                j++;
            }
            if(j<min(s1.size(),s2.size()) && mp[s1[j]]<mp[s2[j]])
            continue;
            else if(j==min(s1.size(),s2.size()))
            {
                if(s1.size()>s2.size())
                return false;
            }
            else 
            return false;
        }
        return true;
    }
};