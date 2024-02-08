#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkAP(int start, int end, vector<int> &nums)
    {
        unordered_set<int> st;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int series_len = end - start + 1;
        for (int i = start; i <= end; i++)
        {
            maxi = max(nums[i], maxi);
            mini = min(nums[i], mini);
            st.insert(nums[i]);
        }
        if ((maxi - mini) % (series_len - 1) != 0)
        {
            return false;
        }
        int diff = (maxi - mini) / (series_len - 1);
        int curr = mini + diff;
        while (curr < maxi)
        {
            if (st.find(curr) == st.end())
            {
                return false;
            }
            curr += diff;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++)
        {
            ans.push_back(checkAP(l[i], r[i], nums));
        }
        return ans;
    }
};