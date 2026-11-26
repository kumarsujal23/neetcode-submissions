class Node{
    public:
        int val;
        int freq;
        int timestamp;
        Node(int v,int f,int t){
            val=v;
            freq=f;
            timestamp=t;
        }
};
class LFUCache {
public:
    int timestamp;
    unordered_map<int,Node*> cache;
    int cap;
    LFUCache(int capacity) {
        cap=capacity;
        timestamp=0;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end())
        return -1;
        timestamp++;
        cache[key]->freq++;
        cache[key]->timestamp=timestamp;
        return cache[key]->val;
    }
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            timestamp++;
            cache[key]->freq++;
            cache[key]->timestamp=timestamp;
            cache[key]->val=value;
            return;
        }
        if(cap>0)
        {
            timestamp++;
            cache[key]=new Node(value,1,timestamp);
            cap--;
            return;
        }
        int mintime=INT_MAX,minfreq=INT_MAX,lfukey=0;
        for(auto &[k,node]:cache)
        {
            if(node->freq<minfreq ||(node->freq==minfreq && node->timestamp<mintime))
            {
                minfreq=node->freq;
                mintime=node->timestamp;
                lfukey=k;
            }
        }
        delete cache[lfukey];
        cache.erase(lfukey);
        timestamp++;
        cache[key]=new Node(value,1,timestamp);
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */