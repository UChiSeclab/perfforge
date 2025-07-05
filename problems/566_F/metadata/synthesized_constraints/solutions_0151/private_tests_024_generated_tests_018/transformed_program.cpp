#include <bits/stdc++.h>
using namespace std;

const int N = 1000007;
int dp[N];

// Checker for small divisor leading to high iteration counts
void check_small_divisor_invariant(int a) {
    if (a == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - small divisor causing excessive iterations!" << endl;
        abort();
    }
}

// Checker for large number of updates on dp array
void check_large_iteration_invariant(int a) {
    if (a == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive updates to dp array due to small divisor!" << endl;
        abort();
    }
}

void solve() {
    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);

        // Check for performance bottlenecks before proceeding
        check_small_divisor_invariant(a);
        check_large_iteration_invariant(a);

        dp[a] = max(dp[a], 1);
        for (int b = a + a; b < N; b += a) {
            dp[b] = max(dp[b], dp[a] + 1);
        }
        ans = max(ans, dp[a]);
    }
    printf("%d\n", ans);
}

void testGen() {
    FILE *f = fopen("input.txt", "w");
    fclose(f);
}

int main() {
    cerr << fixed;
    cerr.precision(3);
    cout << fixed;
    cout.precision(9);
    solve();
    return 0;
}