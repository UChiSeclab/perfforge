#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long mul(long long a, long long b) { return a * b % mod; }
long long binpow(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = mul(ans, a);
        }
        b >>= 1;
        a = mul(a, a);
    }
    return ans;
}
long long div(long long a) { return binpow(a, mod - 2); }
long long fact[10000];
long long precalk[200];

void check_large_d(long long sqrd, long long d) {
    if (sqrd > 1000000) {  // Arbitrary large threshold for demonstration
        cerr << "Warning: Performance bottleneck detected due to large D with many divisors" << endl;
        abort();
    }
}

void check_prime_factorization(long long num_factors) {
    if (num_factors > 100) {  // Assuming a high number of factors is problematic
        cerr << "Warning: Performance bottleneck detected in prime factorization process" << endl;
        abort();
    }
}

void check_large_query_inputs(long long v, long long u, long long d) {
    if (v > d / 1000 || u > d / 1000) {  // Threshold based on a portion of D
        cerr << "Warning: Performance bottleneck detected due to large query inputs" << endl;
        abort();
    }
}

signed main() {
    fact[0] = 1;
    for (long long i = 1; i < 10000; i++) {
        fact[i] = mul(i, fact[i - 1]);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long d;
    cin >> d;
    long long sqrd = 2;
    for (; sqrd * sqrd <= d; sqrd++) {
    }
    
    // Check for large D
    check_large_d(sqrd, d);

    vector<long long> p;
    for (long long i = 2; i <= sqrd; i++) {
        if (d % i == 0) {
            p.push_back(i);
            while (d % i == 0) {
                d /= i;
            }
        }
    }
    
    if (d != 1) {
        p.push_back(d);
    }
    
    long long n = p.size();
    
    // Check for problematic number of prime factors
    check_prime_factorization(n);
    
    for (long long i = 0; i < 200; i++) {
        precalk[i] = div(fact[i]);
    }
    long long q;
    cin >> q;
    long long v, u;
    for (long long c = 0; c < q; c++) {
        cin >> v >> u;

        // Check for large query inputs
        check_large_query_inputs(v, u, d);

        vector<long long> p1(n), p2(n);
        for (long long j = 0; j < n; j++) {
            while (v % p[j] == 0) {
                p1[j]++;
                v /= p[j];
            }
            while (u % p[j] == 0) {
                p2[j]++;
                u /= p[j];
            }
        }
        long long s1 = 0;
        long long s2 = 0;
        vector<long long> v1(n, 0), v2(n, 0);
        for (long long i = 0; i < n; i++) {
            if (p1[i] > p2[i]) {
                s1 += p1[i] - p2[i];
                v1[i] = p1[i] - p2[i];
            } else {
                s2 += p2[i] - p1[i];
                v2[i] = p2[i] - p1[i];
            }
        }
        long long ans = mul(fact[s1], fact[s2]);
        for (long long i = 0; i < n; i++) {
            if (v1[i] != 0) {
                ans = mul(ans, precalk[v1[i]]);
            }
            if (v2[i] != 0) {
                ans = mul(ans, precalk[v2[i]]);
            }
        }
        cout << ans << '\n';
    }
}