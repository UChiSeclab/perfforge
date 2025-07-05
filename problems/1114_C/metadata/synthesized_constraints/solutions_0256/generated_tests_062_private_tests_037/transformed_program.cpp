#include <bits/stdc++.h>
using namespace std;

// Checker for many distinct prime factors
void check_prime_factorization_invariant(long long base, size_t primeFactorCount) {
    if (primeFactorCount > 100) {
        cerr << "Warning: Performance bottleneck due to many distinct prime factors in base b!" << endl;
        abort();
    }
}

// Checker for excessive repeated division operations
void check_repeated_division_invariant(long long base, long long factorCount) {
    if (factorCount > 500) {
        cerr << "Warning: Performance bottleneck due to excessive repeated division operations!" << endl;
        abort();
    }
}

// Checker for high factor frequency management overhead
void check_factor_frequency_invariant(size_t frequencySize) {
    if (frequencySize > 50) {
        cerr << "Warning: Performance bottleneck due to high factor frequency management overhead!" << endl;
        abort();
    }
}

void solve() {
    long long n, b;
    cin >> n >> b;
    long long c = 0;
    vector<long long> f;
    vector<long long> freq;
    long long B = b;
    
    if (b == 1) {
        cout << 0;
        return;
    }

    long long factorCount = 0;  // Keep track of number of divisions
    for (long long i = 2; i <= sqrt(b); i++) {
        int ff = 0;
        while (B % i == 0) {
            B = B / i;
            ff++;
            factorCount++;  // Count this division
        }
        if (ff > 0) {
            f.push_back(i);
            freq.push_back(ff);
        }
    }
    if (B > 1) {
        f.push_back(B);
        freq.push_back(1);
    }

    // Place checker after calculating prime factors
    check_prime_factorization_invariant(b, f.size());
    // Place checker for repeated division operations
    check_repeated_division_invariant(b, factorCount);
    // Place checker for factor frequency management
    check_factor_frequency_invariant(freq.size());
    
    long long ans = 1700000000000000000;
    for (int i = 0; i < f.size(); i++) {
        long long N = n;
        c = 0;
        while (N > 0) {
            N = N / f[i];
            c += N;
        }
        c = c / freq[i];
        ans = min(ans, c);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}