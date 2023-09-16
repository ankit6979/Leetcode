#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll digitSum(ll num){
    ll sum=0;
    while(num != 0){
        sum += num%10;
        num = num/10;
    }
    return sum;
}

int main(){
    int testCase, numOfRounds, chefWins, mortyWins;
    ll chefNum, mortyNum, chefSum, mortySum;
    scanf("%d", &testCase);
    while(testCase--){
        scanf("%d", &numOfRounds);
        for(int i=0; i<numOfRounds; i++){
            scanf("%lld %lld", &chefNum, &mortyNum);
            chefSum=digitSum(chefNum);
            mortySum=digitSum(mortyNum);
            if(chefSum>mortySum){
                chefWins += 1;
            }
            else if(mortySum>chefSum){
                mortyWins+=1;
            }
            else{
                chefWins+=1;
                mortyWins+=1;
            }
        }
        if(chefWins>mortyWins){
            printf("0");
        }
        else if(chefWins<mortyWins){
            printf("1");
        }
        else{
            printf("2");
        }
        printf("\n");
    }
    return 0;
}