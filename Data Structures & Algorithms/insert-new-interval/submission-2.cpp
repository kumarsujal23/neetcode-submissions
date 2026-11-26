class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++)
        {
            int l=intervals[i-1][0];
            int rmax=intervals[i-1][1];
            while(i<n && rmax>=intervals[i][0])
            {
                rmax=max(rmax,intervals[i][1]);
                i++;
            }
            int r=rmax;
            ans.push_back({l,r});
        }
        return ans;
    }
};
