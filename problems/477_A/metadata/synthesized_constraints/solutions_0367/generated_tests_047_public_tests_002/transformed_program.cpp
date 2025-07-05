#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

// Check functions based on performance-characterizing invariants
void check_loop_iteration_threshold(long long b) {
    if (b > 1000000) {
        cerr << "Warning: Performance bottleneck due to high number of loop iterations!" << endl;
        abort();
    }
}

void check_repeated_modulo_calculations(long long b) {
    if (b > 1000000) {
        cerr << "Warning: Performance bottleneck due to repeated modulo calculations!" << endl;
        abort();
    }
}

void check_arithmetic_operations(long long b) {
    if (b > 1000000) {
        cerr << "Warning: Performance bottleneck due to expensive arithmetic operations!" << endl;
        abort();
    }
}

long long power(long long x, long long y, long long m = 1000000000000000007) {
    if (!y) return 1;
    if (y % 2) return x * power(x, y - 1, m) % m;
    long long k = power(x, y / 2, m);
    return k * k % m;
}

vector<vector<long long>> multy(vector<vector<long long>> x, vector<vector<long long>> y, long long m = 1000000000000000007) {
    vector<vector<long long>> z;
    z.resize(x.size());
    for (int i = 0; i < z.size(); ++i) z[i].assign(y[0].size(), 0);
    for (int k = 0; k < y.size(); ++k)
        for (int i = 0; i < x.size(); ++i)
            for (int j = 0; j < y[0].size(); ++j)
                z[i][j] = (z[i][j] + x[i][k] * y[k][j]) % m;
    return z;
}

vector<vector<long long>> power(vector<vector<long long>> x, long long y, long long m = 1000000000000000007) {
    if (y == 1) return x;
    if (y % 2) return multy(x, power(x, y - 1, m), m);
    vector<vector<long long>> k = power(x, y / 2, m);
    return multy(k, k, m);
}

long double power(long double x, long long y) {
    return exp(log(x) * (long double)y);
}

long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }

long long gcdex(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long lcm(long long x, long long y, long long m = 1000000000000000007) {
    return x / gcd(x, y) * y % m;
}

long long phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    if (n > 1) result -= result / n;
    return result;
}

long long rev_el(long long a, long long m) {
    long long x, y;
    long long g = gcdex(a, m, x, y);
    if (g != 1)
        return power(x, phi(m) - 1, m);
    else {
        x = (x % m + m) % m;
        return x;
    }
}

bool isPrime(long long x) {
    if (x <= 1) return false;
    for (long long i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

int cnt_dig(long long x) {
    if (!x) return 1;
    int ans = 0;
    while (x) {
        x /= 10;
        ans++;
    }
    return ans;
}

int sum_dig(long long x) {
    long long ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int cnt_bit(long long x) {
    int res = 0;
    while (x) {
        res += x & 1;
        x >>= 1;
    }
    return res;
}

long long sqr(long long x, long long m = 1000000000000000007) {
    return x * x % m;
}

long long a, b;

int main() {
    ios::sync_with_stdio(0);
    while (cin >> a >> b) {
        // Check for potential performance bottlenecks
        check_loop_iteration_threshold(b);
        check_repeated_modulo_calculations(b);
        check_arithmetic_operations(b);
        
        long long res = 0;
        long long rev = rev_el(2, 1000000007);
        for (long long g = 1; g < b; ++g) {
            res += (((g * b % 1000000007) * (a + 1) % 1000000007) * a % 1000000007) * rev % 1000000007;
            res %= 1000000007;
            res += g * a;
            res %= 1000000007;
        }
        cout << res << endl;
    }
}