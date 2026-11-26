class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry=0;
        string res="";
        for(int i=0;i<max(a.size(),b.size());i++)
        {
            int da=(i<a.size())?(a[i]-'0'):0;
            int db=(i<b.size())?(b[i]-'0'):0;
            int sum=da+db+carry;
            char c=char(sum%2+'0');
            res=res+c;
            carry=sum/2;
        }
        if(carry)
        res=res+'1';
        reverse(res.begin(),res.end());
        return res;
    }
};