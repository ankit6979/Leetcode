#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
class Solution
{
public:
    int dp[5000][10];
    int findSteps(int curr_digit, int n, vector<vector<int>> &board)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (dp[n][curr_digit] != -1)
        {
            return dp[n][curr_digit];
        }
        int res = 0;
        for (int i = 0; i < board[curr_digit].size(); i++)
        {
            res = ((res % mod) + (findSteps(board[curr_digit][i], n - 1, board) % mod)) % mod;
        }
        return dp[n][curr_digit] = res;
    }
    int knightDialer(int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> board{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        for (int i = 0; i <= 9; i++)
        {
            ans = ((ans % mod) + (findSteps(i, n - 1, board) % mod)) % mod;
        }
        return ans;
    }
};