#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stringToNum(string s){
        int num=0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1'){
                num += pow(2, i);
            }
        }
        return num;
    }
    string intToString(int n, int len){ 
        string str="";
        for (int i = 0; i<=len; i++) { 
            int k = n >> i; 
            if (k & 1) {
                str = str+"1";
            } 
            else{
                str = str+"0";
            }
        }
        return str;
    } 
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        int val=0;
        map<int, int> mapping;
        for(int i=0; i<nums.size(); i++){
            mapping[stringToNum(nums[i])] = 1;
        }
        while(val<pow(2, 16)){
            if(mapping[val] != 1){
                return intToString(val, nums.size()-1);
            }
            val++;
        }
        return ans;
    }
};