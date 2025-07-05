#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
int n, k, v[maxn];
int dp[maxn][maxn];

// Checker functions
void check_large_k_invariant(int k, double average_coin_value) {
    if (k > 5 * average_coin_value) {
        cerr << "Warning: Performance bottleneck triggered - k is large compared to average coin value!" << endl;
        abort();
    }
}

void check_large_n_invariant(int n, int k, const vector<int>& v) {
    int count_large_coins = 0;
    for (int coin : v) {
        if (coin > k / 2) count_large_coins++;
    }
    if (n > 400 && count_large_coins > n / 4) {
        cerr << "Warning: Performance bottleneck triggered - high number of large coins with large n!" << endl;
        abort();
    }
}

void check_diverse_coins_invariant(int n, int distinct_values_count) {
    if (n > 400 && distinct_values_count > n / 2) {
        cerr << "Warning: Performance bottleneck triggered - high diversity in coin values!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> k;
    vector<int> coin_values(n);
    set<int> distinct_values;
    int sum_values = 0;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        coin_values[i - 1] = v[i];
        distinct_values.insert(v[i]);
        sum_values += v[i];
    }
    
    double average_coin_value = sum_values / static_cast<double>(n);

    // Insert checks for performance-characterizing invariants
    check_large_k_invariant(k, average_coin_value);
    check_large_n_invariant(n, k, coin_values);
    check_diverse_coins_invariant(n, distinct_values.size());

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= v[i]; j--) {
            for (int c = k; c >= 0; c--) {
                if (c < v[i])
                    dp[j][c] = max(dp[j][c], dp[j - v[i]][c]);
                else
                    dp[j][c] =
                        max(dp[j][c], max(dp[j - v[i]][c], dp[j - v[i]][c - v[i]]));
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= 500; i++) {
        if (dp[k][i]) ans++;
    }
    cout << ans << endl;
    for (int i = 0; i <= 500; i++) {
        if (dp[k][i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}