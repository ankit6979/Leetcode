class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, right = 0;
        int max_len = -1;
        while (right < nums.size()) {
            int len = right - left;
            if (len < k)
            {
                ++freq[nums[right++]];
            }
            else if (freq[nums[right]] < k) {
                ++freq[nums[right++]];
            }
            else {
                --freq[nums[left++]];
            }
            len = right - left;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();