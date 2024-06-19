#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> set_size;
    void buildSeive(int max_num, vector<vector<int>>& prime_factors){
        for(int i=2; i<=max_num; i++){
            int num = i;
            if(prime_factors[i].empty()){
                while(num<=max_num){
                    prime_factors[num].push_back(i);
                    num+=i;
                }
            }
        }
    }
    int root(int u){
        if(u != parent[u]){
            return parent[u] = root(parent[u]);
        }
        return parent[u];
    }
    void unionSet(int a, int b){
        int root_a = root(a);
        int root_b = root(b);
        if(set_size[root_a]<set_size[root_b]){
            parent[root_a] = parent[root_b];
            set_size[root_b] += set_size[root_a];
        }
        else{
            parent[root_b] = parent[root_a];
            set_size[root_a] += set_size[root_b];
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        int n = *max_element(nums.begin(), nums.end());
        int final_parent;
        parent.reserve(n+1);
        set_size.reserve(n+1);
        vector<vector<int>> prime_factors(n+1);
        buildSeive(n, prime_factors);
        
        for (int i=0; i<=n; i++){
            parent[i] = i;
            set_size[i] = 0;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                return false;
            }
            for(int j=0; j<prime_factors[nums[i]].size(); j++){
                unionSet(prime_factors[nums[i]][0], prime_factors[nums[i]][j]);
            }
        }
        final_parent=-1;
        for(int i=0; i<nums.size(); i++){
            int curr_parent = root(prime_factors[nums[i]][0]);
            if(final_parent == -1){
                final_parent = curr_parent;
            }
            else if(final_parent != curr_parent){
                return false;
            }
        }
        return true;
    }
};