#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int min_x = abs(fx-sx);
        int min_y = abs(fy-sy);
        if(sx==fx && sy==fy){
            return t!=1;
        }
        return t>=max(min_x, min_y);
    }
};