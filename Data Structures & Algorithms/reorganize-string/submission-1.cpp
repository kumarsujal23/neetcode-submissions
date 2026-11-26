class Solution {
public:
    int getmax(vector<int> &v,int rep)
    {
        int maxi=-1,maxc=0;
        for(int i=0;i<v.size();i++)
        {
            if(rep==i || v[i]==0)
            continue;
            if(maxc<v[i])
            {
                maxc=v[i];
                maxi=i;
            }
        }
        return maxi;
    }
    string reorganizeString(string s) {
        vector<int> v(26);
        for(auto ch:s)
        {
            v[ch-'a']++;
        }
        string res="";
        int repeated=-1;
        while(true)
        {
            int val=getmax(v,repeated);
            if(val==-1)
            break;
            res+=char(val+'a');
            v[val]--;
            repeated=val;
           
        }
        if(res.size()!=s.size())
        return "";
        else
        return res;

    }
};