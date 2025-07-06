#include <bits/stdc++.h>
using namespace std;

int n, k;
long long int fact[400005];

void init() {
    fact[0] = 1;
    for (int i = 1; i < 400005; i++) {
        fact[i] = (fact[i - 1] * i) % 998244353;
    }
}

long long int modexp(long long int x, long long int power) {
    if (power == 0) return 1;
    else {
        if (power % 2 != 0)
            return (x * modexp((x * x) % 998244353, power / 2)) % 998244353;
        else
            return (modexp((x * x) % 998244353, power / 2)) % 998244353;
    }
}

long long int modinv(long long int num) { return modexp(num, 998244353 - 2); }

long long int comb(long long int N, long long int K) {
    long long int n1 = fact[N];
    long long int k1 = fact[K];
    long long int n_k = fact[N - K];
    long long int res = (((n1 * modinv(k1)) % 998244353) * modinv(n_k)) % 998244353;
    return res;
}

long long int stirling(long long int N, long long int K) {
    long long int ans = 0;
    for (int i = 0; i <= K; i++) {
        long long int temp = (comb(K, i) * modexp(K - i, n)) % 998244353;
        if (i % 2 == 0) ans += temp;
        else ans -= temp;
        ans = (ans + 998244353) % 998244353;
    }
    ans = (ans * modinv(fact[K])) % 998244353;
    return ans;
}

void check_factorial_invariant(int n, int k) {
    if (n > 100000 && k < n / 1000) {
        cerr << "Warning: Factorial initialization overhead due to large n and small k." << endl;
        abort();
    }
}

void check_modexp_invariant(int n, int k) {
    if (n > 100000 && k < n / 500) {
        cerr << "Warning: Excessive recursive depth in modular exponentiation." << endl;
        abort();
    }
}

void check_stirling_invariant(int n, int k) {
    if (n > 100000 && n - k > n / 2) {
        cerr << "Warning: High iteration count in Stirling and combinatorial calculations." << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    // Check performance-characterizing invariants
    check_factorial_invariant(n, k);
    check_modexp_invariant(n, k);
    check_stirling_invariant(n, k);
    
    if (k > n - 1) {
        cout << 0 << endl;
        return 0;
    }
    
    init();
    
    long long int res = 0;
    long long int c = n - k;
    res = (res + 2 * (((comb(n, c) * stirling(n, c)) % 998244353) * fact[c]) % 998244353) % 998244353;
    
    if (k == 0) {
        res = fact[n];
    }
    
    cout << res << endl;
    return 0;
}