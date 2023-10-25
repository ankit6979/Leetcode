#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        float val=n;
        if(n==1){
            return true;
        }
        if(n==0){
            return false;
        }
        else{
            while(n!=1){
                if(ceil(val/4)!=floor(val/4)){
                    return false;
                }
                n = n/4;
                val = n;
            }
            return true;
        }
    }
};