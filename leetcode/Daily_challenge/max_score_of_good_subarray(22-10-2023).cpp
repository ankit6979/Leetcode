#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int max_score=nums[k], min_num=nums[k], curr_score;
        int i=k-1, j=k+1;
        while(i>=0 || j<nums.size()){
            int left_val = i<0?-1:nums[i];
            int right_val = j>=nums.size()?-1:nums[j];
            if(left_val<=right_val){
                if(min_num>right_val){
                    min_num = right_val;
                }
                curr_score = min_num*(j-i);
                if(curr_score>max_score){
                    max_score = curr_score;
                }
                j++;
            }
            else if(left_val>right_val){
                if(min_num>left_val){
                    min_num = left_val;
                }
                curr_score = min_num*(j-i);
                if(curr_score>max_score){
                    max_score = curr_score;
                }
                i--;
            }
        }
        return max_score;
    }
};