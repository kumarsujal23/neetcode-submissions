class Node{
    public:
    vector<Node*> links;
    bool flag;
    Node()
    {
        flag=false;
        links.resize(26,nullptr);
    }
    bool charcheck(char ch)
    {
        if(links[ch-'a']!=nullptr)
        return true;
        else 
        return false;
    }
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root=new Node();
    }
    void insert(string word) {
        Node* r=root;
        for(int i=0;i<word.size();i++)
        {
            if(!(r->charcheck(word[i])))
            {
                r->links[word[i]-'a']=new Node();
            }
            
            r=r->links[word[i]-'a'];        
        }
        r->flag=true;
    }
    
    bool search(string word) {
        Node* r=root;
        for(int i=0;i<word.size();i++)
        {
            if((r->charcheck(word[i])))
            r=r->links[word[i]-'a'];
            else
            return false;
        }
        return r->flag;
    }
    
    bool startsWith(string prefix) {
        Node* r=root;
        for(int i=0;i<prefix.size();i++)
        {
            if((r->charcheck(prefix[i])))
            r=r->links[prefix[i]-'a'];
            else
            return false;
        }
        if(r!=nullptr || r->flag)
        return true;
    }
};
