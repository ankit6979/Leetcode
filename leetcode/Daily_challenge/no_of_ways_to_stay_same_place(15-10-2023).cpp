class Solution {
public:
    const int MOD = 1000000007;
    int n, dp[251][501];
    int stepsPossible(int pos, int steps, int arrLen){
        if(steps==0){
            return (pos==0)?1:0;
        }
        else if(pos>=n || pos<0){
            return 0;
        }
        else if(dp[pos][steps] != -1){
            return dp[pos][steps];
        }
        else{
            int leftStep = stepsPossible(pos-1, steps-1, arrLen);
            int stayStep = stepsPossible(pos, steps-1, arrLen);
            int rightStep = stepsPossible(pos+1, steps-1, arrLen);
            return dp[pos][steps] = ((leftStep+stayStep)%MOD+rightStep%MOD)%MOD;
        }
    }
    int numWays(int steps, int arrLen) {
        n= min(251, arrLen); //since at max we can go till 251 to reach back to 0
        // memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<501; j++){
                dp[i][j]=-1;
            }
        }
        return stepsPossible(0, steps, arrLen);
    }
};