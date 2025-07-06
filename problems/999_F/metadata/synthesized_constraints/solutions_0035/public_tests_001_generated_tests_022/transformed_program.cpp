#include <bits/stdc++.h>
#pragma 03
using namespace std;

long long n, k;
long long cnt1[200005];
long long cnt2[200005];
long long c[5005];
long long f[505];
long long h[15];
long long dp[5005][505];

void check_nested_loop_invariant(int n, int k) {
    if (n > 400 && k == 10) {
        cerr << "Warning: Performance bottleneck due to excessive nested loop iterations!" << endl;
        abort();
    }
}

void check_dp_update_invariant(int numDistinctFavNums, int numDistinctCardNums) {
    if (numDistinctFavNums > 350 && numDistinctCardNums > 450) {
        cerr << "Warning: Performance bottleneck due to frequent dynamic programming updates!" << endl;
        abort();
    }
}

void check_distribution_invariant(int varianceFavNums, int varianceCardNums) {
    if (varianceFavNums > 200 && varianceCardNums > 300) {
        cerr << "Warning: Performance bottleneck due to complex distribution of numbers!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> k;
    
    // Check for potential bottlenecks before proceeding with main logic
    check_nested_loop_invariant(n, k);
    
    for (int i = 0; i < 200005; i++) {
        cnt1[i] = 0;
        cnt2[i] = 0;
    }
    for (long long i = 0; i < k * n; i++) {
        cin >> c[i];
        cnt1[c[i]]++;
    }
    
    for (long long i = 0; i < n; i++) {
        cin >> f[i];
        cnt2[f[i]]++;
    }
    
    // Calculate distinct counts (hypothetical function calls)
    int numDistinctFavNums = set<int>(f, f + n).size();
    int numDistinctCardNums = set<int>(c, c + k * n).size();
    
    check_dp_update_invariant(numDistinctFavNums, numDistinctCardNums);
    
    h[0] = 0;
    for (long long i = 1; i <= k; i++) cin >> h[i];
    
    for (long long i = 0; i < 505; i++) dp[0][i] = 0;
    for (long long i = 1; i < 5005; i++) {
        for (long long j = 1; j < 505; j++) {
            long long r = min(k, i);
            for (long long a = 0; a <= r; a++)
                dp[i][j] = max(dp[i - a][j - 1] + h[a], dp[i][j]);
        }
    }
    
    long long ans = 0;
    for (long long i = 0; i < 200005; i++) ans += dp[cnt1[i]][cnt2[i]];
    cout << ans << endl;
    
    return 0;
}