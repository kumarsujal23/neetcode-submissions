class Solution {
public:
    unordered_map<int,int> col;
    unordered_map<int,int> posdiag;
    unordered_map<int,int> negdiag;
    int res;
    void solve(int r,int n)
    {
        if(r==n)
        {
            res++;
            return;
        }
        for(int c=0;c<n;c++)
        {
            if(col.find(c)==col.end() && posdiag.find(r+c)==posdiag.end() && negdiag.find(r-c)==negdiag.end())
            {
                col[c]++;
                posdiag[r+c]++;
                negdiag[r-c]++;
                solve(r+1,n);
                col.erase(c);
                posdiag.erase(r+c);
                negdiag.erase(r-c);
            }
        }
        return;
    }
    int totalNQueens(int n) {
       res=0;
       solve(0,n);
       return res;
    }
};