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
        int maxi=0;
        for(auto it:intervals)
        {
            maxi=max(maxi,it.end);
        }
        vector<int> meet(maxi+1);
        for(auto it:intervals)
        {
            meet[it.start]+=1;
            meet[it.end]-=1;
        }
        int best=0,res=0;
        for(int i=0;i<meet.size();i++)
        {
            res+=meet[i];
            best=max(res,best);
        }
        return best;
    }
};
