#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int started, ended;
        vector<int> ans, bloom_start, bloom_end;
        for(int i=0; i<flowers.size(); i++){
            bloom_start.push_back(flowers[i][0]);
            bloom_end.push_back(flowers[i][1]);
        }
        sort(bloom_start.begin(), bloom_start.end());
        sort(bloom_end.begin(), bloom_end.end());
        for(int i=0; i<people.size(); i++){
            started = upper_bound(bloom_start.begin(), bloom_start.end(), people[i])- bloom_start.begin();
            ended = lower_bound(bloom_end.begin(), bloom_end.end(), people[i])- bloom_end.begin();
            ans.push_back(started-ended);
        }
        return ans;
    }
};