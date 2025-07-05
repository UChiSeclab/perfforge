#include <bits/stdc++.h>
using namespace std;

unsigned long long pw[64];

bool check(unsigned long long x, unsigned long long n, unsigned long long k) {
    if (!x) return 1;
    string N;
    while (n) N = char(n % 2 + '0') + N, n /= 2;
    string X;
    while (x) X = char(x % 2 + '0') + X, x /= 2;

    // Check for nested loop inefficiency due to binary string length differences
    check_nested_loop_invariant(N.size(), X.size());

    unsigned long long ans = 0;
    if (X.size() < N.size()) {
        for (int i = X.size(); i < (int)N.size(); ++i)
            ans += pw[i - (int)X.size() + (X.back() == '0')];
    }
    int xsiz = X.size();
    while (X.size() < N.size()) X += '0';
    if (X <= N) {
        vector<unsigned long long> dp[2];
        dp[0].resize(N.size() + 1);
        dp[1].resize(N.size() + 1);
        dp[0][0] = 1;
        for (int i = 0; i < N.size(); ++i) {
            for (int f = 0; f < 2; ++f) {
                dp[f | (X[i] < N[i])][i + 1] += dp[f][i];
                if (i >= xsiz - 1 && X[i] == '0' && (f || X[i] < N[i]))
                    dp[f][i + 1] += dp[f][i];
            }
        }
        ans += dp[0][N.size()] + dp[1][N.size()];
    }
    return ans >= k;
}

int main() {
    pw[0] = 1;
    for (int i = 1; i < 64; ++i) pw[i] = pw[i - 1] * 2;

    unsigned long long n, k;
    scanf("%llu %llu", &n, &k);

    // Check for binary conversion performance bottleneck
    check_binary_conversion_invariant(n);

    unsigned long long lb = 0, rb = n / 2;
    while (lb < rb) {
        unsigned long long md = (lb + rb + 1) >> 1;
        if (check(md * 2, n, k))
            lb = md;
        else
            rb = md - 1;
    }
    unsigned long long ans = lb * 2;

    lb = 0;
    rb = (n - 1) / 2;
    while (lb < rb) {
        unsigned long long md = (lb + rb + 1) >> 1;
        if (check(md * 2 + 1, n, k))
            lb = md;
        else
            rb = md - 1;
    }

    // Check for binary search inefficiency
    check_binary_search_invariant(n, k);

    ans = max(ans, lb * 2 + 1);
    printf("%llu\n", ans);
    return 0;
}