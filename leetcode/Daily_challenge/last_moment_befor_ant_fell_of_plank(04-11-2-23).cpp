#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size() == 0){
            return n-*min_element(right.begin(), right.end());
        }
        else if(right.size() == 0){
            return *max_element(left.begin(), left.end());
        }
        else{
            return max(
                *max_element(left.begin(), left.end()),
                n-*min_element(right.begin(), right.end())
            );
        }
    }
};