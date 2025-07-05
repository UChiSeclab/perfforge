#include <bits/stdc++.h>
using namespace std;

int N, p[200], cnt[2];
bool v[200];
int dp[110][110][110][2];

// Checker functions
void check_missing_bulbs_invariant(int count_missing) {
    if (count_missing > 50) {
        cerr << "Warning: High number of missing bulbs can lead to performance issues!" << endl;
        abort();
    }
}

void check_near_max_input_invariant(int n, int count_missing) {
    if (n > 90 && count_missing > 50) {
        cerr << "Warning: Near maximum input size with many missing bulbs can slow down computation!" << endl;
        abort();
    }
}

void check_dp_state_explosion_invariant(int n) {
    if (n > 90) {
        cerr << "Warning: Large input leading to dynamic programming state explosion!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int i, j, k, t;

    int count_missing = 0;

    for (i = 1; i <= N; i++) {
        cin >> p[i];
        if (p[i] == 0) {
            count_missing++;
        } else {
            v[p[i]] = 1;
        }
    }

    // Check invariants
    check_missing_bulbs_invariant(count_missing);
    check_near_max_input_invariant(N, count_missing);
    check_dp_state_explosion_invariant(N);

    for (i = 1; i <= N; i++)
        if (!v[i]) cnt[i % 2]++;
    for (i = N; i > 0; i--) {
        for (j = 0; j <= N; j++)
            for (k = 0; k <= N; k++)
                for (t = 0; t < 2; t++) {
                    dp[i][j][k][t] = 2 * N;
                    if (p[i] != 0) {
                        int v = 0;
                        if (i != 1 && p[i] % 2 != t) v = 1;
                        dp[i][j][k][t] = v + dp[i + 1][j][k][p[i] % 2];
                    } else {
                        if (j > 0) {
                            int v = 0;
                            if (i != 1 && t != 0) v = 1;
                            dp[i][j][k][t] = min(dp[i][j][k][t], v + dp[i + 1][j - 1][k][0]);
                        }
                        if (k > 0) {
                            int v = 0;
                            if (i != 1 && t != 1) v = 1;
                            dp[i][j][k][t] = min(dp[i][j][k][t], v + dp[i + 1][j][k - 1][1]);
                        }
                    }
                }
    }
    cout << dp[1][cnt[0]][cnt[1]][0] << "\n";
    return 0;
}