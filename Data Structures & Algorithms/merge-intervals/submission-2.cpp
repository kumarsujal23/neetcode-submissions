class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int n=intervals.size();
        for(int i=1;i<=n;i++)
        {
            int l=intervals[i-1][0];
            int rmax=intervals[i-1][1];
            while(i<n && rmax>=intervals[i][0])
            {
                rmax=max(rmax,intervals[i][1]);
                i++;
            }
            res.push_back({l,rmax});
        }
        return res;

    }
};
