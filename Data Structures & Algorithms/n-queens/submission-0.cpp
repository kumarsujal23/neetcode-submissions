class Solution {
public:
    vector<vector<string>> res;
    unordered_map<int ,int> col;
    unordered_map<int,int> posdig;
    unordered_map<int,int> negdig;
    void solve(int r,vector<string> &board)
    {
        if(r>=board.size())
        {
            res.push_back(board);
            return;
        }
        for(int c=0;c<board.size();c++)
        {
            if(col.find(c)==col.end() && posdig.find(r+c)==posdig.end() && negdig.find(r-c)==negdig.end())
            {
                board[r][c]='Q';
                col[c]=1;
                posdig[r+c]=1;
                negdig[r-c]=1;
                solve(r+1,board);
                board[r][c]='.';
                col.erase(c);
                posdig.erase(r+c);
                negdig.erase(r-c);

            }
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(0,board);
        return res;
        
    }
};
