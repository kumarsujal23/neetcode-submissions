class Solution {
public:
    int candy(vector<int>& ratings) {
      vector<int> ans(ratings.size(),1);
      for(int i=0;i<ans.size()-1;i++)
      {
        if(ratings[i]<=ratings[i+1])
        {
            if(ans[i+1]<=ans[i] && ratings[i]!=ratings[i+1])
            ans[i+1]=ans[i]+1;
        }
        else
        {
            if(ans[i+1]>=ans[i])
            ans[i]=ans[i+1]+1;
        }
      }  
      for(int i=ans.size()-2;i>=0;i--)
      {
        if(ratings[i]<=ratings[i+1])
        {
            if(ans[i+1]<=ans[i] && ratings[i]!=ratings[i+1])
            ans[i+1]=ans[i]+1;
        }
        else
        {
            if(ans[i+1]>=ans[i])
            ans[i]=ans[i+1]+1;
        }
      }
      int res=0;
      for(auto it:ans)
      res+=it;
      return res;
    }
};