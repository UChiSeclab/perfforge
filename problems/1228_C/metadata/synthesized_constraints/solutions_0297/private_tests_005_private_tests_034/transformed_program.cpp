#include <bits/stdc++.h>
using namespace std;

void check_prime_factorization_invariant(unsigned long long x) {
    int num_small_factors = 0;
    unsigned long long c = x;
    if (c % 2 == 0) {
        num_small_factors++;
        while (c % 2 == 0) c /= 2;
    }
    for (unsigned long long i = 3; i <= sqrt(x); i += 2) {
        if (c % i == 0) {
            num_small_factors++;
            while (c % i == 0) c /= i;
        }
    }
    if (c > 2) num_small_factors++; // Remaining prime factor
    if (num_small_factors > 5) { 
        cerr << "Warning: Performance bottleneck due to excessive prime factors in x!" << endl;
        abort();
    }
}

void check_large_n_invariant(unsigned long long n) {
    unsigned long long threshold = 1000000000000000000ULL;
    if (n >= threshold) {
        cerr << "Warning: Performance bottleneck due to large n!" << endl;
        abort();
    }
}

int main() {
    unsigned long long int n, x, i, j, ans = 1, c, s, k;
    unsigned long long int p[1000];
    k = 0;
    cin >> x >> n;

    // Integrate checkers after input
    check_prime_factorization_invariant(x);
    check_large_n_invariant(n);

    c = x;
    if (c % 2 == 0) p[k++] = 2;
    while (c % 2 == 0) c /= 2;
    for (i = 3; i <= sqrt(x); i++) {
        if (c % i == 0) p[k++] = i;
        while (c % i == 0) c /= i;
    }
    if (c > 2) p[k++] = c;
    for (i = 0; i < k; i++) {
        c = p[i];
        s = 0;
        while (c <= n) {
            s += (n / c);
            s %= (1000000007 - 1);
            if (c > (n / p[i])) break;
            c *= p[i];
        }
        while (s > 0) {
            if (s % 2 == 1) ans = (ans * p[i]) % 1000000007;
            s /= 2;
            p[i] = (p[i] * p[i]) % 1000000007;
        }
    }
    cout << ans << endl;
    return 0;
}