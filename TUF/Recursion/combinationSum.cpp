#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void recurseSum(vector<int>& candidates, int idx, int target, vector<int>& elementsPicked) {
        if (idx >= candidates.size() && target != 0) {
            return;
        }
        else if (idx >= candidates.size() && target == 0) {
            ans.push_back(elementsPicked);
            return;
        }
        else if (target - candidates[idx] < 0) {
            recurseSum(candidates, idx - 1, target, elementsPicked);
        }
        else {
            elementsPicked.emplace_back(candidates[idx]);
            recurseSum(candidates, idx, target - candidates[idx], elementsPicked);
            elementsPicked.pop_back();
            recurseSum(candidates, idx - 1, target, elementsPicked);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> elementsPicked;
        recurseSum(candidates, candidates.size() - 1, target, elementsPicked);
        return ans;
    }
};