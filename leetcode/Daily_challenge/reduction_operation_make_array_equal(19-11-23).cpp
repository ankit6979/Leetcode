#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int operations=0;
        map<int, int> freq;
        vector<int> elems;
        sort(nums.rbegin(), nums.rend());
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]] += 1;
            if(freq[nums[i]] == 1){
                elems.push_back(nums[i]);
            }
        }
        for(int i=0; i<elems.size(); i++){
            operations = operations + (elems.size()-i-1)*freq[elems[i]];
        }
        return operations;
    }
};