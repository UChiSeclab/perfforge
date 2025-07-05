#include <bits/stdc++.h>
using namespace std;

// Function to check invariant on bulb configuration
void check_bulb_configuration_invariant(const vector<int>& bulbs) {
    int zeroCount = count(bulbs.begin(), bulbs.end(), 0);
    if (zeroCount > bulbs.size() / 2) { // Threshold: more than half of bulbs missing
        cerr << "Warning: Performance bottleneck condition triggered due to excessive missing bulbs!" << endl;
        abort();
    }
}

// Function to check invariant on state space complexity
void check_state_space_invariant(const vector<int>& bulbs) {
    int max_cluster = 0, current_cluster = 0;
    for (int bulb : bulbs) {
        if (bulb == 0) {
            current_cluster++;
        } else {
            max_cluster = max(max_cluster, current_cluster);
            current_cluster = 0;
        }
    }
    max_cluster = max(max_cluster, current_cluster);
    if (max_cluster > bulbs.size() / 2) { // Threshold: more than half in one block
        cerr << "Warning: Performance bottleneck condition triggered due to large cluster of missing bulbs!" << endl;
        abort();
    }
}

// Function to check invariant on initialization overhead
void check_initialization_invariant(int n) {
    if (n > 50) { // Threshold for initialization overhead
        cerr << "Warning: Performance bottleneck condition triggered due to large DP table initialization!" << endl;
        abort();
    }
}

// Function to check invariant on loop nesting
void check_loop_nesting_invariant(int n) {
    if (n > 50) { // Threshold for loop nesting
        cerr << "Warning: Performance bottleneck condition triggered due to deep loop nesting!" << endl;
        abort();
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Invariant checks before proceeding
    check_bulb_configuration_invariant(a);
    check_state_space_invariant(a);
    check_initialization_invariant(n);
    check_loop_nesting_invariant(n);

    vector<int> used(n + 1);
    for (auto i : a) {
        used[i] = 1;
    }
    int dp[n][n + 2][n + 2][2];
    for (int i = 0; i < n; i++) {
        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= n; y++) {
                dp[i][x][y][0] = n * n;
                dp[i][x][y][1] = n * n;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!i) {
            if (!a[i]) {
                dp[0][1][0][0] = 0;
                dp[0][0][1][1] = 0;
            } else {
                if (a[i] % 2) {
                    dp[0][0][1][1] = 0;
                } else {
                    dp[0][1][0][0] = 0;
                }
            }
        } else {
            for (int x = 0; x <= n; x++) {
                for (int y = 0; y <= n; y++) {
                    for (int val = 0; val < 2; val++) {
                        if (a[i] && val != a[i] % 2) {
                            continue;
                        }
                        if (!val) {
                            dp[i][x + 1][y][val] =
                                min(dp[i][x + 1][y][val], dp[i - 1][x][y][val]);
                            dp[i][x + 1][y][val] =
                                min(dp[i][x + 1][y][val], dp[i - 1][x][y][val ^ 1] + 1);
                        } else {
                            dp[i][x][y + 1][val] =
                                min(dp[i][x][y + 1][val], dp[i - 1][x][y][val]);
                            dp[i][x][y + 1][val] =
                                min(dp[i][x][y + 1][val], dp[i - 1][x][y][val ^ 1] + 1);
                        }
                    }
                }
            }
        }
    }
    vector<int> cnt(2);
    for (int i = 1; i <= n; i++) {
        cnt[i % 2]++;
    }
    cout << min(dp[n - 1][cnt[0]][cnt[1]][0], dp[n - 1][cnt[0]][cnt[1]][1])
         << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int test;
    test = 1;
    while (test--) {
        solve();
    }
    return 0;
}