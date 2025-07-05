#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_small_divisor_invariant(int x) {
    if (x == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - small initial divisor (1) causes extensive loop iterations!" << endl;
        abort();
    }
}

void check_large_range_invariant(int x) {
    if (x < 10) { // Arbitrary threshold to highlight larger range iterations
        cerr << "Warning: Performance bottleneck condition triggered - large range iteration due to small x!" << endl;
        abort();
    }
}

int dp[1111111];
template <typename __ll>
inline void read(__ll &m) {
    __ll x = 0, f = 1;
    char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    m = x * f;
}

int main() {
    int i, n, x, ma = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
        read(x);

        // Apply performance checks
        check_small_divisor_invariant(x);
        check_large_range_invariant(x);

        ma = max(ma, dp[x] + 1);
        for (int j = 2 * x; j <= 1000000; j += x) {
            dp[j] = max(dp[j], dp[x] + 1);
        }
        dp[x]++;
    }
    printf("%d", ma);
}