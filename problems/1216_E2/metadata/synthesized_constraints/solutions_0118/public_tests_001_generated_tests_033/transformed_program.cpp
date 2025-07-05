#include <bits/stdc++.h>

using namespace std;

const long long MAX = 510000;
const long long INF = 1LL << 61;
const long long MOD = 1000000007LL;
const long long mod = 998244353LL;
long long ten[20];

void check_nested_loop_invariant(long long D) {
    if (D > 15) { // Arbitrary threshold for D based on potential slowdowns
        cerr << "Warning: Nested loop invariant triggered - high number of iterations due to large D." << endl;
        abort();
    }
}

void check_binary_search_invariant(long long k) {
    if (k > 1e17) { // Threshold based on input size constraints
        cerr << "Warning: Binary search invariant triggered - large search space required for k." << endl;
        abort();
    }
}

long long sum(long long x) {
    if (x == 0) return 0;
    long long D = to_string(x).size();

    // Check the nested loop invariant
    check_nested_loop_invariant(D);

    long long res = 0;
    for (long long i = 1; i <= D; i++) {
        long long mn = ten[i - 1];
        long long mx = min(ten[i] - 1, x);
        long long n = mx - mn + 1;
        for (long long j = 1; j < i; j++) {
            res += 9 * ten[j - 1] * n * j;
        }
        res += n * (n + 1) / 2 * i;
    }
    return res;
}

long long sum2(long long x) {
    if (x == 0) return 0;
    long long D = to_string(x).size();
    
    // Check the nested loop invariant
    check_nested_loop_invariant(D);

    long long res = 0;
    long long mn = ten[D - 1];
    long long mx = min(ten[D] - 1, x);
    long long n = mx - mn + 1;
    for (long long i = 1; i < D; i++) {
        res += 9 * ten[i - 1] * i;
    }
    res += n * D;
    return res;
}

void solve(long long k) {
    // Check the binary search invariant
    check_binary_search_invariant(k);

    long long l = 0;
    long long r = 1LL << 30;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (sum(m) < k) {
            l = m;
        } else {
            r = m;
        }
    }
    long long k2 = k - sum(l);
    l = 0;
    r = 1LL << 30;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (sum2(m) < k2) {
            l = m;
        } else {
            r = m;
        }
    }
    long long k3 = k2 - sum2(l);
    string s = to_string(r);
    cout << s[k3 - 1] << endl;
}

int main() {
    long long Q;
    scanf("%lld", &Q);
    ten[0] = 1;
    for (long long i = 1; i < 20; i++) {
        ten[i] = ten[i - 1] * 10;
    }
    for (long long loop = 0; loop < Q; loop++) {
        long long k;
        scanf("%lld", &k);
        solve(k);
    }
    return 0;
}