#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bSearch(vector<int>& nums, int target, bool flag){
        int pos=-1, mid, low=0, high=nums.size()-1;
        while(low<=high){
            mid = low+(high-low)/2;
            if(nums[mid]==target){
                pos = mid;
                if(flag){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(bSearch(nums, target, true));
        ans.push_back(bSearch(nums, target, false));
        return ans;
    }
};