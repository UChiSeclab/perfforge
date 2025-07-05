#include <bits/stdc++.h>
using namespace std;

int dp[2222][2];
int X, Y, n;
int x[2222], y[2222];
int inv[211111], fu[211111];

int pv(int a, int b) {
    if (b == 0) return 1;
    long long r = pv(a, b / 2);
    r = r * r % 1000000007;
    if (b % 2) r = r * a % 1000000007;
    return r;
}

int C(int n, int k) {
    return fu[n] * 1ll * inv[k] % 1000000007 * inv[n - k] % 1000000007;
}

// Check for large dimensions
void check_large_dimension_invariant(int h, int w) {
    if (h + w > 200000) {
        cerr << "Warning: Performance bottleneck condition triggered! Large board dimensions." << endl;
        abort();
    }
}

// Check for power calculation bottleneck
void check_power_calculation_invariant(int h, int w) {
    if (h > 50000 || w > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered! Power calculation in large configuration." << endl;
        abort();
    }
}

// Check for complex black cell configuration
void check_black_cell_path_complexity(int n) {
    if (n > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered! Complex black cell configuration." << endl;
        abort();
    }
}

int main() {
    cin >> X >> Y >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    
    // Insert checks based on natural language invariants
    check_large_dimension_invariant(X, Y); // Detects large board dimensions
    check_power_calculation_invariant(X, Y); // Detects large configuration for power calculations
    check_black_cell_path_complexity(n); // Detects complex black cell configuration

    fu[0] = 1;
    for (int i = 1; i <= X + Y; i++) fu[i] = fu[i - 1] * 1ll * i % 1000000007;
    for (int i = 0; i <= X + Y; i++) inv[i] = pv(fu[i], 1000000007 - 2);
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (x[i] + y[i] > x[j] + y[j]) {
                swap(x[i], x[j]);
                swap(y[i], y[j]);
            }

    for (int i = 0; i < n; i++) dp[i][1] = C(x[i] - 1 + y[i] - 1, x[i] - 1);
    for (int i = 0; i < n; i++)
        for (int o = 0; o < 2; o++)
            for (int j = i + 1; j < n; j++) {
                if (x[j] < x[i] || y[j] < y[i]) continue;
                dp[j][o ^ 1] =
                    (dp[j][o ^ 1] +
                     dp[i][o] * 1ll * C(x[j] - x[i] + y[j] - y[i], x[j] - x[i])) %
                    1000000007;
            }

    int ans = C(X - 1 + Y - 1, X - 1);
    for (int i = 0; i < n; i++)
        for (int o = 0; o < 2; o++) {
            int t = dp[i][o] * 1ll * C(X - x[i] + Y - y[i], X - x[i]) % 1000000007;
            if (o)
                ans = (ans - t + 1000000007) % 1000000007;
            else
                ans = (ans + t) % 1000000007;
        }
    
    cout << ans << endl;
    return 0;
}