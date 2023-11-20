#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mod_inv 500000004
#define ll long long
class Solution {
public:
    int substringCount(ll n){
        ll num = (n*(n+1))%mod;
        ll ans = (num*mod_inv)%mod;
        return (int)ans;
    }
    int countHomogenous(string s) {
        int counter=1, substrings=0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i+1]==s[i]){
                counter++;
            }
            else{
                substrings = ((substrings%mod)+substringCount(counter)%mod)%mod;
                counter=1;
            }
        }
        substrings = ((substrings%mod)+substringCount(counter)%mod)%mod;
        return substrings;
    }
};