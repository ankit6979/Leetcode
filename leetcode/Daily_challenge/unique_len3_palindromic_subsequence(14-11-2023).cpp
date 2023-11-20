#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> prefix(26, INT_MAX);
        vector<int> suffix(26, -1);
        set<char> elems;
        int ans=0;
        for(int i=0; i<s.length(); i++){
            if(i<prefix[s[i]-97]){
                prefix[s[i]-97] = i;
            }
        }
        for(int i=0; i<s.length(); i++){
            if(i>suffix[s[i]-97]){
                suffix[s[i]-97] = i;
            }
        }
        for(int i=0; i<26; i++){
            if(prefix[i] != INT_MAX && suffix[i]!=-1 && (suffix[i]-prefix[i])>1){
                for(int j=prefix[i]+1; j<suffix[i]; j++){
                    elems.insert(s[j]);
                }
                ans+=elems.size();
                elems.clear();
            }
        }
        return ans;
    }
};