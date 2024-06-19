#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int triplet_cnt = 0;
        vector<int> prefixXOR(arr.begin(), arr.end());
        prefixXOR.insert(prefixXOR.begin(), 0);
        for (int i = 1; i < prefixXOR.size(); ++i) {
            prefixXOR[i] ^= prefixXOR[i - 1];
        };
        for (int i = 0; i < prefixXOR.size(); ++i) {
            for (int j = i + 1; j < prefixXOR.size(); ++j) {
                if (prefixXOR[i] == prefixXOR[j]) {
                    triplet_cnt += (j - i - 1);
                }
            }
        }
        return triplet_cnt;
    }
};