#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501];
    int maxSum(int pos, int subarraySize, vector<int>& arr, int k, int maxVal){
        if(pos>=arr.size() || subarraySize>k){
            return 0;
        }
        else if(dp[pos][subarraySize] != -1){
            return dp[pos][subarraySize];
        }
        else{
            if(subarraySize+1<k){
                if(arr[pos]>maxVal){
                    maxVal=arr[pos];
                }
                return dp[pos][subarraySize]=max(maxSum(pos+1, 0, arr, k, -1)+(maxVal*(subarraySize+1)), maxSum(pos+1, subarraySize+1, arr, k, maxVal));
            }
            else{
                if(arr[pos]>maxVal){
                    maxVal=arr[pos];
                }
                return dp[pos][subarraySize]=maxSum(pos+1, 0, arr, k, -1)+(maxVal*(subarraySize+1));
            }
        }
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return maxSum(0, 0, arr, k, -1);
    }
};