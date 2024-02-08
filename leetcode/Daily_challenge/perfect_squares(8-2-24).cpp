#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> dp = std::vector<int>(10001, -1);
    int numSquares(int n) {
        if(n <= 0){
            return n==0?0:INT_MAX;
        }
        else if(dp[n] != -1){
            return dp[n];
        }
        else{
            int i=1, ans=INT_MAX;
            while(i*i<=n){
                ans = min(ans, numSquares(n-(i*i))+1);
                i++;
            }
            return dp[n] = ans;
        }
    }
};