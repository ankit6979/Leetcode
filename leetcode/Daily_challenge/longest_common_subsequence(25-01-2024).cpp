#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    int maxLength(int idx1, int idx2, string& text1, string& text2){
        if(idx1==text1.length() || idx2==text2.length()){
            return 0;
        }
        else if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(text1[idx1]==text2[idx2]){
            return dp[idx1][idx2] = maxLength(idx1+1, idx2+1, text1, text2)+1;
        }
        else{
            return dp[idx1][idx2] = max(maxLength(idx1+1, idx2, text1, text2), maxLength(idx1, idx2+1, text1, text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        memset(dp, -1, sizeof(dp));
        return maxLength(0, 0, text1, text2);
    }
};