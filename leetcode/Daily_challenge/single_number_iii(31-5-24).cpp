#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check_bit(int num, int bit) {
        if (num & (1<<bit)) {
            return true;
        }
        return false;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int xor1 = 0;
        int xor_grp1 = 0, xor_grp2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xor1 = xor1 ^ nums[i];
        }
        for (int i = 0; i <= 31; ++i) {
            if (check_bit (xor1, i)) {
                for (int j = 0; j < nums.size(); ++j) {
                    if (check_bit(nums[j], i)) {
                        xor_grp1 = xor_grp1 ^ nums[j];
                    }
                    else {
                        xor_grp2 = xor_grp2 ^ nums[j];
                    }
                }
                break;
            }
        }
        return {xor_grp1 , xor_grp2};
    }
};