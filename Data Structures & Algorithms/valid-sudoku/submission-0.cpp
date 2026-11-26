class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> row,col;
        map<pair<int,int>,unordered_set<char>> buck;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                continue;
                pair<int,int> p={i/3,j/3};
                if(row[i].count(board[i][j]) ||col[j].count(board[i][j])||buck[p].count(board[i][j]) )
                {
                    return false;
                }
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                buck[p].insert(board[i][j]);

            }
        }
        return true;
        
    }
};
