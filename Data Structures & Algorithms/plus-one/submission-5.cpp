class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]<9)
        {
            digits[n-1]++;
            return digits;
        }
        int d=0;
        for(int i=0;i<n;i++)
        {
            if(digits[i]==9)
            d++;
        }
        vector<int> res;
        if(d==n)
        {
            res.push_back(1);
            for(int i=0;i<n;i++)
            res.push_back(0);
            return res;
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                if(digits[i]==9)
                digits[i]=0;
                else 
                {
                    digits[i]++;
                    break;
                }
            }
            return digits;
        }
    }
};
