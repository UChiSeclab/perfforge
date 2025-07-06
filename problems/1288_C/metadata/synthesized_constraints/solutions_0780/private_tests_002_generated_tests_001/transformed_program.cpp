#include <bits/stdc++.h>
using namespace std;

long long n, m, dp[1005][1005][10];

void check_range_size_invariant(long long l, long long r) {
    if (r - l > 500) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - large range size in recursive calls!" << endl;
        abort();
    }
}

void check_dp_utilization_invariant(long long l, long long r, long long pos) {
    if (dp[l][r][pos] == -1 && (r - l) > 100) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - inefficient DP table utilization!" << endl;
        abort();
    }
}

void check_branching_invariant(long long pos) {
    if (pos > 7) { // Example threshold for branching
        cerr << "Warning: Performance bottleneck condition triggered - high branching in recursive calls!" << endl;
        abort();
    }
}

long long fn(long long l, long long r, long long pos) {
    check_range_size_invariant(l, r); // Check for large range size
    check_dp_utilization_invariant(l, r, pos); // Check for inefficient DP utilization
    check_branching_invariant(pos); // Check for high branching
    
    if (pos == m) return 1;
    if (l > r) return 0;
    long long &z = dp[l][r][pos];
    if (z != -1) return z;
    z = 0;
    z += fn(l, r, pos + 1);
    z %= 1000000007;
    z += fn(l + 1, r, pos);
    z %= 1000000007;
    z += fn(l, r - 1, pos);
    z %= 1000000007;
    z -= fn(l + 1, r - 1, pos);
    z += 1000000007;
    z %= 1000000007;
    return z;
}

int main() {
    long long int i, j, k, z = 0, c = 0, t, x, y, l, r, mid;
    scanf("%lld", &n);
    scanf("%lld", &m);
    memset(dp, -1, sizeof(dp));
    z = fn(1, n, 0);
    cout << z << endl;
}