class Node{
    public:
    vector<Node*> links;
    string word;
    Node()
    {
        word="";
        links.resize(26,nullptr);
    }
    bool charchecker(char ch)
    {
        if(links[ch-'a']!=nullptr)
        return true;
        else 
        return false;
    }
};
class Solution {
public:
    Node* root;
    void insert(string word)
    {
        Node* r=root;
        for(int i=0;i<word.size();i++)
        {
            if(!(r->charchecker(word[i])))
            r->links[word[i]-'a']=new Node();
            r=r->links[word[i]-'a'];
        }
        r->word=word;
    }
    void dfs(int r,int c,Node* node,vector<vector<char>>& board,vector<string> &ans)
    {
        if(board[r][c]=='#')
        return;
        char ch=board[r][c];
        if(node->links[ch-'a']==nullptr)
        return;
        node=node->links[ch-'a'];
        if(node->word!="")
        {
            ans.push_back(node->word);
            node->word="";
        }
        board[r][c]='#';
        int n=board.size(),m=board[0].size();
        if(r+1<n)
        dfs(r+1,c,node,board,ans);
        if(r-1>=0)
        dfs(r-1,c,node,board,ans);
        if(c+1<m)
        dfs(r,c+1,node,board,ans);
        if(c-1>=0)
        dfs(r,c-1,node,board,ans);
        board[r][c]=ch;

        return;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new Node();
        for(auto it:words)
        insert(it);

        vector<string> ans;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                dfs(i,j,root,board,ans);
            }
        }
        return ans;
    }
};
