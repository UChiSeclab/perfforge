#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int mod = 1e9 + 7;
long long dp[N][2], sums[N][2];

// Checker functions
void check_loop_range_invariant(int f1, int f2, int n) {
    if ((f2 - f1) > 0.9 * n) {  // Arbitrary threshold close to n
        cerr << "Warning: Performance bottleneck condition triggered due to large loop range!" << endl;
        abort();
    }
}

void check_while_loop_invariant(long long dp_value, int mod) {
    if (dp_value < -mod) {  // When the value is extremely negative
        cerr << "Warning: Performance bottleneck condition triggered due to excessive while loop iterations!" << endl;
        abort();
    }
}

void check_iteration_combination_invariant(int a, int n) {
    if (a <= 1 || a >= n) {  // Edge values for a
        cerr << "Warning: Performance bottleneck condition triggered due to edge-case starting floor!" << endl;
        abort();
    }
}

int main() {
    int n, a, b, k, d, s1, s2;
    cin >> n >> a >> b >> k;

    // Perform initial checks
    check_iteration_combination_invariant(a, n);

    int f1, f2;
    if (a < b)
        f1 = 1, f2 = b - 1;
    else
        f1 = b + 1, f2 = n;

    // Check loop range before starting iterations
    check_loop_range_invariant(f1, f2, n);

    int bit1, bit2;
    for (int j = 0; j <= k; j++) {
        bit1 = j & 1;
        bit2 = bit1 ^ 1;
        for (int i = f1; i <= f2; i++) {
            if (j == 0) {
                dp[i][bit1] = 1;
            } else {
                d = abs(b - i);
                s1 = max(f1, i - d + 1);
                s2 = min(f2, i + d - 1);
                dp[i][bit1] = sums[s2][bit2] - sums[s1 - 1][bit2] - dp[i][bit2];

                // Check the while loop condition
                check_while_loop_invariant(dp[i][bit1], mod);

                while (dp[i][bit1] < 0) {
                    dp[i][bit1] += mod;
                }

                dp[i][bit1] %= mod;
            }
            if (i == f1)
                sums[i][bit1] = dp[i][bit1];
            else
                sums[i][bit1] = dp[i][bit1] + sums[i - 1][bit1], sums[i][bit1] %= mod;
        }
    }
    cout << dp[a][k & 1] << endl;
    return 0;
}