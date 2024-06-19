#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs (vector<vector<int>>& grid, int x, int y, int row, int col) {
        if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == 0) {
            return 0;
        }
        int temp = grid[x][y];
        grid[x][y] = 0;
        int left = dfs(grid, x, y - 1, row, col);
        int top = dfs(grid, x - 1, y, row, col);
        int right = dfs(grid, x, y + 1, row, col);
        int bottom = dfs(grid, x + 1, y, row, col);
        grid[x][y] = temp;
        return max({left, top, right, bottom}) + grid[x][y];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int max_coins = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] > 0) {
                    max_coins = max (max_coins, dfs(grid, i, j, row, col));
                }
            }
        }
        return max_coins;
    }
};


class Solution {
public:
    vector<int> roww = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};
    int collect_gold (int x, int y, int row, int col, vector<vector<int>>& grid) {
        if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0) {
            return 0;
        }
        int curr = grid[x][y];
        grid[x][y] = 0;
        int curr_max = curr;
        for (int i = 0; i < 4; ++i) {
            int new_x = x + roww[i];
            int new_y = y + coll[i];
            curr_max = max(curr_max, curr + collect_gold(new_x, new_y, row, col, grid));
        }
        grid[x][y] = curr;
        return curr_max;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int max_gold = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] > 0) {
                    max_gold = max(max_gold, collect_gold(i, j, row, col, grid));
                }
            }
        }
        return max_gold;
    }
};