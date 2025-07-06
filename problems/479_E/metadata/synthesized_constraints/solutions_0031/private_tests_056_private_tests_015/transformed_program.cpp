#include <bits/stdc++.h>
using namespace std;

int n, a, b, k, dp[5010][5010], sum[5010][5010];

void mod_(int &x) {
    while (x > 1000000007) x -= 1000000007;
    // Check for excessive modulo operations
    check_modulo_invariant(x);
}

void check_modulo_invariant(int x) {
    if (x > 1000000007) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive modulo operations!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int k, int b) {
    if (k * b > 25000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop computations!" << endl;
        abort();
    }
}

void check_dp_invariant(int n, int k) {
    if (n * k > 25000000) {
        cerr << "Warning: Performance bottleneck condition triggered - large dynamic programming table!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d%d", &n, &a, &b, &k);

    // Check for dynamic programming overhead
    check_dp_invariant(n, k);

    if (a > b) a = n - a + 1, b = n - b + 1;
    dp[a][0] = 1;

    // Check for nested loop recomputations
    check_nested_loop_invariant(k, b);

    for (int j = 1; j <= k; j++) {
        for (int i = 1; i < b; i++)
            mod_(sum[i][j - 1] = sum[i - 1][j - 1] + dp[i][j - 1]);
        for (int i = 1; i < b; i++) {
            mod_(dp[i][j] += sum[i - 1][j - 1]);
            mod_(dp[i][j] +=
                 (sum[(i + b - 1) / 2][j - 1] - sum[i][j - 1] + 1000000007) %
                 1000000007);
        }
    }
    for (int i = 1; i <= b; i++) mod_(sum[i][k] = sum[i - 1][k] + dp[i][k]);
    printf("%d\n", sum[b][k]);
    return 0;
}