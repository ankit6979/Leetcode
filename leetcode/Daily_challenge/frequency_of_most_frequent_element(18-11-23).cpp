#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    int ifPossible(ll val, vector<int>& nums, vector<ll>& prefixSum, ll k){
        ll windowSize = val;
        ll windowSum;
        ll i=0, j=windowSize-1;
        if(j==0){
            return true;
        }
        while(j>0 && j<nums.size()){
            if(i-1>=0){
                windowSum = (nums[j]*(windowSize-1));
                if(k>=windowSum-(prefixSum[j-1]-prefixSum[i-1])){
                    return true;
                }
            }
            else{
                windowSum = (nums[j]*(windowSize-1));
                if(k>=windowSum-(prefixSum[j-1])){
                    return true;
                }
            }
            j++;
            i++;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        long long int currSum=0;
        sort(nums.begin(), nums.end());
        vector<long long int> prefixSum;
        for(int i=0; i<nums.size(); i++){
            currSum += nums[i];
            prefixSum.push_back(currSum);
        }
        int low=1, high=nums.size(), ans;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(ifPossible(mid, nums, prefixSum, k)){
                ans = mid;
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};