#include <bits/stdc++.h>
using namespace std;

long long md = 998244353LL;
long long inf;

long long modpow(long long x, long long n, long long m) {
    if (n == 0) return 1LL % m;
    long long u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

// Phase 3: Checkers
void check_power_invariant(long long n, long long k) {
    if (n > 100000 && k < n / 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive power calculations!" << endl;
        abort();
    }
}

void check_factorial_invariant(long long n, long long k) {
    if (n > 100000 && k < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - expensive factorial computations!" << endl;
        abort();
    }
}

void check_loop_invariant(long long n, long long k) {
    if (n > 100000 && k < n / 5000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    inf = md * md;
    inf *= 8;
    inf++;
    int test = 1;
    for (int t = 1; t <= test; t++) {
        long long n, k;
        cin >> n >> k;
        
        // Phase 4: Insert checkers
        check_power_invariant(n, k); // Check for power calculation bottleneck
        check_factorial_invariant(n, k); // Check for factorial computation bottleneck
        check_loop_invariant(n, k); // Check for loop iteration bottleneck

        if (k > n) {
            cout << 0 << endl;
            continue;
        }
        if (k == n) {
            cout << 1 << endl;
            continue;
        }
        long long fac[n + 1];
        fac[0] = 1LL;
        long long i = 1;
        while (i <= n) {
            fac[i] = (fac[i - 1] * i) % md;
            i++;
        }
        i = 1;
        long long ans = 0;
        while (i <= n) {
            if ((n / i) < k) break;
            long long z = ((fac[(n / i) - 1] * modpow(fac[k - 1], md - 2, md) % md) *
                           modpow(fac[(n / i) - k], md - 2, md)) %
                          md;
            ans = (ans + z) % md;
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}