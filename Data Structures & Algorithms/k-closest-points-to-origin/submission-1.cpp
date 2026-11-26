class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            x=x*x;
            y=y*y;
            double sum=x+y;
            sum =sqrt(sum);
            pq.push({sum,i});
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++)
        {
            pair<double,int> f=pq.top();
            pq.pop();
            res.push_back(points[f.second]);
        }
        return res;
    }
};
