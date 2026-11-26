class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st2.push(x);
    }
    
    int pop() {
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        int x=st1.top();
        st1.pop();
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        return x;
    }
    
    int peek() {
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        int x=st1.top();
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        return x;
    }
    
    bool empty() {
        return st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */