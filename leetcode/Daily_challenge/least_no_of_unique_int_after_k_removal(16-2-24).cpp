#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }
        vector<int> freq_count;
        for(auto it = freq.begin(); it != freq.end(); it++) {
            freq_count.push_back(it->second);
        }
        sort(freq_count.begin(), freq_count.end());
        int i = 0;
        while(k > 0) {
            if(k >= freq_count[i]) {
                k -= freq_count[i];
                i++;
            }
            else{
                break;
            }
        }
        return freq_count.size() - i;
    }
};