#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n;
long long f[100010], g[100010], s, sum, a[100010], v[100010];
long long exponentiation_calls = 0;  // Track exponentiation calls for invariant

void check_max_element_invariant(long long s) {
    if (s > 50000) {
        cerr << "Warning: max_element_invariant triggered - large maximum element value" << endl;
        abort();
    }
}

void check_frequent_exponentiation_invariant(long long calls) {
    if (calls > 10000) {
        cerr << "Warning: frequent_exponentiation_invariant triggered - too many power computations" << endl;
        abort();
    }
}

long long faspow(long long a, long long b) {
    long long tmp = 1;
    while (b) {
        if (b & 1) tmp = tmp * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    exponentiation_calls++;  // Increment calls for invariant tracking
    return tmp;
}

void check_high_frequency_invariant(long long maxFrequency) {
    if (maxFrequency > 2000) {
        cerr << "Warning: high_frequency_invariant triggered - high frequency of elements" << endl;
        abort();
    }
}

void check_large_nested_iterations_invariant(long long iterations) {
    if (iterations > 1000000) {
        cerr << "Warning: large_nested_iterations_invariant triggered - too many nested iterations" << endl;
        abort();
    }
}

long long count(long long k) {
    return faspow(2, k) - 1;
}

int main() {
    cin >> n;
    long long maxFrequency = 0;
    long long nested_iterations = 0;  // Track nested iterations for invariant
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]]++;
        s = max(s, a[i]);
        maxFrequency = max(maxFrequency, v[a[i]]);
    }
    
    check_max_element_invariant(s);  // Check for large max element
    check_high_frequency_invariant(maxFrequency);  // Check for high frequency
    
    for (int i = 2; i <= s; i++) {
        for (int j = 1; i * j <= s; j++) {
            g[i] += v[i * j];
            nested_iterations++;  // Increment iterations count
        }
    }
    
    check_large_nested_iterations_invariant(nested_iterations);  // Check for too many nested iterations
    
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
    
    check_frequent_exponentiation_invariant(exponentiation_calls);  // Check for too many power computations
    
    return 0;
}