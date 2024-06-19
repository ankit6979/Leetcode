class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int total_subarray = 0, curr_prdt = nums[0];
        while (i < nums.size()) {
            if (curr_prdt < k && j < nums.size() - 1) {
                j++;
                curr_prdt = curr_prdt * nums[j];
            }
            else if (curr_prdt < k && j == nums.size() - 1) {
                total_subarray += (j - i + 1);
                curr_prdt = curr_prdt / nums[i];
                i++;
            }
            else {
                total_subarray += (j - i);
                curr_prdt = curr_prdt / nums[i];
                i++;
                if ( i > j) {
                    j++;
                    curr_prdt = nums[i];
                }
            }
        }
        return total_subarray < 0 ? 0 : total_subarray;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();