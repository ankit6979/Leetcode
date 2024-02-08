#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][105];
    int countWays(string s, int idx, int len, int n){
        if(idx+len>n || s.substr(idx, len).starts_with('0') || stoi(s.substr(idx, len))>26){
            return 0;
        }
        else if(idx+len==n && stoi(s.substr(idx, len))<=26){
            return 1;
        }
        else if(dp[idx][idx+len] != -1){
            return dp[idx][idx+len];
        }
        else{
            return dp[idx][idx+len] = countWays(s, idx+len, 1, n)+countWays(s, idx+len, 2, n);
        }
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return countWays(s, 0, 1, s.length())+countWays(s, 0, 2, s.length());
    }
};