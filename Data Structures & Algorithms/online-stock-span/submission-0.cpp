class StockSpanner {
public:
    stack<int> st1;
    stack<int> st2;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;
        while(!st1.empty())
        {
            int p=st1.top();
            if(p<=price)
            {
                ans++;
                st2.push(st1.top());
                st1.pop();
            }
            else
            break;
        }
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */