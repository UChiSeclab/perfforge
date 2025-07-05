#include <bits/stdc++.h>
using namespace std;

// Performance-checking functions
void check_prime_calculation_invariant(int b) {
    if (b >= 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive prime calculation due to large `b` value!" << endl;
        abort();
    }
}

void check_cumulative_sum_invariant(int a, int b) {
    if ((b - a) >= 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - expensive cumulative sum calculation due to large range `a` to `b`!" << endl;
        abort();
    }
}

void check_binary_search_invariant(int a, int b, int k, int totalPrimes) {
    if (k >= totalPrimes) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive binary search checks due to large `k` value relative to primes!" << endl;
        abort();
    }
}

long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void HoH() {
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
}
long long f_p(long long x, int y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return f_p(x * x, y / 2);
    else
        return x * f_p(x * x, y / 2);
}
long long l_p(long long n) {
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    return (n + 1) >> 1;
}
const int maxnum = 1000000, geps = 1;
bool not_prime[1000000];
int prime[1000001], pi = 0;
int sum[maxnum];
void getprime(int top) {
    not_prime[1] = true;
    for (int i = 2; i <= top; i++) {
        if (!not_prime[i]) prime[++pi] = i;
        for (int j = i * 2; j <= top; j += i) {
            not_prime[j] = true;
        }
    }
}
int a, b, k;
bool check(int l) {
    for (int i = a + l - 1; i <= b; i++)
        if (sum[i] - sum[i - l] < k) return false;
    return true;
}
int main() {
    HoH();
    cin >> a >> b >> k;
    if (b < a) swap(a, b);

    // Place the checks at appropriate locations
    check_prime_calculation_invariant(b);
    check_cumulative_sum_invariant(a, b);

    getprime(b);
    for (int i = 1; i <= b; i++) sum[i] = sum[i - 1] + (!not_prime[i]);

    int totalPrimes = sum[b];
    check_binary_search_invariant(a, b, k, totalPrimes);

    int lo = 1, hi = b - a + 1, mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    if (lo == b - a + 2)
        cout << -1;
    else
        cout << lo;
    return 0;
}