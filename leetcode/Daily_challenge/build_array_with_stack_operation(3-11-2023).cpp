#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int stream_num=1;
        for(auto num: target){
            while(stream_num != num){
                operations.push_back("Push");
                operations.push_back("Pop");
                ++stream_num;
            }
            operations.push_back("Push");
            ++stream_num;
        }
        return operations;
    }
};

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        stack<int> temp;
        int target_ptr=0, i=1;
        while(i<=n){
            temp.push(i);
            operations.push_back("Push");
            if(temp.top() == target[target.size()-1]){
                break;
            }
            if(temp.top() == target[target_ptr]){
                target_ptr++;
                i++;
            }
            else{
                temp.pop();
                operations.push_back("Pop");
                i++;
            }
            
        }
        return operations;
    }
};