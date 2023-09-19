#include<bits/stdc++.h>
using namespace std;

//using tortoise hare algorithm
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int slow = nums[0], fast=nums[0];
//         do{
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }while(slow!=fast);
//         fast = nums[0];
//         while(slow!=fast){
//             slow = nums[slow];
//             fast = nums[fast];
//         }
//         return slow;
//     }
// };

//Using Binary search approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1, high=nums.size(), count=0;
        int mid=(low+high)/2;
        while(low<high){
            mid=(low+high)/2;
            count=0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]<=mid){
                    count++;
                }
            }
            if(count>mid){
                high = mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};