#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int MOD = 998244353;
int fact[105];
int inv[105];

void check_divisor_count_invariant(size_t divisorCount) {
    if (divisorCount > 100000) {
        cerr << "Warning: High divisor count invariant triggered - potential performance bottleneck." << endl;
        abort();
    }
}

void check_prime_factorization_depth_invariant(size_t factorizationDepth) {
    if (factorizationDepth > 100) {
        cerr << "Warning: High factorization depth invariant triggered - potential performance bottleneck." << endl;
        abort();
    }
}

int lgput(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = 1LL * ans * a % MOD;
        a = 1LL * a * a % MOD;
    }
    return ans;
}
map<long long, int> ways;
long long gcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    long long d;
    scanf("%lld", &d);
    vector<long long> div;
    for (int i = 1; 1LL * i * i <= d; ++i) {
        if (d % i == 0) {
            div.push_back(i);
            if (d / i != i) div.push_back(d / i);
        }
    }

    // Check for high divisor count
    check_divisor_count_invariant(div.size());

    vector<long long> pr;
    for (int i = 2; 1LL * i * i <= d; ++i) {
        if (d % i == 0) {
            pr.push_back(i);
            while (d % i == 0) d /= i;
        }
    }
    if (d > 1) pr.push_back(d);

    // Check for high prime factorization depth
    check_prime_factorization_depth_invariant(pr.size());

    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
    inv[MAXN] = lgput(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; --i) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
    for (auto it : div) {
        int nr = 1;
        long long aux = it;
        int dd = 0;
        for (auto it1 : pr) {
            int d1 = 0;
            while (aux % it1 == 0) {
                d1++;
                aux /= it1;
            }
            dd += d1;
            nr = 1LL * nr * inv[d1] % MOD;
        }
        nr = 1LL * nr * fact[dd] % MOD;
        ways[it] = nr;
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        long long u, v;
        scanf("%lld%lld", &u, &v);
        long long g = gcd(u, v);
        int ans1 = ways[u / g];
        int ans2 = ways[v / g];
        printf("%d\n", 1LL * ans1 * ans2 % MOD);
    }
    return 0;
}