/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> mp;
        for(auto it:intervals)
        {
            mp[it.start]++;
            mp[it.end]--;
        }
        int res=0,best=0;
        for(auto it:mp)
        {
            res+=it.second;
            best=max(res,best);
        }
        return best;
    }
};
