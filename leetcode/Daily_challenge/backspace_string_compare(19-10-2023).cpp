#include<bits/stdc++.h>
using namespace std;
/*
    using stack O(n) time, O(n) space
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, t1;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(s[i]);
            }
        }
        for(int i=0; i<t.length(); i++){
            if(t[i]=='#'){
                if(!t1.empty()){
                    t1.pop();
                }
            }
            else{
                t1.push(t[i]);
            }
        }
        if(s1.size()!=t1.size()){
            return false;
        }
        else{
            while(!s1.empty()){
                if(s1.top()!=t1.top()){
                    return false;
                }
                s1.pop();
                t1.pop();
            }
        }
        return true;
    }
};

/*
    using two pointer approach
    time O(n), space O(1)
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int si=0, sj=0, ti=0, tj=0;
        while(sj<s.length()){
            if(s[sj] == '#'){
                if(si>0){
                    si--;
                }
                sj++;
            }
            else{
                s[si] = s[sj];
                si++;
                sj++;
            }
        }
        while(tj<t.length()){
            if(t[tj] == '#'){
                if(ti>0){
                    ti--;
                }
                tj++;
            }
            else{
                t[ti] = t[tj];
                ti++;
                tj++;
            }
        }
        if(si!=ti){
            return false;
        }
        else{
            for(int i=0; i<si; i++){
                if(s[i]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};