class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> used;
        priority_queue<int,vector<int>,greater<int>> avail;
        vector<int> room(n);
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++)
        {
            avail.push(i);
        }
        for(int i=0;i<meetings.size();i++)
        {
            int start=meetings[i][0];
            int end=meetings[i][1];
            while(!used.empty() && used.top().first<=start)
            {
                auto top=used.top();
                used.pop();
                avail.push(top.second);
            }
            if(avail.empty())
            {
                auto top=used.top();
                used.pop();
                top.first+=(end-start);
                room[top.second]++;
                used.push(top);
            }
            else 
            {
                int minroom=avail.top();
                avail.pop();
                room[minroom]++;
                used.push({end,minroom});
            }
        }
        int maxind=0;
        for(int i=0;i<n;i++)
        {
            if(room[i]>room[maxind])
            maxind=i;
        }
        return maxind;
    }
};