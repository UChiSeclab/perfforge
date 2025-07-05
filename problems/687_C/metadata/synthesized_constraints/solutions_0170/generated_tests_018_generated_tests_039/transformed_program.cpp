#include <bits/stdc++.h>
using namespace std;

// Checker functions based on inferred invariants
void check_dp_table_complexity(int k, const vector<int>& coins) {
    int unique_values = unordered_set<int>(coins.begin(), coins.end()).size();
    if (k > 450 && unique_values > 5) {  // Thresholds based on problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - High complexity in DP table updates due to large k and diverse coin values!" << endl;
        abort();
    }
}

void check_nested_loop_overhead(int k, const vector<int>& coins) {
    int max_coin = *max_element(coins.begin(), coins.end());
    int unique_values = unordered_set<int>(coins.begin(), coins.end()).size();
    if (k > max_coin * 2 && unique_values > 3) {  // Arbitrary thresholds to identify potential loops
        cerr << "Warning: Performance bottleneck condition triggered - Extensive nested loop computations due to large k and similar coin values!" << endl;
        abort();
    }
}

void check_state_exploration(int n, int k) {
    if (n > 450 && k > 450) {  // Thresholds chosen to highlight excessive state space
        cerr << "Warning: Performance bottleneck condition triggered - Excessive state exploration in DP table!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Insert checker functions to assess potential performance bottlenecks
    check_dp_table_complexity(k, A);
    check_nested_loop_overhead(k, A);
    check_state_exploration(n, k);

    vector<vector<vector<bool>>> DP(
        k + 1, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
    for (int i = 0; i < n; ++i) {
        DP[0][i][0] = true;
    }
    if (A[0] <= k) {
        DP[A[0]][0][A[0]] = true;
        DP[A[0]][0][0] = true;
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i < n; ++i) {
            if (j - A[i] >= 0) {
                for (int l = 0; l <= k; ++l) {
                    if (DP[j - A[i]][i - 1][l]) {
                        DP[j][i][l + A[i]] = true;
                        DP[j][i][l] = true;
                    }
                }
            }
            for (int l = 0; l <= k; l++) {
                if (DP[j][i - 1][l]) {
                    DP[j][i][l] = true;
                }
            }
        }
    }
    int sum = 0;
    for (int l = 0; l <= k; ++l) {
        if (DP[k][n - 1][l]) {
            sum++;
        }
    }
    cout << sum << "\n";
    for (int l = 0; l <= k; ++l) {
        if (DP[k][n - 1][l]) {
            cout << l << " ";
        }
    }
}