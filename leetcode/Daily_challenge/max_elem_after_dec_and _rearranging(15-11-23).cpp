#include <bits/stdc++.h>
using namespaces std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int maxVal = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= maxVal)
            {
                maxVal = arr[i];
            }
            else
            {
                maxVal++;
            }
        }
        return maxVal;
    }
};
