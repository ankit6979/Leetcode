#include<bits/stdc++.h>
using namespace std;

struct Node {
    int sum;
    int idx_a;
    int idx_b;
};

struct myCmp{
    bool operator()(const Node &a, const Node &b){
        return a.sum < b.sum;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<Node, vector<Node>, myCmp> pq;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    vector<int> ans;
    set<pair<int, int>> s;
    
    pq.push({A[0] + B[0], 0, 0});
    s.insert({0, 0});
    
    while(C > 0 && !pq.empty()) {
        Node curr = pq.top(); pq.pop();
        ans.push_back(curr.sum);
        C -= 1;
        
        int new_idx_a = curr.idx_a + 1;
        int new_idx_b = curr.idx_b;
        
        if(new_idx_a < A.size() && s.find({new_idx_a, new_idx_b}) == s.end()) {
            pq.push({A[new_idx_a] + B[new_idx_b], new_idx_a, new_idx_b});
            s.insert({new_idx_a, new_idx_b});
        }
        
        new_idx_a = curr.idx_a;
        new_idx_b = curr.idx_b + 1;

        if(new_idx_a < A.size() && s.find({new_idx_a, new_idx_b}) == s.end()) {
            pq.push({A[new_idx_a] + B[new_idx_b], new_idx_a, new_idx_b});
            s.insert({new_idx_a, new_idx_b});
        }
    }
    
    return ans;
}
