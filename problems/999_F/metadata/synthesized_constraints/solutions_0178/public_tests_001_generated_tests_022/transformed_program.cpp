#include <bits/stdc++.h>
using namespace std;

// Checker functions implemented as suggested
void check_large_search_space(int uniqueCardNumbers, int uniqueFavoriteNumbers) {
    if (uniqueCardNumbers > 10000 || uniqueFavoriteNumbers > 100) {
        cerr << "Warning: Performance bottleneck due to large search space!" << endl;
        abort();
    }
}

void check_excessive_loop_execution(int n, int k) {
    if (n > 400 && k > 8) {
        cerr << "Warning: Performance bottleneck due to excessive loop execution!" << endl;
        abort();
    }
}

void check_dp_table_size(int maxSupply, int maxDemand) {
    if (maxSupply > 5000 || maxDemand > 500) {
        cerr << "Warning: Performance bottleneck due to large DP table usage!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long card[5001], f[501], h[11], n, k, i, j, p, q, r, demand[100001], supply[100001], ans = 0;
    map<long long, long long> make_pair;

    for (i = 0; i < 100001; i++) demand[i] = supply[i] = 0;

    cin >> n >> k;

    // Insert check for excessive loop execution based on n and k
    check_excessive_loop_execution(n, k);

    int uniqueCardNumbers = 0;
    for (i = 0; i < n * k; i++) {
        cin >> card[i];
        if (supply[card[i]] == 0) {
            uniqueCardNumbers++;
        }
        supply[card[i]]++;
    }

    int uniqueFavoriteNumbers = 0;
    for (i = 0; i < n; i++) {
        cin >> f[i];
        if (demand[f[i]] == 0) {
            uniqueFavoriteNumbers++;
        }
        demand[f[i]]++;
    }

    // Insert check for large search space
    check_large_search_space(uniqueCardNumbers, uniqueFavoriteNumbers);

    h[0] = 0;
    for (i = 1; i < k + 1; i++) cin >> h[i];

    for (j = 0; j < 501; j++) dp[0][j] = 0;

    for (p = 1; p < 501; p++) {
        for (q = 1; q < 5001; q++) {
            dp[p][q] = dp[p - 1][q];
            for (r = 1; r < q + 1; r++) {
                if (r > k) break;
                dp[p][q] = max(dp[p][q], dp[p - 1][q - r] + h[r]);
            }
        }
    }

    int maxSupply = 0, maxDemand = 0;
    for (i = 1; i < 100001; i++) {
        maxSupply = max(maxSupply, supply[i]);
        maxDemand = max(maxDemand, demand[i]);
        ans += dp[demand[i]][supply[i]];
    }

    // Insert check for large DP table usage
    check_dp_table_size(maxSupply, maxDemand);

    cout << ans;
}