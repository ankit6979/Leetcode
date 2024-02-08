#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int cnt=0;
        for(int i=0; i<s.length(); i++){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                if(freq1[i]<freq2[i]){
                    cnt += (freq2[i]-freq1[i]);
                }
            }
        }
        return cnt;
    }
};