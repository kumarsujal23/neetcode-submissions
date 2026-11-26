class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp1,mp2;
        if(s1.size()>s2.size())
        return false;
        for(auto it:s1)
        {
            mp1[it]++;
        }
        for(int i=0;i<s1.size();i++)
        {
            mp2[s2[i]]++;
        }
        if(mp1==mp2)
        return true;
        int r=s1.size()-1,l=0;
        while(r<s2.size())
        {

            if(mp1==mp2)
            return true;
            else
            {
                mp2[s2[l]]--;
                if(mp2[s2[l]]==0)
                mp2.erase(s2[l]);
                l++;
                r++;
                if(r<s2.size())
                mp2[s2[r]]++;
            }
        }
        return false;
    }
};
