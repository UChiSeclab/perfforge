#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

void check_recursion_invariant(long long k) {
    if (k > 100000) { // Arbitrary threshold for large k
        cerr << "Warning: Performance bottleneck condition triggered - high branching and recursion due to large k!" << endl;
        abort();
    }
}

void check_combination_invariant(int n) {
    if (n > 200) { // Threshold for large n close to the upper limit
        cerr << "Warning: Performance bottleneck condition triggered - excessive combination calculations for large n!" << endl;
        abort();
    }
}

void check_recursive_growth_invariant(int n, long long k) {
    if (n > 200 && k > 100000) { // Combined effect of large n and k
        cerr << "Warning: Performance bottleneck condition triggered - exponential growth in recursive call tree!" << endl;
        abort();
    }
}

long long POW(long long a, long long b, long long MMM = MOD) {
    long long ret = 1;
    for (; b; b >>= 1, a = (a * a) % MMM)
        if (b & 1) ret = (ret * a) % MMM;
    return ret;
}

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return a + b;
    return a * (b / gcd(a, b));
}

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int ddx[] = {2, 2, -2, -2, 1, 1, -1, -1}, ddy[] = {1, -1, 1, -1, 2, -2, 2, -2};

long long fac[301];
long long inv[301];
long long powk[301], powk1[301];

int n;
long long k;

long long nCr(int n, int r) {
    if (r > n) return 0;
    long long c = fac[n];
    c = (c * inv[r]) % MOD;
    c = (c * inv[n - r]) % MOD;
    return c;
}

long long d[255][255];

long long go(int N, int c) {
    if (N == n) {
        return c == n;
    }
    long long &ret = d[N][c];
    if (~ret) return ret;
    ret = 0;
    if (c > 0) {
        long long cc = powk[c] - powk1[c];
        if (cc < 0) cc += MOD;
        cc = (cc * powk1[n - c]) % MOD;
        ret = (ret + cc * go(N + 1, c)) % MOD;
    }
    for (int i = 1; i <= (n - c); i++) {
        long long cc = nCr(n - c, i);
        cc = (cc * powk1[n - c - i]) % MOD;
        cc = (cc * powk[c]) % MOD;
        ret = (ret + cc * go(N + 1, c + i)) % MOD;
    }
    return ret;
}

int main() {
    memset((d), -1, sizeof(d));
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 300; i++) fac[i] = (fac[i - 1] * i) % MOD;
    inv[300] = POW(fac[300], MOD - 2);
    for (int i = 299; i >= 1; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    scanf("%d%lld", &n, &k);

    // Place checkers after reading inputs
    check_recursion_invariant(k);
    check_combination_invariant(n);
    check_recursive_growth_invariant(n, k);

    powk[0] = powk1[0] = 1;
    for (int i = 1; i <= 300; i++) {
        powk[i] = (powk[i - 1] * k) % MOD;
        powk1[i] = (powk1[i - 1] * (k - 1)) % MOD;
    }
    if (n == 1 || k == 1) return !printf("1");
    printf("%lld", go(0, 0));
}