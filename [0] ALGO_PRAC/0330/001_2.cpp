#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vector1d;

int DP(vector1d& dp, int n, int k, int d){
    dp[0] = 1;
    k = k < n-k ? k : n-k; // n C k == n C n-k
    for(int i=1; i<=n; i++){
        int t, tt = 1, e = min(i,k);
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

    vector1d dp2(n/2+1, 0);
    int ans = DP(dp2, n, k, d);

    cout << ans;

    return 0;
}