#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mx = 500 + 9;
ll MOD = 1;
int a[mx];
ll dp[mx][mx], then[mx][mx];

// Function to check for bugs constraint efficiency
void check_bugs_constraint_efficiency(int b, const vector<int>& a) {
    int total_possible_bugs = accumulate(a.begin(), a.end(), 0);
    if (b > total_possible_bugs * 0.8) { // Consider a threshold of 80% of total possible bugs
        cerr << "Warning: Performance bottleneck condition triggered - bugs constraint efficiency!" << endl;
        abort();
    }
}

// Function to check for large data structure iteration
void check_large_data_structure_iteration(int b, int n) {
    if (b * n > 200000) { // Threshold chosen based on problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - large data structure iteration!" << endl;
        abort();
    }
}

// Function to check for programmer specific bugs
void check_programmer_specific_bugs(int b, const vector<int>& a) {
    int max_bug_rate = *max_element(a.begin(), a.end());
    if (max_bug_rate > b * 0.5) { // Consider if any programmer contributes disproportionately
        cerr << "Warning: Performance bottleneck condition triggered - programmer specific bugs!" << endl;
        abort();
    }
}

int main() {
    int n, m, b;
    cin >> n >> m >> b >> MOD;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    // Insert performance checks after reading input
    check_bugs_constraint_efficiency(b, a);
    check_large_data_structure_iteration(b, n);
    check_programmer_specific_bugs(b, a);
    
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= b; k++) {
            then[i][k] = 1;
        }
    }
    for (int j = m - 1; j >= 0; j--) {
        for (int k = 0; k <= b; k++) {
            for (int i = n; i >= 1; i--) {
                dp[i][k] = dp[i + 1][k];
                if (k + a[i] <= b) dp[i][k] += then[i][k + a[i]];
                if (dp[i][k] >= MOD) dp[i][k] %= MOD;
            }
        }
        for (int k = 0; k <= b; k++) {
            for (int i = n; i >= 1; i--) {
                then[i][k] = dp[i][k];
                dp[i][k] = 0;
            }
        }
    }
    ll ans = then[1][0];
    cout << ans << endl;
}