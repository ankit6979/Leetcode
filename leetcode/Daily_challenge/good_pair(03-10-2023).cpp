#include<bits/stdc++.h>
using namespace std;
/*
O(n^2) solution
*/
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         int good_pairs=0;
//         for(int i=0; i<nums.size()-1; i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[i]==nums[j]){
//                     good_pairs++;
//                 }
//             }
//         }
//         return good_pairs;
//     }
// };

/*
O(n) solution
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        short int good_pairs=0;
        short int arr[101] = {0};
        for(short int i=0; i<nums.size(); i++){
            good_pairs += arr[nums[i]]++;
        }
        return good_pairs;
    }
};