#include<bits/stdc++.h>
using namespace std;

/* BFS Solution*/
class Solution {
public:
    struct Node{
        int x;
        int y;
    };
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        ios_base:: sync_with_stdio(false); cin.tie(NULL);
        vector<int> ans;
        queue<Node> q;
        Node start;
        start.x = 0, start.y=0;
        q.push(start);
        while(!q.empty()){
            Node curr_node = q.front();
            q.pop();
            ans.push_back(nums[curr_node.x][curr_node.y]);
            if(curr_node.y==0 && curr_node.x+1<nums.size()){
                q.push({curr_node.x+1, curr_node.y});
            }
            if(curr_node.y+1<nums[curr_node.x].size()){
                q.push({curr_node.x, curr_node.y+1});
            }
        }
        return ans;
    }
};

/* n(log(n)) sorting solution*/
class Solution {
public:
    struct Elements{
        int row_col_sum;
        int row;
        int val;
    };
    static bool comparator(const Elements &a, const Elements &b){
        if(a.row_col_sum == b.row_col_sum){
            return a.row>b.row;
        }
        else{
            return a.row_col_sum<b.row_col_sum;
        }
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        ios_base:: sync_with_stdio(false); cin.tie(NULL);
        vector<Elements> tuples;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                tuples.push_back({i+j, i, nums[i][j]});
            }
        }
        sort(tuples.begin(), tuples.end(), comparator);
        for(int i=0; i<tuples.size(); i++){
            ans.push_back(tuples[i].val);
        }
        return ans;
    }
};