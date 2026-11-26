class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            open.push(i);
            else if(s[i]=='*')
            star.push(i);
            else
            {
                if(open.empty() && star.empty())
                return false;
                else if(open.empty() )
                star.pop();
                else if(!open.empty())
                open.pop();
            }
        }
        while(!open.empty() && !star.empty())
        {
            if(open.top()>star.top())
            return false;
            open.pop();
            star.pop();
        }
        return open.empty();

    }
};
