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
    int solve(int i,string &s)
    {
        if(i==s.size())
        return 0;
        int res=1+solve(i+1,s);
        Node* temp=root;
        for(int j=i;j<s.size();j++)
        {
            if(temp->links[s[j]-'a']==nullptr)
            break;
            temp=temp->links[s[j]-'a'];
            if(temp->isword)
            res=min(res,solve(j+1,s));
        }
        return res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        root=new Node();
        for(auto it:dictionary)
        addword(it);
        return solve(0,s);
    }
};