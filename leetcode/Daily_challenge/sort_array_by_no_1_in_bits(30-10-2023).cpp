#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int countSetBits(int num){
        int count = 0;
        while(num){
            count++;
            num = num & (num-1);
        }
        return count;
    }
    static bool comp(const int& a, const int& b){
        int set_bit_a = countSetBits(a);
        int set_bit_b = countSetBits(b);
        if(set_bit_a==set_bit_b){
            return a<b;
        }
        return set_bit_a<set_bit_b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};



class Solution {
public:
    struct bits{
        int num;
        int set_bits;
        bool operator<(const bits& a) const{
            if(set_bits == a.set_bits){
                return num<a.num;
            }
            return set_bits<a.set_bits;
        }
    };
    int countSetBits(int num){
        int count = 0;
        while(num!=0){
            count++;
            num = num & (num-1);
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<bits> set_bits_arr;
        for(int i=0; i<arr.size(); i++){
            set_bits_arr.push_back({arr[i], countSetBits(arr[i])});
        }
        sort(set_bits_arr.begin(), set_bits_arr.end());
        for(int i=0; i<set_bits_arr.size(); i++){
            ans.push_back(set_bits_arr[i].num);
        }
        return ans;
    }
};