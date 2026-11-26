class Solution {
public:
            int count = 0;
                void dfs(int row, int cols, int diag1, int diag2, int n) {
                            if (row == n) {
                count++;
                    return;
                            }
                    int avail = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        while (avail) {
                        int p = avail & -avail;
                                    avail -= p;
                dfs(row + 1, cols | p, (diag1 | p) << 1, (diag2 | p) >> 1, n);
        }
                }
                    int totalNQueens(int n) {
                                count = 0;
                dfs(0, 0, 0, 0, n);
            return count;
                    }
      };
