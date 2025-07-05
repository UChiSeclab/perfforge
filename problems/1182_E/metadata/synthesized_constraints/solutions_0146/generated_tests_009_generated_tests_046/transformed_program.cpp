#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_factorization_invariant(set<int>& primes) {
    if (primes.size() > 20) { // Example threshold
        cerr << "Warning: factorization_invariant triggered - too many distinct prime factors" << endl;
        abort();
    }
}

void check_matrix_invariant(int n, int m) {
    if (n * m > 1000) { // Example threshold for matrix dimension product
        cerr << "Warning: matrix_invariant triggered - potentially large matrix operations" << endl;
        abort();
    }
}

void check_modulo_invariant(long long value) {
    if (value > 1000000000) { // Example large value threshold
        cerr << "Warning: modulo_invariant triggered - large value used in modulo operation" << endl;
        abort();
    }
}

struct mat {
    int n, m;
    long long c[50][5];
    long long* operator[](int x) { return c[x]; }
    mat(int N = 0, int M = 0) {
        n = N;
        m = M;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) c[i][j] = 0;
    }
};

mat operator*(mat a, mat b) {
    mat r(a.n, b.m);
    for (int i = 1; i <= a.n; i++)
        for (int j = 1; j <= b.m; j++)
            for (int k = 1; k <= a.m; k++) {
                r[i][j] += (a[i][k] * b[k][j]);
                r[i][j] %= (1000000007ll - 1);
            }
    return r;
}

long long binpow(long long x, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return binpow((x * x) % 1000000007ll, n / 2);
    return (x * binpow(x, n - 1)) % 1000000007ll;
}

mat binpow(mat x, long long n) {
    if (n == 1) return x;
    if (n % 2 == 0) return binpow(x * x, n / 2);
    return x * binpow(x, n - 1);
}

long long n, c, f[4], x, ans = 1, prime;
int k;
mat p, e;
set<int> primes;
map<int, int> ind;
vector<int> pr;

void factor(long long x) {
    prime = 2;
    if (x % prime == 0) {
        primes.insert(prime);
        while (x % prime == 0) x /= prime;
    }
    prime = 3;
    while (prime * prime <= x) {
        if (x % prime == 0) {
            primes.insert(prime);
            while (x % prime == 0) x /= prime;
        }
        prime += 2;
    }
    if (x > 1) primes.insert(x);
}

void tuft(long long x, int t) {
    long long prime = 2;
    if (x % prime == 0) {
        while (x % prime == 0) {
            x /= prime;
            p[ind[prime]][t]++;
        }
    }
    prime = 3;
    while (prime * prime <= x) {
        if (x % prime == 0) {
            while (x % prime == 0) {
                x /= prime;
                p[ind[prime]][t]++;
            }
        }
        prime += 2;
    }
    if (x > 1) p[ind[x]][t]++;
}

int main() {
    cin >> n >> f[1] >> f[2] >> f[3] >> c;
    factor(f[1]);
    factor(f[2]);
    factor(f[3]);
    factor(c);
    check_factorization_invariant(primes); // Check prime factorization invariant

    pr.push_back(0);
    while (!primes.empty()) {
        k++;
        ind[(*primes.begin())] = k;
        pr.push_back((*primes.begin()));
        primes.erase((*primes.begin()));
    }
    p = mat(k, 3);
    tuft(f[1], 1);
    tuft(c, 1);
    tuft(f[2], 2);
    tuft(c, 2);
    tuft(c, 2);
    tuft(f[3], 3);
    tuft(c, 3);
    tuft(c, 3);
    tuft(c, 3);

    e = mat(3, 3);
    e[2][1] = 1;
    e[3][2] = 1;
    e[1][3] = 1;
    e[2][3] = 1;
    e[3][3] = 1;

    check_matrix_invariant(e.n, e.m); // Check matrix invariant

    p = p * binpow(e, n - 1);

    for (int i = 1; i <= k; i++) {
        ans *= binpow(pr[i], p[i][1]);
        ans %= 1000000007ll;
    }
    
    long long c_pow_n = binpow(c, n);
    check_modulo_invariant(c_pow_n); // Check modulo invariant

    ans *= binpow(c_pow_n, 1000000007ll - 2);
    ans %= 1000000007ll;
    cout << ans << endl;
    return 0;
}