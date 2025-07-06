#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
long long a[N];

void check_large_range_invariant(long long l, long long n) {
    if (l > 1000000000 && l/n > 10000) { // Example heuristic thresholds
        cerr << "Warning: Performance bottleneck condition triggered due to large range and many divisors!" << endl;
        abort();
    }
}

void check_divisor_count_invariant(size_t divisorCount, long long n) {
    if (divisorCount > n * 10) { // Arbitrary threshold assuming the divisor count grows too much relative to `n`
        cerr << "Warning: Performance bottleneck condition triggered due to high number of divisor tests!" << endl;
        abort();
    }
}

bool go(long long n, long long m) {
    long long i, l = (a[n - 1] - a[0]) / m;
    for (i = 1; i < n; i++) {
        if (((a[i] - a[0]) % l) != 0) return false;
    }
    return true;
}

int32_t main() {
    long long t, i, j, n, m, l, r, ans = -1;
    scanf("%lld", &n);
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    l = a[n - 1] - a[0];

    // Check for large range and divisor count before entering heavy computation
    check_large_range_invariant(l, n);

    vector<long long> v;
    for (i = 1; i <= (l / i); i++) {
        if (l % i == 0) {
            if (i >= (n - 1)) v.push_back(i);
            if (i != (l / i) && (l / i) >= (n - 1)) v.push_back(l / i);
        }
    }

    // Check for high number of potential divisors
    check_divisor_count_invariant(v.size(), n);

    sort(v.begin(), v.end());
    r = 0;
    while (ans == -1) {
        if (go(n, v[r]) == true) ans = v[r] - n + 1;
        r++;
    }
    printf("%lld\n", ans);
    return 0;
}