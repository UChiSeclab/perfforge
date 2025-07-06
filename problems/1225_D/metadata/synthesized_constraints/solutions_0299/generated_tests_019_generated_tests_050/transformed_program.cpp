#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, k, total[N], MinP[N], p[N], A[N];
long long a, x, y, ans;

// Function for fast exponentiation
inline int quick_pow(long long v, int c) {
    long long res = 1;
    while (c) {
        if (c & 1) res *= v;
        if (v > 100000) return v;
        v *= v;
        c >>= 1;
        if (res > 100000) break;
    }
    quick_pow_call_count++; // Track calls to quick_pow
    return res;
}

// Checkers from phase 3
void check_max_invariant(int Max) {
    if (Max > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large Max value!" << endl;
        abort();
    }
}

void check_prime_factorization_invariant(int Max, int* p) {
    int distinctPrimes = 0;
    for (int i = 2; i <= Max; ++i) {
        if (p[i] == i) {
            ++distinctPrimes;
        }
    }
    if (distinctPrimes > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered due to many distinct primes!" << endl;
        abort();
    }
}

void check_quick_pow_invariant() {
    if (quick_pow_call_count > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive quick_pow calls!" << endl;
        abort();
    }
}

// Input function
template <class T>
inline void sd(T& x) {
    char c;
    T y = 1;
    while (c = getchar(), (c < 48 || 57 < c) && c != -1)
        if (c == 45) y = -1;
    x = c - 48;
    while (c = getchar(), 47 < c && c < 58) x = x * 10 + c - 48;
    x *= y;
}

int main() {
    sd(n), sd(k);
    int Max = 1;
    
    for (register int i = 1; i <= n; ++i) {
        sd(A[i]);
        Max = max(A[i], Max);
    }
    
    // Perform check after reading inputs and determining Max
    check_max_invariant(Max);
    
    for (register int i = 2; i <= Max; i++) {
        if (p[i] != 0) continue;
        for (register int j = i; j <= Max; j += i) p[j] = i;
    }
    
    // Perform check after filling prime factor array
    check_prime_factorization_invariant(Max, p);
    
    for (register int i = 1; i <= n; ++i) {
        x = y = 1;
        while (A[i] > 1) {
            int j = p[A[i]], cnt = 0;
            while (A[i] % j == 0) A[i] /= j, cnt++;
            cnt %= k;
            x *= quick_pow(j, cnt);
            y *= quick_pow(j, (k - cnt) % k);
            if (y > 100000) break;
        }
        if (y < 100001 && y >= 0) ans += total[y], total[x]++;
    }
    
    // Perform check for excessive calls to quick_pow
    check_quick_pow_invariant();
    
    printf("%lld", ans);
    return 0;
}