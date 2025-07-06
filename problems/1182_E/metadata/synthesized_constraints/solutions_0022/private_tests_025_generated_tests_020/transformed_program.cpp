#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7 - 1;

struct matrix {
    long long a[N][N];
    int n;
    matrix() {}
    matrix(int k) {
        n = k;
        memset(a, 0, sizeof(a));
    }
    void init() {
        for (int i = 0; i < n; i++) a[i][i] = 1;
    }
    matrix operator*(const matrix &B) {
        matrix C(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]) % mod;
        return C;
    }
    matrix operator^(long long k) {
        matrix A = (*this), res(n);
        res.init();
        while (k) {
            if (k & 1) res = res * A;
            A = A * A;
            k >>= 1;
        }
        return res;
    }
    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

vector<long long> pri[4];
long long f[4];

vector<long long> get(long long n) {
    vector<long long> p;
    size_t divisor_count = 0;  // Track the number of divisor findings
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            p.push_back(i);
            ++divisor_count;
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) p.push_back(n);
    check_prime_factorization_invariant(divisor_count);  // Check for excessive divisors
    return p;
}

long long qpow(long long n, long long k, long long p) {
    long long res = 1;
    size_t division_count = 0;  // Track the number of divisions in the loop
    while (k) {
        if (k & 1) res = res * n % p;
        n = n * n % p;
        k >>= 1;
        ++division_count;
    }
    check_repeated_division_invariant(division_count);  // Check for excessive divisions
    return res;
}

int main() {
    long long n, c;
    cin >> n;
    check_matrix_exponentiation_invariant(n);  // Check for large n before matrix power
    for (int i = 1; i <= 3; i++) cin >> f[i], pri[i] = get(f[i]);
    cin >> c;
    matrix a(5);
    for (int i = 0; i < 4; i++) a.a[0][i] = 1;
    a.a[1][0] = a.a[2][1] = 1;
    a.a[3][3] = 1, a.a[3][4] = 2;
    a.a[4][4] = 1;
    a = a ^ (n - 3);
    vector<long long> p;
    for (int i = 1; i <= 3; i++)
        for (long long j : pri[i]) p.push_back(j);
    for (long long j : get(c)) p.push_back(j);
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    long long ans = 1;
    for (long long x : p) {
        long long tem = 0;
        for (int i = 1; i <= 3; i++) {
            int t = 0;
            long long ff = f[i];
            while (ff % x == 0) t++, ff /= x;
            tem += t * a.a[0][3 - i] % mod;
            tem %= mod;
        }
        int t = 0;
        long long ff = c;
        while (ff % x == 0) t++, ff /= x;
        tem += a.a[0][3] * 2 * t % mod;
        tem %= mod;
        tem += a.a[0][4] * t % mod;
        tem %= mod;
        ans = ans * qpow(x, tem, mod + 1) % (mod + 1);
    }
    cout << ans << endl;
}