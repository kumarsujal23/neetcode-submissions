class FreqStack {
public:
    unordered_map<int,int> cnt;
    priority_queue<vector<int>> pq;
    int index;
    FreqStack() {
        index=0;
    }
    
    void push(int val) {
        cnt[val]++;
        pq.push({cnt[val],index++,val});
    }
    
    int pop() {
       auto it=pq.top();
       pq.pop();
       int res=it[2];
       cnt[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */