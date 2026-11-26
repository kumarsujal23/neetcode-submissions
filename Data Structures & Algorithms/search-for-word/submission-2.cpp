class Solution {
public:
    bool solve(int r,int c,string s,string word,vector<vector<char>>& b,vector<vector<int>> &vis)
    {
        vis[r][c]=1;
        
        s.push_back(b[r][c]);
        int n=b.size(),m=b[0].size();
        if(s==word)
        return true;
        if(s==word.substr(0,s.size()))
        {
            if(r<n-1 && !vis[r+1][c] && solve(r+1,c,s,word,b,vis) )
            return true;
            if(r>0 && !vis[r-1][c] && solve(r-1,c,s,word,b,vis))
            return true;
            if(c<m-1 && !vis[r][c+1] && solve(r,c+1,s,word,b,vis))
            return true;
            if(c>0 &&  !vis[r][c-1] && solve(r,c-1,s,word,b,vis))
            return true;
        }
        
        s.pop_back();
        vis[r][c]=0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(solve(i,j,"",word,board,vis))
                return true;
            }
        } 
        return false;
    }
};
