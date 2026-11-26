class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size()>a.size())
        return addBinary(b,a);
        int i=a.size()-1;;
        int j=b.size()-1;
        bool flag=false;
        string res="";
        while(j>=0)
        {
            if(a[i]=='1' && b[j]=='1' && !flag)
            {
                res='0'+res;
                flag=true;
            }
            else if(a[i]=='1' && b[j]=='1' && flag)
            {
                res='1'+res;
                flag=true;
            }
            else if((a[i]=='1'||b[j]=='1')&&!flag)
            {
                res='1'+res;
                flag=false;
            }
            else if((a[i]=='1'||b[j]=='1')&& flag)
            {
                res='0'+res;
                flag=true;
            }
            else if(flag)
            {
                res='1'+res;
                flag=false;
            }
            else
            {
                res='0'+res;
                flag=false;
            }
            j--;
            i--;
        }
        while(i>=0)
        {
            if(a[i]=='1' && flag)
            {
                res='0'+res;
                flag=true;
            }
            else if(a[i]=='1' && !flag)
            {
                res='1'+res;
                flag=false;
            }
            else if(flag)
            {
                res='1'+res;
                flag=false;
            }
            else 
            {
                res='0'+res;
                flag=false;
            }
            i--;
        }
        if(flag)
        res='1'+res;
        return res;

        
    }
};