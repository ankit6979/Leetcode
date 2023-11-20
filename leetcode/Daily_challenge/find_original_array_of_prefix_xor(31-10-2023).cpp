#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int curr_xor, prev_xor=pref[0];
        for(int i=1; i<pref.size(); i++){
            curr_xor = pref[i]^pref[i-1];
            pref[i-1]=prev_xor;
            prev_xor = curr_xor;
        }
        if(pref.size()>1){
            pref[pref.size()-1] = curr_xor;
        }
        return pref;
    }
};