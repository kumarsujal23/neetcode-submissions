class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board)
    {
        board[r][c]='T';
        int n=board.size(),m=board[0].size();
        if(r<n-1 && board[r+1][c]=='O')
        dfs(r+1,c,board);
        if(r>0 && board[r-1][c]=='O')
        dfs(r-1,c,board);
        if(c<m-1 && board[r][c+1]=='O')
        dfs(r,c+1,board);
        if(c>0 && board[r][c-1]=='O')
        dfs(r,c-1,board);
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++)
        {
            if(board[i][0]=='O')
                dfs(i,0,board);
            if(board[i][col-1]=='O')
                dfs(i,col-1,board);
        }
        for(int i=0;i<col;i++)
        {
            if(board[0][i]=='O')
                dfs(0,i,board);
            if(board[row-1][i]=='O')
                dfs(row-1,i,board);
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='O')
                board[i][j]='X';
                else if(board[i][j]=='T')
                board[i][j]='O';
            }
        }
    }
};
