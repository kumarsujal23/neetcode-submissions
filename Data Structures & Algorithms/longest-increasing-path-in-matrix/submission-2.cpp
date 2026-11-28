
        #include <algorithm>
        #include <vector>
        using namespace std;
        class Solution {
                int m, n;
                    vector<vector<int>> memo;
                int dx[4] = {-1, 1, 0, 0};
                int dy[4] = {0, 0, -1, 1};
            int dfs(int x, int y, vector<vector<int>>& a) {
                    int &r = memo[x][y];
                        if (r) return r;
                            r = 1;
                            for (int k = 0; k < 4; ++k) {
                                int nx = x + dx[k], ny = y + dy[k];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] > a[x][y]) {
                                                r = max(r, 1 + dfs(nx, ny, a));
                            }
                            }
                                    return r;
            }
            public:
                int longestIncreasingPath(vector<vector<int>>& matrix) {
                            if (matrix.empty() || matrix[0].empty()) return 0;
                m = matrix.size();
            n = matrix[0].size();
            memo.assign(m, vector<int>(n, 0));
            int ans = 0;
            for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        ans = max(ans, dfs(i, j, matrix));
                    }
            }
            return ans;
                }
        };
    
