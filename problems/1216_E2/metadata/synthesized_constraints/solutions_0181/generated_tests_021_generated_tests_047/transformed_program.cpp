#include <bits/stdc++.h>
using namespace std;

// Checker functions based on performance-characterizing invariants
void check_len1_invariant(long long n) {
    if (n > 1e6) {
        cerr << "Warning: len1 invariant triggered - potential performance issue with large n" << endl;
        abort();
    }
}

void check_len2_invariant(long long n) {
    if (n > 1e6) {
        cerr << "Warning: len2 invariant triggered - potential performance issue with large n" << endl;
        abort();
    }
}

void check_biser_range_invariant(long long range) {
    if (range > 1e9) {
        cerr << "Warning: biser range invariant triggered - excessive iterations possible" << endl;
        abort();
    }
}

long long le(long long n) {
    long long r = 0;
    while (n) {
        r++;
        n /= 10;
    }
    return r;
}

long long minpow10(long long n) {
    long long r = 1;
    for (int i = 1; i < n; i++) r = r * 10;
    return r;
}

long long maxpow10(long long n) {
    long long r = 1;
    for (int i = 1; i <= n; i++) r = r * 10;
    return r - 1;
}

long long len1(long long n) {
    // Check the invariant for len1 before proceeding
    check_len1_invariant(n);

    long long l = le(n);
    long long mp10 = minpow10(l);
    long long res = (n - mp10 + 1) * l;
    for (int i = 1; i < l; i++) {
        res += i * (maxpow10(i) - minpow10(i) + 1);
    }
    return res;
}

long long len2(long long n) {
    // Check the invariant for len2 before proceeding
    check_len2_invariant(n);

    if (n == 0) return 0;
    long long l = le(n);
    long long mp10 = minpow10(l);
    long long res =
        (n - mp10 + 1) * (n - mp10 + 2) / 2 * l + (n - mp10 + 1) * len1(mp10 - 1);
    res += len2(mp10 - 1);
    return res;
}

long long biser2(long long k, long long l, long long r) {
    // Check the range invariant
    check_biser_range_invariant(r - l);

    while (l < r) {
        long long m = (l + r) / 2;
        if (len2(m) < k)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

long long biser1(long long k, long long l, long long r) {
    // Check the range invariant
    check_biser_range_invariant(r - l);

    while (l < r) {
        long long m = (l + r) / 2;
        if (len1(m) < k)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        long long b2 = biser2(k, 1, 510000000);
        k = k - len2(b2 - 1);
        long long b1 = biser1(k, 1, 1e18);
        k = k - len1(b1 - 1);
        long long l = le(b1);
        for (long long i = 0; i < l - k; i++) b1 /= 10;
        cout << b1 % 10 << endl;
    }
}