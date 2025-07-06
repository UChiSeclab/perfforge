#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
long long ans;
long long dp[266][266];
long long cdp[266][266];
long long tt[266];
long long ttt[266];

void check_large_k_invariant(long long k) {
    if (k > 100000000) { // Arbitrary threshold for large k near its upper limit
        cerr << "Warning: Performance bottleneck condition triggered - large k value!" << endl;
        abort();
    }
}

void check_recursion_invariant(int n) {
    if (n > 200) { // Threshold close to maximum constraint for n
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n) {
    if (n > 200) { // Threshold close to maximum constraint for n
        cerr << "Warning: Performance bottleneck condition triggered - large nested loop execution!" << endl;
        abort();
    }
}

void check_memoization_invariant(int n) {
    if (n > 200) { // High degree of variation leading to reduced cache effectiveness
        cerr << "Warning: Performance bottleneck condition triggered - ineffective memoization!" << endl;
        abort();
    }
}

long long f(long long x, int y) {
    if (x == k)
        return tt[y];
    else if (x == k - 1LL)
        return ttt[y];
    else {
        long long val = x;
        long long output = 1LL;
        while (y > 0) {
            if (y % 2 == 1) {
                output *= val;
                output %= 1000000007LL;
            }
            val *= val;
            val %= 1000000007LL;
            y /= 2;
        }
        return output;
    }
}

long long getcdp(int x, int y) {
    if (cdp[x][y] != -1LL) return cdp[x][y];
    if (y > x - y) return cdp[x][y] = getcdp(x, x - y);
    if (y == 0) return cdp[x][y] = 1LL;
    return cdp[x][y] = (getcdp(x - 1, y - 1) + getcdp(x - 1, y)) % 1000000007LL;
}

long long getdp(int x, int a) {
    if (dp[x][a] != -1LL) return dp[x][a];
    if (a == 0LL) {
        long long val = f(k, n) - f(k - 1LL, n) + 1000000007LL;
        val %= 1000000007LL;
        return dp[x][a] = f(val, x);
    }
    if (x == 1LL) {
        return dp[x][a] = f(k, n - a);
    }
    dp[x][a] = f(k, n - a) - f(k - 1LL, n - a) + 1000000007LL;
    dp[x][a] %= 1000000007LL;
    dp[x][a] *= f(k - 1LL, a);
    dp[x][a] %= 1000000007LL;
    dp[x][a] *= getdp(x - 1LL, a);
    dp[x][a] %= 1000000007LL;
    for (int i = 1; i <= a; i++) {
        long long val = getcdp(a, i);
        val *= f(k - 1LL, a - i);
        val %= 1000000007LL;
        val *= getdp(x - 1LL, a - i);
        val %= 1000000007LL;
        val *= f(k, n - a);
        val %= 1000000007LL;
        dp[x][a] += val;
        dp[x][a] %= 1000000007LL;
    }
    return dp[x][a];
}

int main() {
    scanf("%d %lld", &n, &k);

    // Check potential performance bottlenecks
    check_large_k_invariant(k);
    check_recursion_invariant(n);
    check_nested_loop_invariant(n);
    check_memoization_invariant(n);

    if (n == 1LL || k == 1LL) {
        printf("1");
        return 0;
    }
    tt[0] = 1LL;
    ttt[0] = 1LL;
    for (int i = 1; i <= n; i++) {
        tt[i] = tt[i - 1] * k;
        ttt[i] = ttt[i - 1] * (k - 1LL);
        tt[i] %= 1000000007LL;
        ttt[i] %= 1000000007LL;
    }
    memset(dp, -1, sizeof(dp));
    memset(cdp, -1, sizeof(cdp));
    printf("%lld\n", getdp(n, n));
    return 0;
}