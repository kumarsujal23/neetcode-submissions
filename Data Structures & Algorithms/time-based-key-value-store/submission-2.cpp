class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int l=0,r=mp[key].size()-1;
        string res="";
        while(l<=r)
        {
            int m=(l+r)/2;
            if(mp[key][m].first<=timestamp)
            {
                res=mp[key][m].second;
                l=m+1;
            }
            else
            r=m-1;
        }
        return res;
        
    }
};
