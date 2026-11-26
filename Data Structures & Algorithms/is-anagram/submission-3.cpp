class Solution {
public:
    bool isAnagram(string s, string t) {
    //    sort(s.begin(),s.end());
    //    sort(t.begin(),t.end());
    //    if(s==t)
    //    return true;
    //    else
    //    return false;
    map<char,int> mp;
    map<char,int>mp2;
    int n1=s.size();
    int n2=t.size();
    if(n1!=n2)
    return false;
    for(int i=0;i<n1;i++)
    {
        mp[s[i]]++;
        mp2[t[i]]++;
    }
    if(mp==mp2)
    return true;
    else
    return false;

    }
};
