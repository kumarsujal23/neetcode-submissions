class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> maxcapital;
        priority_queue<int> maxprofit;
        for(int i=0;i<capital.size();i++)
        {
            maxcapital.push({capital[i],profits[i]});
        }
        for(int i=0;i<k;i++)
        {
            while(!maxcapital.empty() && maxcapital.top().first<=w)
            {
                maxprofit.push(maxcapital.top().second);
                maxcapital.pop();
            }
            if(maxprofit.empty())
            break;
            w+=maxprofit.top();
            maxprofit.pop();
        }
        return w;
    }
};