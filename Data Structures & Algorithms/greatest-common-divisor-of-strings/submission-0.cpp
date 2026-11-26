class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size()>str2.size())
        return gcdOfStrings(str2,str1);
        string res="";
        for(int i=0;i<str1.size();i++)
        {
            string check=str1.substr(0,i+1);
            bool flag1=true;
            int j=0;
            while(j<str1.size())
            {
                if(check==str1.substr(j,check.size()))
                j+=check.size();
                else
                {
                    flag1=false;
                    break;
                }
            }
            
            bool flag2=true;
            j=0;
            while(j<str2.size())
            {
                if(check==str2.substr(j,check.size()))
                j+=check.size();
                else
                {
                    flag2=false;
                    break;
                }
            }
            if(flag1 && flag2)
            {
                res=check;
            }
        }
        return res;
    }
};