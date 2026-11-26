class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"|| num2=="0")
        return "0";
        vector<int> res(num1.size()+num2.size());
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i2=0;i2<num2.size();i2++)
        {
            for(int i1=0;i1<num1.size();i1++)
            {
                int d=(num1[i1]-'0')*(num2[i2]-'0');
                res[i1+i2]+=d;
                res[i1+i2+1]+=res[i1+i2]/10;
                res[i1+i2]=res[i1+i2]%10;
            }
        }
        int i=res.size()-1;
        while(i>=0 && res[i]==0)
        i--;
        string ans="";
        while(i>=0)
        ans+=to_string(res[i--]);
        return ans;
    }
};
