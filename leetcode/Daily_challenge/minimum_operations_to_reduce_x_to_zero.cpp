/* Using binary search by creating prefix and suffix arrays and then iterating
over prefix and finding the x-prefix_sum in suffix and repeating the same
process for suffix array*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bsearch(vector<int>& arr, int low, int high, int val){
        // int low=0, high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==val){
                return mid;
            }
            else if(arr[mid]<val){
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    } 
    int minOperations(vector<int>& nums, int x) {
        vector<int> prefix, suffix;
        int curr_sum=0, min_len=INT_MAX, l_sum=0, r_sum=0, idx;
        for(int i=0; i<nums.size(); i++){
            curr_sum+=nums[i];
            prefix.push_back(curr_sum);
        }
        curr_sum=0;
        for(int i=nums.size()-1; i>=0; i--){
            curr_sum+=nums[i];
            suffix.push_back(curr_sum);
        }
        sort(suffix.begin(), suffix.end());
        l_sum=x;
        for(int i=0; i<prefix.size(); i++){
            if(l_sum>=0){
                idx = bsearch(suffix, 0, suffix.size()-i-1, l_sum);
                if(idx != -1){
                    if(idx+1+i<min_len){
                        min_len=idx+1+i;
                    }
                }
            l_sum = x-prefix[i];
            }
            else{
                break;
            }
        }
        r_sum=x;
        for(int i=0; i<suffix.size(); i++){
            if(r_sum>=0){
                idx = bsearch(prefix, 0, prefix.size()-i-1, r_sum);
                if(idx != -1){
                    if(idx+1+i<min_len){
                        min_len=idx+1+i;
                    }
                }
            r_sum = x-suffix[i];
            }
            else{
                break;
            }
        }
        if(min_len == INT_MAX){
            return -1;
        }
        return min_len;
    }
};