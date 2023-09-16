#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCase, length;
    scanf("%d", &testCase);
    while(testCase--){
        bool lapindromeFlag = true;
        map<char,int> freq;
        string S;
        cin>>S;
        length = S.size();
        for(int i=0; i<length; i++){
            if(i<(length/2)){
                freq[S[i]] += 1;
            }
            else if(i>=ceil(length/2.0)){
                if(freq[S[i]]==0){
                    lapindromeFlag = false;
                    break;   
                }
                else{
                    freq[S[i]] -= 1;
                }
            }
        }
        map<char, int> :: iterator it;
        for (it = freq.begin(); it != freq.end(); it++){
            if(it->second > 0){
                lapindromeFlag = false;
                break;  
            }
        }
        if(lapindromeFlag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}