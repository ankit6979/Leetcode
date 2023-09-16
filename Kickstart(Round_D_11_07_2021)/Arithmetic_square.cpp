#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int test_case, test_cases, ap_count;
    ll element;
    vector<ll> matrix, mid_terms;
    scanf("%d", &test_cases);
    for(test_case=1; test_case<=test_cases; test_case++){
        ap_count = 0;
        mid_terms.clear();
        matrix.clear();
        for(int i=0; i<8; i++){
            scanf("%lld", &element);
            matrix.push_back(element);
        }
        if(matrix[0]+matrix[2] == 2*matrix[1]){
            ap_count++;
        }
        if(matrix[5]+matrix[7] == 2*matrix[6]){
            ap_count++;
        }
        if(matrix[0]+matrix[5] == 2*matrix[3]){
            ap_count++;
        }
        if(matrix[2]+matrix[7] == 2*matrix[4]){
            ap_count++;
        }
        cout<<(ap_count);
        mid_terms.push_back(matrix[3]+matrix[4]);
        mid_terms.push_back(matrix[1]+matrix[6]);
        mid_terms.push_back(matrix[0]+matrix[7]);
        mid_terms.push_back(matrix[2]+matrix[5]);
        sort(mid_terms.begin(), mid_terms.end());
        if((mid_terms[0]==mid_terms[1]) && (mid_terms[1]==mid_terms[2]) && (mid_terms[2]==mid_terms[3])){
            ap_count += 4;
        }
        else if(((mid_terms[0]==mid_terms[1]) && (mid_terms[1]==mid_terms[2])) || ((mid_terms[1]==mid_terms[2]) && (mid_terms[2] && mid_terms[3]))){
            ap_count += 3;
        }
        else if((mid_terms[0] != mid_terms[1]) && (mid_terms[1] != mid_terms[2]) && (mid_terms[2] != mid_terms[3])){
            ap_count += 1;
        }
        else{
            ap_count += 2;
        }
        cout<<"Case #" + to_string(test_case) + ": "<<ap_count<<endl;
    }
    return 0;
}