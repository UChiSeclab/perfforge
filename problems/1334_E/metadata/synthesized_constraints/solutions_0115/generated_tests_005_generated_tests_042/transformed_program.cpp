#include <bits/stdc++.h>
using namespace std;

// Checker Functions
void check_sieve_invariant(long long nn) {
    if (nn > 1000000) {
        cerr << "Warning: Performance bottleneck - large nn for sieve computation!" << endl;
        abort();
    }
}

void check_factorization_invariant(size_t factor_count) {
    if (factor_count > 100000) {
        cerr << "Warning: Performance bottleneck - too many factors to process!" << endl;
        abort();
    }
}

void check_prime_factorization_invariant(size_t prime_factor_count) {
    if (prime_factor_count > 100) {
        cerr << "Warning: Performance bottleneck - too many prime factors for map construction!" << endl;
        abort();
    }
}

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void mad(long long &a, long long b) {
    a = (a + b) % 998244353;
    if (a < 0) a += 998244353;
}
long long gcd(long long a, long long b) {
    if (!a) return b;
    return gcd(b % a, a);
}
vector<long long> prime;
bool isnotp[40000000];
void sieve(long long n) {
    for (long long i = 2; i <= n; i++) {
        if (isnotp[i]) continue;
        for (long long j = i + i; j <= n; j += i) {
            isnotp[j] = 1;
        }
        prime.push_back(i);
    }
}
long long powmod(long long a, long long b) {
    if (b == 0) return 1;
    long long c = powmod(a, b / 2ll);
    c = ((c * c) % 998244353 * ((b & 1ll) ? a : 1ll)) % 998244353;
    return c;
}
map<long long, map<long long, int> > mp;
void solve() {
    long long n;
    cin >> n;
    long long nn = sqrt(n);

    // Check sieve invariant
    check_sieve_invariant(nn);

    sieve(nn);
    vector<long long> factors, pf;
    for (long long i = 1; i <= nn; i++) {
        if (n % i) continue;
        factors.push_back(i);
        if (i * i != n) factors.push_back(n / i);
    }

    // Check factorization invariant
    check_factorization_invariant(factors.size());

    long long m = n;
    for (long long i : prime) {
        if (i * i > m) break;
        if (m % i == 0) pf.push_back(i);
        while (m % i == 0) {
            m /= i;
        }
    }
    if (m > 1) pf.push_back(m);

    // Check prime factorization invariant
    check_prime_factorization_invariant(pf.size());

    sort(factors.begin(), factors.end());
    sort(pf.begin(), pf.end());
    int q;
    cin >> q;
    for (long long i : factors) {
        long long f = i;
        for (long long j : pf) {
            int cnt = 0;
            while (f % j == 0) {
                f /= j;
                cnt++;
            }
            mp[i][j] = cnt;
        }
    }
    long long fact[100], ifact[100];
    fact[0] = 1;
    ifact[0] = 1;
    for (long long i = 1; i < 100; i++) {
        fact[i] = (fact[i - 1] * i) % 998244353;
        ifact[i] = (powmod(fact[i], 998244353 - 2));
    }
    while (q--) {
        long long u, v;
        cin >> u >> v;
        long long ans1 = 1, ans2 = 1, ans = 1;
        long long sum1 = 0, sum2 = 0;
        long long g = gcd(u, v);
        for (long long i : pf) {
            long long dif = max(0, (mp[v][i] - mp[g][i]));
            sum1 += dif;
            ans1 = (ans1 * ifact[dif]) % 998244353;
        }
        for (long long i : pf) {
            long long dif = max(0, (mp[u][i] - mp[g][i]));
            sum2 += dif;
            ans2 = (ans2 * ifact[dif]) % 998244353;
        }
        ans1 = (ans1 * fact[sum1]) % 998244353;
        ans2 = (ans2 * fact[sum2]) % 998244353;
        ans = (ans1 * ans2) % 998244353;
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}