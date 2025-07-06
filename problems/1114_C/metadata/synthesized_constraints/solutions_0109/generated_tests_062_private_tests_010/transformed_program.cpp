#include <bits/stdc++.h>
using namespace std;
const long long maxn = (long long)1e9 + 7;
const long double EPS = 1e-9;
const long long INF = (long long)1e18 + 18;
const long long mod = (long long)1e9 + 7;

// Checker function for performance bottleneck
void check_factorization_invariant(long long b, int threshold) {
    int factor_count = 0;
    for (long long i = 2; i <= sqrt(b); i++) {
        while (b % i == 0) {
            factor_count++;
            b /= i;
        }
    }
    if (b > 1) {  // if there's any prime factor left
        factor_count++;
    }
    if (factor_count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many factors!" << endl;
        abort();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, q;
    cin >> n >> q;
    long long ans = n;
    long long b = q;

    // Insert checker before main loop to avoid overhead in tight loops
    check_factorization_invariant(b, 50);  // Arbitrary threshold, can be tuned based on tests

    for (long long i = 2; i <= sqrt(q); i++) {
        if (b % i == 0) {
            long long p = 0;
            while (b % i == 0) {
                p++;
                b /= i;
            }
            long long c = 0;
            long long k = n;
            while (k / i > 0) {
                c += k / i;
                k /= i;
            }
            ans = min(ans, c / p);
        }
    }
    if (b >= 2) {
        long long c = 0;
        long long k = n;
        while (k / b > 0) {
            c += k / b;
            k /= b;
        }
        ans = min(ans, c);
    }
    cout << ans << '\n';
}