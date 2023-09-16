#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCase;
    scanf("%d", &testCase);
    while(testCase--){
        int num, digit, maxPower, revNum=0;
        vector<int> digits;
        scanf("%d", &num);
        while(num!=0){
            digit = num%10;
            num = num/10;
            digits.push_back(digit);
        }
        maxPower = digits.size();
        for(int i=0; i<maxPower; i++){
            revNum += pow(10, maxPower-i-1)*digits[i];
        }
        printf("%d\n", revNum);
    }
    return 0;
}