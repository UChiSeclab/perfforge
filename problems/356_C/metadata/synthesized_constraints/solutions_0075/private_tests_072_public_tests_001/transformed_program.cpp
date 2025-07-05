#include <bits/stdc++.h>
using namespace std;
const long long MN = 1100000;
long long d[MN];
long long a[MN], b[MN], c[MN];

void check_compartment_count_invariant(long long n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large compartment count!" << endl;
        abort();
    }
}

void check_variance_invariant(const long long *d, long long n) {
    int high_variance_count = 0;
    for (long long i = 0; i < n; ++i) {
        if (d[i] == 1 || d[i] == 2) {
            high_variance_count++;
        }
    }
    if (high_variance_count > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to high variance in student distribution!" << endl;
        abort();
    }
}

void check_condition_check_invariant(long long n, long long condition_count) {
    if (condition_count > n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered due to extensive condition checks!" << endl;
        abort();
    }
}

signed main() {
    long long n;
    cin >> n;

    // Check the invariant for compartment count
    check_compartment_count_invariant(n);

    long long s = 0;
    for (long long i = 0; i < n; i++) {
        cin >> d[i];
        s += d[i];
    }

    // Check the invariant for variance in student distribution
    check_variance_invariant(d, n);

    sort(d, d + n, greater<long long>());
    a[0] = b[0] = c[0] = 0;
    for (long long i = 0; i <= n; i++) {
        a[i + 1] = a[i], b[i + 1] = b[i], c[i + 1] = c[i];
        a[i + 1] += 4 - d[i];
        if (d[i] == 4) {
            c[i + 1]++;
        } else {
            b[i + 1] += 3 - d[i];
        }
        assert(a[i + 1] >= a[i]);
        assert(b[i + 1] >= b[i]);
        assert(c[i + 1] >= c[i]);
    }
    long long r = s * 2;
    long long condition_count = 0;
    for (long long i = 0; i <= n; i++) {
        long long u = s - 4 * i;
        if (u < 0) break;
        if (u % 3) continue;
        u /= 3;
        if (n < i + u) continue;
        long long bb = b[i + u] - b[i], cc = c[i + u] - c[i];
        r = min(r, a[i] + bb);
        condition_count++;
    }

    // Check the invariant for extensive condition checks
    check_condition_check_invariant(n, condition_count);

    if (r == s * 2) {
        cout << -1 << endl;
    } else {
        cout << r << endl;
    }
    return 0;
}