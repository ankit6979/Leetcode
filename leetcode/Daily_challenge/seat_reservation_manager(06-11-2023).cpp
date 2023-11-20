#include<bits/stdc++.h>
using namespace std;

class SeatManager {
public:
    int pos;
    priority_queue<int, vector<int>, greater<int>> unreserved;
    SeatManager(int n) {
        pos = 0;
    }
    int reserve() {
        int curr_pos = pos;
        if(!unreserved.empty()){
            if(unreserved.top() < ++curr_pos){
                curr_pos = unreserved.top();
                unreserved.pop();
                return curr_pos;
            }
            else{
                return ++pos;    
            }
        }
        else{
            return ++pos;
        }
    }
    
    void unreserve(int seatNumber) {
        unreserved.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */