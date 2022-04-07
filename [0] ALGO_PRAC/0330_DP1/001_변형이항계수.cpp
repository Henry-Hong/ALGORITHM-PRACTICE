#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vector1d;
typedef vector<vector1d> vector2d;

// Memoization = topDown with recursion
int DP(vector2d& dp, int n, int k, int d){
    if(dp[n][k] != -1) return dp[n][k];

    if(k == 0 || k == n) return dp[n][k] = 1;
    else return dp[n][k] = (DP(dp, n-1, k-1, d) + DP(dp, n-1, k, d)) % d;
}

// Tabulation = bottmUp with for loop
int TB(vector2d& dp, int n, int k, int d){
    for(int i=2; i <= n; i++){
        for(int j=0; j<= i; j++){
            if(j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % d;
        }
    }
    return dp[n][k];
}


// Space complexity optimization
int DPv2(vector1d& dp, int n, int k, int d){
    k = k < n-k ? k : n-k; // n C k == n C n-k
    for(int i=1; i<=n; i++){
        int t, tt = 1, e = min(i, k);
        for(int j=1; j<=e; j++){
            t = dp[j];
            dp[j] = (t + tt) % d;
            tt = t;
        }
    }
    return dp[k];
}

int main(){

    int n, k, d;
    cin >> n >> k >> d;

    // 2d array를 이용한 이항계수 계산
    // vector2d dp(n+1, vector1d(n+1, -1));
    // dp[1][0] = dp[1][1] = 1;
    // int ans = DP(dp, n, k, d);
    // int ans = TB(dp, n, k, d);

    // 1d array를 이용한 이항계수 계산
    vector1d dp2(n/2 + 1, 0);
    dp2[0] = 1;
    int ans = DPv2(dp2, n, k, d);

    cout << ans;

    return 0;
}