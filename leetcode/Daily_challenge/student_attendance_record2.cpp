#define mod 1000000007
int dp[100001][3][2];
class Solution {
public:
    int attendance(int day, int late_cnt, int abs_cnt, int n) {
        if (late_cnt >= 3 || abs_cnt > 1) {
            return 0;
        }
        if (day == n) {
            return 1;
        }
        if (dp[day][late_cnt][abs_cnt] != -1) {
            return dp[day][late_cnt][abs_cnt];
        }
        long long present = attendance(day + 1, 0, abs_cnt, n);
        long long late = attendance(day + 1, late_cnt + 1, abs_cnt, n); 
        long long absent = attendance(day + 1, 0, abs_cnt + 1, n);

        return dp[day][late_cnt][abs_cnt] = ((present + late) % mod + absent) % mod;
    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return attendance(0, 0, 0, n);  
    }
};