#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max_elem=-1, second_max_elem, min_elem=INT_MAX, second_min_elem;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>max_elem){
                second_max_elem = max_elem;
                max_elem = nums[i]; 
            }
            else if(nums[i] <= max_elem){
                if(nums[i]>second_max_elem){
                    second_max_elem = nums[i];
                }
            }
            if(nums[i]<min_elem){
                second_min_elem = min_elem;
                min_elem = nums[i]; 
            }
            else if(nums[i] >= min_elem){
                if(nums[i]<second_min_elem){
                    second_min_elem = nums[i];
                }
            }
        }
        // cout<<max_elem<<" "<<second_max_elem<<endl;
        // cout<<min_elem<<" "<<second_min_elem<<endl;
        return (max_elem*second_max_elem)-(min_elem*second_min_elem);
    }
};