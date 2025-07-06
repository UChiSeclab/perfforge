#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

const ll mod = 1e9 + 7;

ll ipow(ll a, ll p) {
    if (p == 0)
        return 1;
    ll ret = ipow(a, p / 2);
    ret = ret * ret % mod;
    if (p & 1)
        ret = ret * a % mod;
    return ret;
}

ll fac[200005];

ll comb(ll n, ll r) {
    return fac[n] * ipow(fac[r], mod - 2) % mod * ipow(fac[n - r], mod - 2) % mod;
}

// Check if ipow might be called excessively for large exponents
void check_recursive_power_invariant(ll n, ll l, ll r) {
    if (n > 100000 || abs(l - r) > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive power calculations!" << endl;
        abort();
    }
}

// Check for potentially excessive loop iterations
void check_loop_range_invariant(ll mn) {
    if (mn > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop range iterations!" << endl;
        abort();
    }
}

// Check for excessive combinatorial calculations
void check_combinatorial_invariant(ll s, ll e, ll n) {
    if ((e - s + 1) > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive combinatorial calculations!" << endl;
        abort();
    }
}

int main() {
    fac[0] = 1;
    for (int i = 1; i < 200005; ++i)
        fac[i] = fac[i - 1] * i % mod;

    int T;
    scanf("%d", &T);
    while (T--) {
        ll n, l, r;
        scanf("%lld %lld %lld", &n, &l, &r);

        // Apply the check for the excessive recursive power calculations
        check_recursive_power_invariant(n, l, r);

        ll mn = min(-l + 1, r - n);
        
        // Apply the check for excessive loop range iterations
        check_loop_range_invariant(mn);

        ll ans = mn % mod * comb(n, n / 2) * (n % 2 + 1) % mod;

        mn++;
        int s = 1, e = n;
        while (true) {
            if (r - 1 < mn || l - n > -mn)
                break;

            while (l - s > -mn)
                s++;
            while (r - e < mn)
                e--;

            int x = n - e, y = s - 1;

            if (x > (n + 1) / 2 || y > (n + 1) / 2)
                break;

            // Apply the combinatorial invariant check
            check_combinatorial_invariant(s, e, n);

            if (n % 2 == 0) {
                if (e - s + 1 <= 0)
                    ans = (ans + 1) % mod;
                else
                    ans = (ans + comb(e - s + 1, n / 2 - x)) % mod;
            } else {
                if (e - s + 1 > 0 && x < (n + 1) / 2 && y < (n + 1) / 2) {
                    ans = (ans + comb(e - s + 1, n / 2 - x + 1)) % mod;
                    ans = (ans + comb(e - s + 1, n / 2 - x)) % mod;
                } else if (x < (n + 1) / 2 || y < (n + 1) / 2)
                    ans = (ans + 1) % mod;
            }

            mn++;
        }

        printf("%lld\n", ans);
    }

    return 0;
}