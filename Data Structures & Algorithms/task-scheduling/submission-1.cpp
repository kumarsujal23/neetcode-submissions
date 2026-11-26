class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto it:tasks)
        mp[it]++;
        int m=INT_MIN;
        for(auto it:mp)
        m=max(m,it.second);
        int c=0;
        for(auto it:mp)
        {
            if(it.second==m)
            c++;
        }
        if(mp.size()>n)
        return tasks.size();
        else
        return m+(m-1)*n+c-1;
    }
};
