#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSymbol(int n, int k){
        if(n==1){
            return 0;
        }
        else{
            if(k>(pow(2, n-1))/2){
                return !findSymbol(n-1, k-pow(2, n-2));
            }
            else{
                return findSymbol(n-1, k);
            }
        }
    }
    int kthGrammar(int n, int k) {
        if(n==1){
            return 0;
        }
        return k>(pow(2, n-1))/2?!findSymbol(n-1, k-pow(2, n-2)):findSymbol(n-1, k);
    }
};