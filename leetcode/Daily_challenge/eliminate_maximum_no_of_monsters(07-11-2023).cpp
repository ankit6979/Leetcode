#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time_taken;
        int i;
        for(i=0; i<dist.size(); i++){
            time_taken.push_back(ceil(float(dist[i])/float(speed[i])));
        }
        sort(time_taken.begin(), time_taken.end());
        for(i=0; i<time_taken.size(); i++){
            if(time_taken[i]<=i){
                break;
            }
        }
        return max(i, 1);
    }
};