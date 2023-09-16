#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCase, numOfChords, pluck;
    scanf("%d", &testCase);
    while(testCase--){
        scanf("%d", &numOfChords);
        vector<int> chord;
        int skippedStrings=0;
        for(int i=0; i<numOfChords; i++){
            scanf("%d", &pluck);
            chord.push_back(pluck);
        }
        for(int i=0; i<numOfChords-1; i++){
            skippedStrings += abs(chord[i+1]-chord[i])-1;
        }
        printf("%d\n", skippedStrings);
    }
    return 0;
}