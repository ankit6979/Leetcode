#include <bits/stdc++.h>
using namespace std

#define MOD 1000000007
    class Solution
{
public:
    int dp[20001][5];
    int countPermutation(int pos, int &n, char curr_char, int curr_elem)
    {
        if (pos == n)
        {
            return 1;
        }
        else if (dp[pos][curr_elem] != -1)
        {
            return dp[pos][curr_elem];
        }
        else
        {
            if (curr_char == 'a')
            {
                return dp[pos][curr_elem] = countPermutation(pos + 1, n, 'e', 1) % MOD;
            }
            else if (curr_char == 'e')
            {
                return dp[pos][curr_elem] = (countPermutation(pos + 1, n, 'a', 0) % MOD + countPermutation(pos + 1, n, 'i', 2) % MOD) % MOD;
            }
            else if (curr_char == 'i')
            {
                return dp[pos][curr_elem] = ((countPermutation(pos + 1, n, 'a', 0) % MOD + countPermutation(pos + 1, n, 'e', 1) % MOD) % MOD + (countPermutation(pos + 1, n, 'o', 3) % MOD + countPermutation(pos + 1, n, 'u', 4) % MOD) % MOD) % MOD;
            }
            else if (curr_char == 'o')
            {
                return dp[pos][curr_elem] = (countPermutation(pos + 1, n, 'i', 2) % MOD + countPermutation(pos + 1, n, 'u', 4) % MOD) % MOD;
            }
            else
            {
                return dp[pos][curr_elem] = countPermutation(pos + 1, n, 'a', 0) % MOD;
            }
        }
    }
    int countVowelPermutation(int n)
    {
        memset(dp, -1, sizeof(dp));
        return (((countPermutation(1, n, 'a', 0) % MOD + countPermutation(1, n, 'e', 1) % MOD) % MOD + (countPermutation(1, n, 'i', 2) % MOD + countPermutation(1, n, 'o', 3) % MOD) % MOD) % MOD + countPermutation(1, n, 'u', 4) % MOD) % MOD;
    }
};