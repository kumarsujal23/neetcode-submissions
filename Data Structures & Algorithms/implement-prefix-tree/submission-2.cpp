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
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->links[word[i]-'a']==nullptr)
            {
                temp->links[word[i]-'a']=new Node();
            }
            temp=temp->links[word[i]-'a'];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->links[word[i]-'a'])
            temp=temp->links[word[i]-'a'];
            else
            return false;
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(temp->links[prefix[i]-'a'])
            temp=temp->links[prefix[i]-'a'];
            else
            return false;
        }
        return temp!=nullptr;
    }
};
