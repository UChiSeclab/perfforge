#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const int INF = (1LL << 31) - 1;
const long long LINF = LLONG_MAX;
const int maxn = 1e3 + 1;
long long C[maxn][maxn], a[maxn], n, ans = 1;

// Checker functions
void check_recursion_depth_invariant(int r, int n) {
    if (r > 500 && n > 500) { // Thresholds based on constraints
        cerr << "Warning: Performance bottleneck - high recursion depth with large parameters!" << endl;
        abort();
    }
}

void check_memoization_invariant(int r, int n, int t) {
    if (r * n > 250000) { // Heuristic threshold for inefficient memoization
        cerr << "Warning: Performance bottleneck - inefficient memoization for wide input ranges!" << endl;
        abort();
    }
}

void check_combinatorial_invariant(int t, int max_a) {
    if (t > 800 && max_a > 50) { // Arbitrary thresholds based on analysis
        cerr << "Warning: Performance bottleneck - combinatorial growth in recursive calls!" << endl;
        abort();
    }
}

long long c(int r, int n) {
    check_recursion_depth_invariant(r, n);  // Check recursion depth
    if (r == 0 || r == n) return 1ll;
    if (C[r][n]) return C[r][n];
    C[r][n] = c(r - 1, n - 1);
    C[r][n] %= mod;
    C[r][n] += c(r, n - 1);
    C[r][n] %= mod;
    return C[r][n];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    int s = 0, t = 0;
    int max_a = 0;  // To track the maximum number of balls of any color
    for (int i = 0; i < n; i++) {
        cin >> a[i], t += a[i];
        max_a = max(max_a, a[i]);
    }
    check_combinatorial_invariant(t, max_a);  // Check combinatorial growth
    for (int i = n - 1; i >= 0; i--) {
        check_memoization_invariant(a[i], t - s - 1, t);  // Check memoization efficiency
        ans *= c(a[i] - 1, t - s - 1) % mod;
        ans %= mod;
        s += a[i];
    }
    cout << ans << endl;
}