#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1, maxPairSum=-1;
        while(i<j){
            maxPairSum = max(maxPairSum, nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxPairSum;
    }
};