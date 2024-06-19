#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[71][71][71];
    int recurse(int robX, int rob1Y, int rob2Y, int row, int col, vector<vector<int>>& grid){
        if(rob1Y>=col || rob2Y>=col || rob1Y<0 || rob2Y<0){
            return -1e8;
        }
        else if(robX==row-1){
            if(rob1Y==rob2Y){
                return grid[robX][rob1Y];
            }
            return grid[robX][rob1Y]+grid[robX][rob2Y];
        }
        else if(dp[robX][rob1Y][rob2Y] != -1){
            return dp[robX][rob1Y][rob2Y];
        }
        else{
            if(rob1Y==rob2Y){
                int path1 = recurse(robX+1, rob1Y-1, rob2Y-1, row, col, grid)+grid[robX][rob1Y];
                int path2 = recurse(robX+1, rob1Y-1, rob2Y, row, col, grid)+grid[robX][rob1Y];
                int path3 = recurse(robX+1, rob1Y-1, rob2Y+1, row, col, grid)+grid[robX][rob1Y];
                int path4 = recurse(robX+1, rob1Y, rob2Y-1, row, col, grid)+grid[robX][rob1Y];
                int path5 = recurse(robX+1, rob1Y, rob2Y, row, col, grid)+grid[robX][rob1Y];
                int path6 = recurse(robX+1, rob1Y, rob2Y+1, row, col, grid)+grid[robX][rob1Y];
                int path7 = recurse(robX+1, rob1Y+1, rob2Y-1, row, col, grid)+grid[robX][rob1Y];
                int path8 = recurse(robX+1, rob1Y+1, rob2Y, row, col, grid)+grid[robX][rob1Y];
                int path9 = recurse(robX+1, rob1Y+1, rob2Y+1, row, col, grid)+grid[robX][rob1Y];
                return dp[robX][rob1Y][rob2Y] = max({path1, path2, path3, path4, path5, path6, path7, path8, path9});
            }
            else{
                int path1 = recurse(robX+1, rob1Y-1, rob2Y-1, row, col, grid)+grid[robX][rob1Y]+grid[robX][rob2Y];
                int path2 = recurse(robX+1, rob1Y-1, rob2Y, row, col, grid)+grid[robX][rob1Y]+grid[robX][rob2Y];
                int path3 = recurse(robX+1, rob1Y-1, rob2Y+1, row, col, grid)+grid[robX][rob1Y]+grid[robX][rob2Y];
                int path4 = recurse(robX+1, rob1Y, rob2Y-1, row, col, grid)+grid[robX][rob1Y]+grid[robX][rob2Y];
                int path5 = recurse(robX+1, rob1Y, rob2Y, row, col, grid)+grid[robX][rob1Y]+grid[robX][rob2Y];
                int path6 = recurse(robX+1, rob1Y, rob2Y+1, row, col, grid)+grid[robX][rob1Y]+grid[robX][rob2Y];
                int path7 = recurse(robX+1, rob1Y+1, rob2Y-1, row, col, grid)+grid[robX][rob1Y]+grid[robX][rob2Y];
                int path8 = recurse(robX+1, rob1Y+1, rob2Y, row, col, grid)+grid[robX][rob1Y]+grid[robX][rob2Y];
                int path9 = recurse(robX+1, rob1Y+1, rob2Y+1, row, col, grid)+grid[robX][rob1Y]+grid[robX][rob2Y];
                return dp[robX][rob1Y][rob2Y] = max({path1, path2, path3, path4, path5, path6, path7, path8, path9});
            }
            
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int row=grid.size(), col=grid[0].size();
        return recurse(0, 0, col-1, row, col, grid);
    }
};