#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
const long long inf = 1e13 + 10;
long long dp[2][maxn];
int n, a[maxn], b[maxn];

// Checker functions based on derived invariants
void check_quadratic_complexity_invariant(int n) {
    if (n > 2000) {
        cerr << "Warning: quadratic complexity invariant triggered - large n leading to high loop iterations" << endl;
        abort();
    }
}

void check_adjustment_invariant(const int* a, int n) {
    int largeDifferenceCount = 0;
    const int threshold = 100;  // Example threshold for "significant margin"
    for (int i = 1; i <= n; i++) {
        if (a[i] > i + threshold) {
            largeDifferenceCount++;
        }
    }
    if (largeDifferenceCount > n / 2) {
        cerr << "Warning: adjustment invariant triggered - large differences causing high operation count" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    // Check for potential high complexity due to large n
    check_quadratic_complexity_invariant(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
        b[i] = a[i];
    }

    // Check for potential high operations due to array adjustments
    check_adjustment_invariant(a, n);

    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        long long w = inf;
        for (int j = 1; j <= n; j++) {
            w = min(dp[0][j], w);
            dp[1][j] = w + abs(b[j] - a[i]);
        }
        swap(dp[1], dp[0]);
    }
    long long ans = inf;
    for (int j = 1; j <= n; j++) {
        ans = min(ans, dp[0][j]);
    }
    cout << ans;
    return 0;
}