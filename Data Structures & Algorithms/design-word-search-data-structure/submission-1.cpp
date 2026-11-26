class Node{
    public:
    vector<Node*> links;
    bool flag;
    Node()
    {
        links.resize(26,nullptr);
        flag=false;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    bool solve(Node* root,int i,string &word)
    {
        if(i>=word.size())
        {
            return root->flag;
        }
        if(word[i]!='.')
        {
            if(root->links[word[i]-'a']!=nullptr)
            return solve(root->links[word[i]-'a'],i+1,word);
            else 
            return false;
        }
        else
        {
            for(int j=0;j<26;j++)
            {
                if(root->links[j]!=nullptr)
                {
                    if(solve(root->links[j],i+1,word))
                    return true;
                }
            }
        }
        return false;
    }
    void addWord(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->links[word[i]-'a']==nullptr)
            temp->links[word[i]-'a']=new Node();
            temp=temp->links[word[i]-'a'];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        return solve(root,0,word);
    }
};
