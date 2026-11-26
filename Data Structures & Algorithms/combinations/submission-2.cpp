class Solution {
public:
    vector<vector<int>> res;
    void solve(int i,vector<int> &ans,int k,int &n)
    {
        
        if(k==0)
        {
            res.push_back(ans);
            return;
        }
        if(i>n)
        return ;
        ans.push_back(i);
        solve(i+1,ans,k-1,n);
        ans.pop_back();
        solve(i+1,ans,k,n);
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        solve(1,ans,k,n);
        return res;
    }
};