#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        sort(piles.begin(), piles.end());
        int i=piles.size() - 2, no_of_coins=piles.size()/3,  my_coins=0;
        while(no_of_coins!=0){
            my_coins += piles[i];
            i-=2;
            no_of_coins--;
        }
        return my_coins;
    }
};