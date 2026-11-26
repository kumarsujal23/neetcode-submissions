class Solution {
public:
    int getmax(vector<int> &count,int repeated)
    {
        int indx=-1,maxcount=0;
        for(int i=0;i<3;i++)
        {
            if(repeated==i || count[i]==0)
            continue;
            if(maxcount<count[i])
            {
                maxcount=count[i];
                indx=i;
            }
        }
        return indx;
    }
    string longestDiverseString(int a, int b, int c) {
       vector<int> count={a,b,c};
       int repeated=-1;
       string res="";
       while(true)
       {
            int maxchar=getmax(count,repeated);
            if(maxchar==-1)
            break;
            res=res+char(maxchar+'a');
            count[maxchar]--;
            if(res.size()>1 && res.back()==res[res.size()-2])
            repeated=maxchar;
            else 
            repeated=-1;

       }
       return res;

    }
};