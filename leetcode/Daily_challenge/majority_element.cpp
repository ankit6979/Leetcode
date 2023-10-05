#include<bits/stdc++.h>
using namespace std;

/*
    MOORES VOTING ALGO
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority_element, cnt=0;
        for(int num: nums){
            if(cnt==0){
                majority_element = num;;
                cnt++;
            }
            else if(majority_element == num){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return majority_element;
    }
};