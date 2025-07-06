#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
long long int spf[MAXN];

long long int mpow(long long int x, long long int y) {
    long long int res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

void sieve() {
    spf[1] = 1;
    for (long long int i = 2; i < MAXN; i++) spf[i] = i;
    for (long long int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (long long int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

// Checkers for performance invariants
void check_exponentiation_invariant(long long cnt) {
    if (cnt > 50) {
        cerr << "Warning: Exponentiation invariant triggered - large exponent in mpow." << endl;
        abort();
    }
}

void check_divisors_invariant(long long mx) {
    if (mx > 50000) {
        cerr << "Warning: Divisors invariant triggered - high number of divisor computations." << endl;
        abort();
    }
}

void check_nested_loops_invariant(long long mx) {
    if (mx > 50000) {
        cerr << "Warning: Nested loops invariant triggered - heavy computation in loops." << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int T = clock();
    long long int n;
    sieve();
    cin >> n;
    vector<long long int> a(n);
    long long int mx = 0;
    set<long long int> s;
    map<long long int, long long int> mpp;
    for (long long int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        s.insert(a[i]);
        mpp[a[i]]++;
    }
    
    // Check for divisor-heavy operations
    check_divisors_invariant(mx);
    
    long long int ans = mpow(2, n) - 1;
    vector<long long int> f(100005);
    for (long long int i = mx; i >= 2; i--) {
        long long int cnt = 0, sub = 0;
        for (long long int j = i; j <= mx; j += i) {
            cnt += mpp[j];
            sub += f[j];
        }
        
        // Check for large exponentiations
        check_exponentiation_invariant(cnt);
        
        f[i] = (mpow(2, cnt) - 1 - sub + mod) % mod;
        ans = (ans - f[i] + mod) % mod;
    }

    // Check for high computational loops
    check_nested_loops_invariant(mx);
    
    cout << ans;
    cerr << "\n\nTIME: " << (double)(clock() - T) / CLOCKS_PER_SEC << " sec\n";
    T = clock();
    return 0;
}