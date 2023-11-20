#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int win_cnt=0, curr_winner, prev_winner=-1, loser, first_idx=0, second_idx=1;
        int max_elem = *max_element(arr.begin(), arr.end());
        int max_elem_idx = max_element(arr.begin(), arr.end())-arr.begin();
        if(k>=max_elem_idx){
            return *max_element(arr.begin(), arr.end());
        }
        else{
            while(win_cnt!=k){
                if(second_idx > arr.size() || first_idx > arr.size()){
                    return max_elem;
                }
                if(arr[first_idx]>arr[second_idx]){
                    curr_winner = arr[first_idx];
                    loser = arr[second_idx];
                    second_idx++;
                }
                else{
                    curr_winner = arr[second_idx];
                    loser = arr[first_idx];
                    first_idx = second_idx;
                    second_idx++;
                }
                if(prev_winner != -1){
                    if(prev_winner == curr_winner){
                        win_cnt++;
                    }
                    else{
                        win_cnt=1;
                    }
                    prev_winner = curr_winner;
                }
                else{
                    win_cnt=1;
                    prev_winner = curr_winner;
                }
                if(win_cnt==k){
                    break;
                }
            }
        }
        return curr_winner;
    }
};