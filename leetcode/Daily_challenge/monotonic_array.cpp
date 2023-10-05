#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool is_inc=true, is_dec=true;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]<nums[i]){
                is_inc=false;
                break;
            }
        }
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]>nums[i]){
                is_dec=false;
                break;
            }
        }
        return is_inc || is_dec;
    }
};

/*Better solution in single pass*/
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool is_inc=true, is_dec=true;
        for(int i=0; i<nums.size()-1; i++){
            if(is_inc || is_dec){
                if(nums[i+1]<nums[i]){
                    is_inc=false;
                }
                if(nums[i+1]>nums[i]){
                    is_dec=false;
                }
            }
            else{
                return false;
            }
        }
        return is_inc || is_dec;
    }
};