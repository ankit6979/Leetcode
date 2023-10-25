#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans, prev_ans;
        ans.push_back(1);
        for(int i=0; i<=rowIndex; i++){
            for(int j=0; j<=i; j++){
                if(j==0){
                    ans[j]= 1;
                }
                else if(j==i){
                    ans.push_back(1);
                }
                else{
                    ans[j]=prev_ans[j-1]+prev_ans[j];
                }
            }
            prev_ans = ans;
        }
        return ans;
    }
};