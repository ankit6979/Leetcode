#include<bits/stdc++.h>
using namespace std;

O(n^3) solution
class Solution {
public:
    string longestPalindrome(string s) {
        int start=0, start_pos, end_pos, max_len=1, curr_len;
        bool is_palindrome;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                start_pos=i, end_pos=j, curr_len=0, is_palindrome=true;
                while(start_pos <= end_pos){
                    if(s[start_pos] != s[end_pos]){
                        is_palindrome = false;
                        break;
                    }
                    else{
                        if(start_pos == end_pos){
                            curr_len += 1;
                        }
                        else{
                            curr_len += 2;
                        }
                    }
                    start_pos++;
                    end_pos--;
                }
                if(curr_len>max_len && is_palindrome){
                    max_len = curr_len;
                    start = i;
                }
            }
        }
        // cout<<start<<" "<<max_len<<endl;
        return s.substr(start, max_len);
    }
};

O(n^3) solution
class Solution {
public:
    string longestPalindrome(string s) {
        int l, r, max_len=1, start=0, end=0;
        //for odd length
        for(int i=0; i<s.length(); i++){
            l=r=i;
            while(l>=0 && r<s.length()){
                if(s[l]==s[r]){
                    l--, r++;
                }
                else if(s[l]!=s[r]){
                    break;
                }
            }
            if(r-l-1 > max_len){
                max_len = r-l-1;
                start = l+1;
            }
        }
        for(int i=0; i<s.length(); i++){
            l=i, r=i+1;
            while(l>=0 && r<s.length()){
                if(s[l]==s[r]){
                    l--, r++;
                }
                else if(s[l]!=s[r]){
                    break;
                }
            }
            if(r-l-1 > max_len){
                max_len = r-l-1;
                start = l+1;
            }
        }
        return s.substr(start, max_len);
    }
};