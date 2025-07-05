#include <bits/stdc++.h>
using namespace std;

const int LOG = 60;

int bit(long long mask, int k) { return (mask >> k) & 1; }

long long pw(int k) {
    if (k < 0) return 0;
    return 1LL << k;
}

long long get2(long long x, long long n, int k) {
    if (x > n) return 0;
    int pos = LOG;
    while (pos >= 0 && bit(n, pos) == bit(x, pos)) --pos;
    long long res;
    if (pos >= k)
        res = 1LL << k;
    else
        res = n - x + 1;
    return res;
}

long long get(long long x, long long n, int k) {
    long long res = 0;
    for (int i = 0; i <= LOG - k + 1; ++i) res += get2(x << i, n, i);
    if (x % 2 == 0) {
        x ^= 1;
        for (int i = 0; i <= LOG - k + 1; ++i) res += get2(x << i, n, i);
        x ^= 1;
    }
    return res;
}

void check_bit_manipulation_invariant(long long x, long long n, int LOG, int threshold) {
    int pos = LOG;
    while (pos >= 0 && ((n >> pos) & 1) == ((x >> pos) & 1)) --pos;
    if (pos > threshold) {
        std::cerr << "Warning: Performance bottleneck triggered due to excessive bit manipulation!" << std::endl;
        abort();
    }
}

void check_path_calculation_invariant(long long n, long long k, int threshold) {
    if (k > threshold) {
        std::cerr << "Warning: Heavy path calculation may slow down execution!" << std::endl;
        abort();
    }
}

void check_iterative_deep_search_invariant(long long n, long long k, int power_threshold) {
    if (k == n && n > power_threshold) {
        std::cerr << "Warning: Iterative deep search may cause performance issues with large n and k!" << std::endl;
        abort();
    }
}

void check_large_input_invariant(long long n, long long k, long long threshold) {
    if (n >= threshold && k >= threshold) {
        std::cerr << "Warning: Large input values may lead to performance bottlenecks!" << std::endl;
        abort();
    }
}

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    // Insert checks after reading inputs
    check_large_input_invariant(n, k, 1e9 / 10); // Arbitrarily chosen threshold
    check_path_calculation_invariant(n, k, 1e8); // Arbitrarily chosen threshold
    check_iterative_deep_search_invariant(n, k, 1e8); // Arbitrarily chosen threshold

    long long ans = 0;
    for (int i = LOG; i >= 0; --i) {
        long long cur = 1LL << i;
        if (get(cur, n, i + 1) < k) continue;
        for (int j = i - 1; j >= 0; --j) {
            cur ^= 1LL << j;
            if (get(cur, n, i + 1) < k) cur ^= 1LL << j;
        }
        printf("%lld\n", cur);
        return 0;
    }
}