#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)

long long modpow(long long a, long long b, long long m) {
    long long p = 1, q = a;
    for (int i = 0; i < 31; i++) {
        if ((b / (1LL << i)) % 2 == 1) {
            p *= q;
            p %= m;
        }
        q *= q;
        q %= m;
    }
    return p;
}

void check_modpow_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive modular exponentiation!" << endl;
        abort();
    }
}

void check_lagrange_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - Lagrange interpolation invoked!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - nested loop complexity due to large K!" << endl;
        abort();
    }
}

void check_execution_path_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - conditional execution path with high N!" << endl;
        abort();
    }
}

long long mod = 1000000007;
long long N, K, fact[5009], factinv[5009], modpows[5009];

void init() {
    fact[0] = 1;
    for (int i = 1; i <= 5006; i++) fact[i] = (1LL * fact[i - 1] * i) % mod;
    for (int i = 0; i <= 5006; i++) factinv[i] = modpow(fact[i], mod - 2, mod);
}

long long ncr(long long n, long long r) {
    long long e = 1;
    for (long long i = n; i >= n - r + 1; i--) {
        e *= i;
        e %= mod;
    }
    return e * factinv[r] % mod;
}

long long Lagrange(long long pos, vector<pair<long long, long long>> vec) {
    long long sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        long long v1 = 1, v2 = 1;
        for (int j = 0; j < vec.size(); j++) {
            if (i == j) continue;
            v1 *= (pos - vec[j].first + mod) % mod;
            v1 %= mod;
            v2 *= (vec[i].first - vec[j].first + mod) % mod;
            v2 %= mod;
        }
        long long v = v1 * modpow(v2, mod - 2, mod) % mod;
        v *= vec[i].second;
        v %= mod;
        sum += v;
        sum %= mod;
    }
    return sum;
}

int main() {
    init();
    cin >> N >> K;

    // Check if the execution path will trigger Lagrange polynomial interpolation
    check_execution_path_invariant(N > K + 1);

    for (int i = 0; i <= 5006; i++) modpows[i] = modpow(i, K, mod);

    if (N < K + 1) {
        long long V = 0;
        for (int i = 1; i <= N; i++) {
            V += ncr(N, i) * modpow(i, K, mod);
            V %= mod;
        }
        cout << V << endl;
    } else {
        vector<pair<long long, long long>> vec;

        // Check for nested loop complexity due to large K
        check_nested_loop_invariant(K > 100); // Example threshold for large K

        for (int t = 1; t <= K + 1; t++) {
            long long s = 0, v = 1;
            for (int i = 1; i <= t; i++) {
                v *= (t + 1LL - 1LL * i);
                v %= mod;
                s += (v * factinv[i] % mod) * modpows[i];
                s %= mod;
            }
            s *= modpow(modpow(2, t, mod), mod - 2, mod);
            s %= mod;
            vec.push_back(make_pair(t, s));
        }

        // Check if Lagrange interpolation becomes a bottleneck
        check_lagrange_invariant(vec.size() > 10); // Example threshold for vec size

        long long e = Lagrange(N, vec);
        e *= modpow(2, N, mod);
        e %= mod;
        cout << e << endl;
    }
    return 0;
}