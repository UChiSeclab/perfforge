#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long infinity = 1000000000000000000;
bool do_debug = false;

// Check for large search space in subset sum calculation
void check_large_search_space(int n, int m, const vector<vector<int>> &matrix) {
    int similar_count = 0;
    for (int i = 0; i < n; ++i) {
        set<int> unique_elements(matrix[i].begin(), matrix[i].end());
        if (unique_elements.size() == 1) {
            ++similar_count;
        }
    }
    if (similar_count > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large search space due to similar elements." << endl;
        abort();
    }
}

// Check for high redundancy in count updates
void check_redundant_updates(int n, int m, const vector<vector<bool>> &subset_sums) {
    if (n > 60 && m < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high redundancy in count updates." << endl;
        abort();
    }
}

// Check for extensive iteration on large state spaces
void check_large_state_space(int n, int k) {
    if (n > 60 && k > 60) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive iteration on large state spaces." << endl;
        abort();
    }
}

void solve() {
    int nr, nc, div;
    cin >> nr >> nc >> div;
    int lim = nc / 2;
    vector<vector<int>> v(nr, vector<int>(nc));
    vector<vector<bool>> subset_sums(nr, vector<bool>(4901, false));
    vector<vector<int>> mod_values(nr, vector<int>(div, -1));
    vector<int> counts(4901, 1000);
    vector<vector<int>> dp(nr, vector<int>(div, -1));

    for (long long i = 0; i < nr; i++) {
        for (long long j = 0; j < nc; j++) {
            cin >> v[i][j];
        }
    }

    // Check for performance bottlenecks
    check_large_search_space(nr, nc, v);
    check_large_state_space(nr, div);

    for (long long i = 0; i < nr; i++) {
        subset_sums[i][0] = true;
        counts = vector<int>(4901, 1000);
        counts[0] = 0;
        for (long long j = 0; j < nc; j++) {
            vector<bool> updated_subset_sums(4901, false);
            vector<int> updated_counts(4901, 1000);
            for (long long k = 0; k < 4901; k++) {
                if (subset_sums[i][k] && (counts[k] + 1 <= lim)) {
                    updated_subset_sums[k + v[i][j]] = true;
                    updated_counts[k + v[i][j]] = counts[k] + 1;
                }
            }
            for (long long k = 0; k < 4901; k++) {
                if (updated_subset_sums[k]) {
                    subset_sums[i][k] = true;
                }
                counts[k] = min(counts[k], updated_counts[k]);
            }
        }
        for (long long k = 0; k < 4901; k++) {
            if (subset_sums[i][k]) {
                mod_values[i][k % div] = max(mod_values[i][k % div], (int)k);
            }
        }
    }
    
    // Additional check after subset sums are updated
    check_redundant_updates(nr, nc, subset_sums);

    for (long long i = 0; i < div; i++) {
        dp[0][i] = mod_values[0][i];
    }
    for (long long i = 1; i < nr; i++) {
        for (long long j = 0; j < div; j++) {
            for (long long k = 0; k < div; k++) {
                if (dp[i - 1][k] != -1 && mod_values[i][j] != -1) {
                    int x = (j + k) % div;
                    dp[i][x] = max(dp[i][x], mod_values[i][j] + dp[i - 1][k]);
                } else if (dp[i - 1][k] != -1) {
                    int x = k;
                    dp[i][x] = max(dp[i][x], dp[i - 1][k]);
                } else if (mod_values[i][j] != -1) {
                    int x = j;
                    dp[i][x] = max(dp[i][x], mod_values[i][j]);
                }
            }
        }
    }
    cout << dp[nr - 1][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q = 1;
    while (q-- > 0) {
        solve();
    }
    return 0;
}