class FreqStack {
public:
    // unordered_map<int,int> cnt;
    // priority_queue<vector<int>> pq;
    // int index;
    vector<stack<int>> st;
    unordered_map<int,int> freq;
    FreqStack() {
        // index=0;
    }
    void push(int val) {
        // cnt[val]++;
        // pq.push({cnt[val],index++,val});
        freq[val]++;
        while(st.size()<=freq[val])
        st.push_back(stack<int>());
        st[freq[val]].push(val);
    }
    int pop() {
    //    auto it=pq.top();
    //    pq.pop();
    //    int res=it[2];
    //    cnt[res]--;
    //     return res;
    int res=st[st.size()-1].top();
    freq[res]--;
    st[st.size()-1].pop();
    if(st[st.size()-1].empty())
    st.pop_back();
    return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */