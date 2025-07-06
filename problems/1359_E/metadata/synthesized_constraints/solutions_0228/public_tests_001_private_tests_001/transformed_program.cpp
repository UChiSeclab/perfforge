#include <bits/stdc++.h>
using namespace std;
int const MAXn = 5e5 + 2, MOD = 998244353;
long long fact[MAXn];

long long qp(long long a, long long e) {
    if (e == 0) return 1;
    if (e == 1) return a;
    if (!(e & 1)) {
        a = qp(a, e / 2);
        return a * a % MOD;
    }
    return a * qp(a, e - 1) % MOD;
}

void check_large_n_and_single_k(int n, int k) {
    if (n > 100000 && k == 1) {
        cerr << "Warning: Performance bottleneck - large n with single k!" << endl;
        abort();
    }
}

void check_recursive_exponentiation(int x) {
    if (x > 10000) {
        cerr << "Warning: Performance bottleneck - frequent large exponentiations!" << endl;
        abort();
    }
}

void check_expensive_factorial_computation(long long i, long long n) {
    if (i > 100000 && n > 100000) {
        cerr << "Warning: Performance bottleneck - expensive factorial computation!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    // Insert checker for large n with single k
    check_large_n_and_single_k(n, k);
    
    if (k > n) {
        cout << 0 << "\n";
        return 0;
    }
    
    fact[0] = 1;
    for (long long i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        // Insert checker for expensive factorial computation
        check_expensive_factorial_computation(i, n);
    }
    
    long long sol = 0;
    for (int i = 1; i <= n; i++) {
        long long x = n / i;
        if (x < k) break;
        
        // Insert checker for recursive exponentiation
        check_recursive_exponentiation(x);
        
        sol = (sol + (fact[x - 1] *
                      qp(fact[x - 1 - (k - 1)] * fact[k - 1] % MOD, MOD - 2) % MOD)) % MOD;
    }
    
    cout << sol << "\n";
    return 0;
}