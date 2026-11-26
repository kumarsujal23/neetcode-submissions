class Node{
    public:
     int freq;
     int time;
     int val;
     Node()
     {
        freq=0;
        time=0;
        val=0;
     }
};
class LFUCache {
public:
    int cap;
    unordered_map<int,Node*> mp;
    int time;
    LFUCache(int capacity) {
        time=0;
        cap=capacity;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            time++;
            mp[key]->freq++;
            mp[key]->time=time;
            return mp[key]->val;
        }
        return -1;
    }
    void put(int key, int value) {
       if(mp.find(key)!=mp.end())
       {
            time++;
            mp[key]->freq++;
            mp[key]->time=time;
            mp[key]->val=value;
       }
       else
       {
        time++;
        if(mp.size()<cap)
        {
            mp[key]=new Node();
            mp[key]->freq++;
            mp[key]->time=time;
            mp[key]->val=value;
        }
        else
        {
            int mintime=INT_MAX;
            int lfukey=-1;
            int minfreq=INT_MAX;
            for(auto &[k,node]:mp)
            {
                if(node->freq<minfreq || (minfreq==node->freq && node->time<mintime))
                {
                    minfreq=node->freq;
                    mintime=node->time;
                    lfukey=k;
                }
            }
            mp.erase(lfukey);
            mp[key]=new Node();
            mp[key]->freq++;
            mp[key]->time=time;
            mp[key]->val=value;
        }
       }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */