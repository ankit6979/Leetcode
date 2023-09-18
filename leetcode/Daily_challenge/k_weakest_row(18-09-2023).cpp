#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> soldiers;
        vector<int> sol;
        int soldier_cnt;
        for(int i=0; i<mat.size(); i++){
            soldier_cnt=0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j]==1){
                    soldier_cnt++;
                }
                else{
                    break;
                }
            }
            soldiers.push_back(make_pair(soldier_cnt, i));
        }
        sort(soldiers.begin(), soldiers.end());
        for(int i=0; i<k; i++){
            sol.push_back(soldiers[i].second);
        }
        return sol;
    }
};


class Solution {
public:
    int bsearch(vector<int>& arr, int x){
        int low=0, high=arr.size()-1, result=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if (x == arr[mid]){
                result = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> soldiers;
        vector<int> sol;
        int soldier_cnt;
        for(int i=0; i<mat.size(); i++){
            soldier_cnt = bsearch(mat[i], 1)+1;
            if(soldiers.size()<k){
                soldiers.push(make_pair(soldier_cnt, i));
            }
            else if(soldiers.top().first>soldier_cnt){
                soldiers.pop();
                soldiers.push(make_pair(soldier_cnt, i));
            }
        }
        while(!soldiers.empty()){
            sol.push_back(soldiers.top().second);
            soldiers.pop();
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
