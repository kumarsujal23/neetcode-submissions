class Node{
    public:
        vector<Node*> links;
        bool isword;
        Node()
        {
            links.resize(26,nullptr);
            isword=false;
        }
};
class Solution {
public:
    Node* root;
    void addword(string word)
    {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->links[word[i]-'a']==nullptr)
            temp->links[word[i]-'a']=new Node();
            temp=temp->links[word[i]-'a'];
        }
        temp->isword=true;
    }
    int solve(int i,string &s,vector<int> &dp)
    {
        if(i==s.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int res=1+solve(i+1,s,dp);
        Node* temp=root;
        for(int j=i;j<s.size();j++)
        {
            if(temp->links[s[j]-'a']==nullptr)
            break;
            temp=temp->links[s[j]-'a'];
            if(temp->isword)
            res=min(res,solve(j+1,s,dp));
        }
        return dp[i]=res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        root=new Node();
        for(auto it:dictionary)
        addword(it);
        vector<int> dp(s.size(),-1);
        return solve(0,s,dp);
    }
};