class Solution {
public:
    vector<vector<int>> res;
    void solve(int i,vector<int> ans,vector<int>& cand,int sum,int target)
    {
        if(sum==target)
        {
            res.push_back(ans);
            return;
        }
        if(i>=cand.size()|| sum>target)
        return;
        for(int j=i;j<cand.size();j++)
        {
            if(sum+cand[j]>target)
            return;
            ans.push_back(cand[j]);
            solve(j+1,ans,cand,sum+cand[j],target);
            ans.pop_back();
            while(j<cand.size()-1 && cand[j]==cand[j+1])
            j++;
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        solve(0,ans,candidates,0,target);
        return res;
    }
};
