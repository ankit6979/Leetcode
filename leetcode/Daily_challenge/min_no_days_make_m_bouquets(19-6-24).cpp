#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int currDay, int reqBouquet, int reqFlower) {
        int currFlower = 0, currBouquet = 0;
        for (auto day : bloomDay) {
            if (currFlower == reqFlower) {
                currBouquet += 1;
                currFlower = 0;
            }
            if (currBouquet == reqBouquet) {
                return true;
            }
            if (day <= currDay) {
                currFlower += 1;
            }
            else {
                currFlower = 0;
            }
        }
        if (currFlower == reqFlower) {
            currBouquet += 1;
            currFlower = 0;
        }
        if (currBouquet == reqBouquet) {
            return true;
        }
        return false;
    }
    int bSearch(vector<int>& bloomDay, int low, int high, int m, int k) {
        int minDays = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if(isPossible(bloomDay, mid, m, k)) {
                minDays = mid;
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }
        return minDays;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll totalFlowerReq = (ll)m * (ll)k;
        if (totalFlowerReq > bloomDay.size()) {
            return -1;
        }
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
        return bSearch(bloomDay, 0, maxDay, m, k);
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();