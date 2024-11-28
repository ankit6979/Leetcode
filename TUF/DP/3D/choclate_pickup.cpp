class Solution {
  public:
    int solverHelper(int r1x, int r1y, int r2x, int r2y, int rows, int cols, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(r1y < 0 || r2y < 0 || r1y >= cols || r2y >= cols || r1y == r2y) {
            return INT_MIN;
        }
        else if(r1x == rows - 1) {
            return grid[r1x][r1y] + grid[r2x][r2y];
        }
        else if(dp[r1x][r1y][r2y] != -1) return dp[r1x][r1y][r2y];
        else {
            int max_chocolates = INT_MIN;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    max_chocolates = max(
                        max_chocolates,
                        solverHelper(r1x + 1, r1y + i, r2x + 1, r2y + j, rows, cols, grid, dp)
                    );
                }
            }
            return dp[r1x][r1y][r2y] = grid[r1x][r1y] + grid[r2x][r2y] + max_chocolates;
        }
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        
        return solverHelper(0, 0, 0, cols - 1, rows, cols, grid, dp);
        
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols)));
        
        for(int j1 = 0; j1 < cols; ++j1) {
            for(int j2 = 0; j2 < cols; ++j2) {
                if (j1 == j2) dp[rows - 1][j1][j2] = grid[rows - 1][j1];
                else {
                    dp[rows - 1][j1][j2] = grid[rows - 1][j1] + grid[rows - 1][j2];
                }
            }
        }
        
        for(int i = rows - 2; i >= 0; --i) {
            for(int j1 = cols - 1; j1 >= 0; --j1) {
                for(int j2 = cols - 1; j2 >= 0; --j2) {
                    int max_chocolates = INT_MIN;
                    for (int j = -1; j <= 1; ++j) {
                        for (int k = -1; k <= 1; ++k) {
                            int curr_chocolate = INT_MIN;
                            if(j1 + j >= 0 && j1 + j < cols && j2 + k >= 0 && j2 + k < cols) {
                                curr_chocolate = dp[i + 1][j1 + j][j2 + k];
                            }
                            max_chocolates = max(
                                max_chocolates,
                                curr_chocolate
                            );
                        }
                    }
                    
                    if(j1 == j2) {
                        dp[i][j1][j2] = grid[i][j1] + max_chocolates;
                    }
                    else {
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + max_chocolates;
                    }
                }
            }
        }
        
        return dp[0][0][cols - 1];
    }
};