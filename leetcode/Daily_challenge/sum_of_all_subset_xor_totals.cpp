#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate_subsets(int idx, vector<int>& nums, vector<int>& subset, vector<vector<int>>& powerset) {
        if (idx == nums.size()) {
            powerset.push_back(subset);
            return;
        }
        subset.push_back (nums[idx]);
        generate_subsets(idx + 1, nums, subset, powerset);
        subset.pop_back();
        generate_subsets(idx + 1, nums, subset, powerset);
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        vector<int> subset;
        generate_subsets(0, nums, subset, powerset);
        return powerset;
    }
};

class Solution {
public:
    void generate_subset(int idx, vector<int>& nums, int & total_xor_sum, int & curr_xor) {
        total_xor_sum += curr_xor;
        for (int i = idx; i < nums.size(); ++i){
            curr_xor = curr_xor ^ nums[i];
            generate_subset(i + 1, nums, total_xor_sum, curr_xor);
            curr_xor = curr_xor ^ nums[i];
        }
    }
    int subsetXORSum(vector<int>& nums) {
        int total_xor_sum = 0, curr_xor = 0;
        generate_subset(0, nums, total_xor_sum, curr_xor);
        return total_xor_sum;
    }
};



class Solution {
public:
    void generate_subset(int idx, vector<int>& nums, vector<vector<int>>& powerset, vector<int>& subset) {
        powerset.push_back(subset);
        for (int i = idx; i < nums.size(); ++i){
            subset.push_back(nums[i]);
            generate_subset(i + 1, nums, powerset, subset);
            subset.pop_back();
        }
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> powerset;
        vector<int> subset;
        int total_xor_sum = 0;
        generate_subset(0, nums, powerset, subset);
        for (int i = 0; i < powerset.size(); ++i) {
            int curr_xor = 0;
            for (int j = 0; j < powerset[i].size(); ++j) {
                curr_xor = curr_xor ^ powerset[i][j];
            }
            total_xor_sum += curr_xor;
        }
        return total_xor_sum;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();