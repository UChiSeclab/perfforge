#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n;
long long f[100010], g[100010], s, sum, a[100010], v[100010];

// Checker for maximum element size
void check_max_element_invariant(long long max_element) {
    if (max_element > 90000) {  // Threshold chosen to be close to the upper constraint
        cerr << "Warning: Performance bottleneck condition triggered! Maximum element is too large." << endl;
        abort();
    }
}

// Checker for repeated exponentiation calls
void check_exponentiation_invariant(int exponent_count) {
    if (exponent_count > 100000) {  // Assume a significant number of calls indicate inefficiency
        cerr << "Warning: Performance bottleneck condition triggered! Excessive repeated exponentiation." << endl;
        abort();
    }
}

// Checker for excessive factor counting
void check_factor_count_invariant(int factor_count) {
    if (factor_count > 1000000) {  // Arbitrary large threshold to indicate inefficiency
        cerr << "Warning: Performance bottleneck condition triggered! Excessive factor counting operations." << endl;
        abort();
    }
}

long long faspow(long long a, long long b) {
    long long tmp = 1;
    int exponent_count = 0; // Count the number of exponentiation operations
    while (b) {
        if (b & 1) tmp = tmp * a % mod;
        b >>= 1;
        a = a * a % mod;
        ++exponent_count;
    }
    check_exponentiation_invariant(exponent_count); // Check for excessive exponentiations
    return tmp;
}

long long count(long long k) { return faspow(2, k) - 1; }

int main() {
    cin >> n;
    int factor_count = 0; // Initialize factor count
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        v[a[i]]++;
        s = max(s, a[i]);
    }
    check_max_element_invariant(s); // Check for large maximum element

    for (int i = 2; i <= s; i++) {
        for (int j = 1; i * j <= s; j++) {
            g[i] += v[i * j];
            ++factor_count; // Count factor operations
        }
    }
    check_factor_count_invariant(factor_count); // Check for excessive factor counting

    f[s] = count(g[s]);
    sum += f[s];
    for (int i = s - 1; i >= 2; i--) {
        f[i] = count(g[i]);
        for (int j = 2; i * j <= s; j++) {
            f[i] = (f[i] - f[i * j]) % mod;
        }
        sum = (sum + f[i]) % mod;
    }
    cout << ((faspow(2, n) - sum - 1) % mod + mod) % mod;
    return 0;
}