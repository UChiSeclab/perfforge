#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b > a) {
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long expo(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}

void extendgcd(long long a, long long b, long long *v) {
    if (b == 0) {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    long long x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
}

long long mminv(long long a, long long b) {
    long long arr[3];
    extendgcd(a, b, arr);
    return arr[0];
}

long long mminvprime(long long a, long long b) {
    return expo(a, b - 2, b);
}

void swap(long long &x, long long &y) {
    long long temp = x;
    x = y;
    y = temp;
}

long long combination(long long n, long long r, long long m, long long *fact, long long *ifact) {
    long long val1 = fact[n];
    long long val2 = ifact[n - r];
    long long val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}

void google(long long t) {
    cout << "Case #" << t << ": ";
}

vector<long long> sieve(long long n) {
    long long *arr = new long long[n + 1]();
    vector<long long> vect;
    for (long long i = 2; i <= n; i++)
        if (arr[i] == 0) {
            vect.push_back(i);
            for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
        }
    return vect;
}

long long mod_add(long long a, long long b, long long m) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}

long long mod_mul(long long a, long long b, long long m) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}

long long mod_sub(long long a, long long b, long long m) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

long long mod_div(long long a, long long b, long long m) {
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}

long long phin(long long n) {
    long long number = n;
    if (n % 2 == 0) {
        number /= 2;
        while (n % 2 == 0) n /= 2;
    }
    for (long long i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1) number = (number / n * (n - 1));
    return number;
}

void c_p_c() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const long long N = 200000;
long long fact[N + 1];

long long comb(long long a, long long b) {
    return mod_div(mod_div(fact[a], fact[b], 998244353), fact[a - b], 998244353);
}

// Checker functions
void check_large_n_small_k(long long n, long long k) {
    if (n > 100000 && k < n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large n with small k!" << endl;
        abort();
    }
}

void check_extensive_combinatorial_calculation(long long n, long long k) {
    if (n > 100000 && k < n / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive combinatorial calculations!" << endl;
        abort();
    }
}

void check_iterative_exponentiation(long long n, long long k) {
    if (n > 100000 && k < n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large iterative exponentiation!" << endl;
        abort();
    }
}

void check_factorial_precomputation(long long n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - large factorial precomputation!" << endl;
        abort();
    }
}

int32_t main() {
    c_p_c();
    long long n, k;
    cin >> n >> k;

    // Integrating performance checks
    check_large_n_small_k(n, k);
    check_extensive_combinatorial_calculation(n, k);
    check_iterative_exponentiation(n, k);
    check_factorial_precomputation(n);

    if (k >= n) {
        cout << 0 << endl;
        return 0;
    }
    fact[0] = 1;
    for (long long i = 1; i <= n; i++)
        fact[i] = mod_mul(fact[i - 1], i, 998244353);
    long long ans = 0;
    long long place = n - k;
    for (long long i = 0; i <= place; i++) {
        long long sa = comb(place, i);
        sa = mod_mul(sa, expo(place - i, n, 998244353), 998244353);
        if (i & 1)
            ans = mod_sub(ans, sa, 998244353);
        else
            ans = mod_add(ans, sa, 998244353);
    }
    ans = mod_mul(ans, comb(n, place), 998244353);
    if (k != 0) ans = mod_mul(ans, 2, 998244353);
    cout << ans << endl;
}