#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int

class Solution {
public:
    int reverseNumber(int num){
        int rev_num=0;
        while(num != 0){
            rev_num = rev_num * 10 + num % 10; 
            num = num / 10;
        }
        return rev_num;
    }
    int countNicePairs(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        ll ans=0, curr_freq;
        vector<int> transformed_nums;
        map<int, int> freq;
        for(int i=0; i<nums.size(); i++){
            transformed_nums.push_back(nums[i]-reverseNumber(nums[i]));
        }
        for(int i=0; i<transformed_nums.size(); i++){
            freq[transformed_nums[i]]++;
        }
        map<int, int>:: iterator it = freq.begin();
        while(it != freq.end()){
            curr_freq = it->second;
            ans = ((ans%mod)+((curr_freq*(curr_freq-1))/2)%mod)%mod;
            it++;
        }
        return (int)ans;
    }
};