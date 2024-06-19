class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int total_subarray = 0;
        int curr_prdt = 1;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            curr_prdt *= nums[right];
            while (curr_prdt >= k) {
                curr_prdt /= nums[left];
                left++;
            }
            total_subarray += (right - left + 1);
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