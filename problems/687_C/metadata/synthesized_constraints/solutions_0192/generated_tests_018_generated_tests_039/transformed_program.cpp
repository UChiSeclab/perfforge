#include <bits/stdc++.h>
using namespace std;

// Checker function implementations
void check_k_threshold(int k) {
    if (k > 450) { // Threshold chosen considering maximum limit and complexity growth
        cerr << "Warning: Performance bottleneck condition triggered - k is close to maximum limit!" << endl;
        abort();
    }
}

void check_loop_iterations(int k, int n) {
    if (k > 450 && n > 10) { // Thresholds reflecting the impact of large k and significant n
        cerr << "Warning: Performance bottleneck condition triggered - high loop iterations expected!" << endl;
        abort();
    }
}

void check_dp_initialization_and_updates(int k, int n) {
    if (k > 450 && n > 10) { // Same as previous check because they are related
        cerr << "Warning: Performance bottleneck condition triggered - extensive DP table operations!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    // Insert checks after reading inputs
    check_k_threshold(k);
    check_loop_iterations(k, n);
    check_dp_initialization_and_updates(k, n);

    int A[n];
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    vector<vector<vector<bool> > > DP(
        k + 1, vector<vector<bool> >(n, vector<bool>(k + 1, false)));

    for (int i = 0; i < n; ++i) {
        DP[0][i][0] = true;
    }
    
    if (A[0] <= k) {
        DP[A[0]][0][0] = true;
        DP[A[0]][0][A[0]] = true;
    }
    
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i < n; ++i) {
            for (int l = 0; l <= k && j - A[i] >= 0; ++l) {
                if (DP[j - A[i]][i - 1][l]) {
                    DP[j][i][l] = true;
                    if (l + A[i] <= k) {
                        DP[j][i][l + A[i]] = true;
                    }
                }
            }
            for (int l = 0; l <= k; ++l) {
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