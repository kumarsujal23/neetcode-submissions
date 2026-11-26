class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size()!=t.size())
       return false;
       map<int,int> mp,mp2;
       for(int i=0;i<s.size();i++)
       {
        mp[s[i]]++;
        mp2[t[i]]++;
       }
       if(mp!=mp2)
       return false;
       else
        return true;
    }
};
