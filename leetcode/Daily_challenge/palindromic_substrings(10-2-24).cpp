class Solution {
public:
    int recurse(int start, int curr_pos, int n, string s){
        if(curr_pos == n){
            return 0;
        }
        else{
            bool isPalindrome=true;
            int i=start, j=curr_pos;
            while(i<=j){
                if(s[i]!=s[j]){
                    isPalindrome=false;
                    break;
                }
                i++;
                j--;
            }
            if(isPalindrome){
                return recurse(start, curr_pos+1, n, s)+1;
            }
            else{
                return recurse(start, curr_pos+1, n, s);
            }
        }
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            ans += recurse(i, i, s.length(), s);
        }
        return ans;
    }
};