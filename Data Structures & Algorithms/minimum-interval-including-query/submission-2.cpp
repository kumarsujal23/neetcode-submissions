class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<vector<int>> events;
        for(int i=0;i<intervals.size();i++)
        {
            int len=intervals[i][1]-intervals[i][0]+1;
            events.push_back({intervals[i][0],0,len,i});//starting interval event
            events.push_back({intervals[i][1],2,len,i});//closing interval event
        }
        for(int i=0;i<queries.size();i++)
        {
            events.push_back({queries[i],1,i});
        }
        sort(events.begin(),events.end(),[](auto &a,auto &b){
            return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
        });
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //storing [size,indx]
        vector<int> ans(queries.size(),-1);
        vector<bool> inactive(intervals.size(),false);
        for(auto it:events)
        {
            if(it[1]==0)
            pq.push({it[2],it[3]});
            else if(it[1]==2)
            inactive[it[3]]=true;
            else
            {
                int qindx=it[2];
                int q=it[0];
                while(!pq.empty() && inactive[pq.top().second])
                pq.pop();
                if(!pq.empty())
                ans[qindx]=pq.top().first;
            }
        }
        return ans;
    }
};
