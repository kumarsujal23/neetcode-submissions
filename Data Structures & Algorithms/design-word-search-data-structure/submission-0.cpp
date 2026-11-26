class Node{
    public:
    vector<Node*> links;
    bool flag;
    Node(){
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
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* r=root;
        for(int i=0;i<word.size();i++)
        {
            if(!(r->charcheck(word[i])))
            r->links[word[i]-'a']=new Node();
            r=r->links[word[i]-'a'];
        }
        r->flag=true;
    }
    bool dfs(string &word,Node* root,int i)
    {
        if(i==word.size())
        return root->flag;
        if(word[i]!='.')
        {
            if(root->charcheck(word[i]))
            return dfs(word,root->links[word[i]-'a'],i+1);
            else 
            return false;
        }
        else
        {
            for(int j=0;j<26;j++)
            {
                if(root->links[j]!=nullptr)
                {
                    if(dfs(word,root->links[j],i+1))
                    return true;
                }

            }
        }
        return false;
    }
    bool search(string word) {
        return dfs(word,root,0);
    }
};
