#include<bits/stdc++.h>
using namespaces std;
#define long long int ll

int main(){
    int testCase, noOfCustomers, int budget, maxBudget=-1, minBudget=INT_MAX;
    ll maxProfit=-1;
    scanf("%d", &testCase);
    while(testCase--){
        vector<int> budgets;
        scanf("%d", &noOfCustomers);
        for(int i=0; i<noOfCustomers; i++){
            scanf("%d", &budget);
            if(budget>maxBudget){
                maxBudget = budget;
            }
            if(budget<minBudget){
                minBudget = budget;
            }
            budgets.push_back(budget);
        }
    }
    return 0;
}