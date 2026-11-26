class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row_wise
        for(auto it:board)
        {
            map<char,int> mp;
            for(auto ch:it)
            {
                if(ch=='.')
                continue;
                if(mp.find(ch)!=mp.end())
                return false;
                mp[ch]++;
            }
        }
        // columns_wise
        vector<vector<int>> v(9,vector<int>(10,0));
        for(auto it:board)
        {
            for(int i=0;i<it.size();i++)
            {
                if(it[i]=='.')
                continue;
                if(v[i][it[i]-'0']!=0)
                return false;
                else
                v[i][it[i]-'0']++;
            }
        }
        //box_wise
        vector<vector<map<int,int>>> box(3,vector<map<int,int>>(3));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int r=i/3;
                int c=j/3;
                char ch=board[i][j];
                if(ch=='.')
                continue;
                if(box[r][c].find(ch-'0')!=box[r][c].end())
                return false;
                else
                box[r][c][ch-'0']++;
            }

        }
        return true;
        
    }
};
