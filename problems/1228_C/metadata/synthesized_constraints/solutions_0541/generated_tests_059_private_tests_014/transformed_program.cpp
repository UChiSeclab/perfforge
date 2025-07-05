#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

// Checkers for performance bottlenecks
void check_large_prime_factors(long long iteration_count, long long threshold) {
    if (iteration_count > threshold) {
        cerr << "Warning: Performance bottleneck due to large prime factors of X!" << endl;
        abort();
    }
}

void check_power_calculation_depth(long long depth, long long threshold) {
    if (depth > threshold) {
        cerr << "Warning: Performance bottleneck due to high recursion depth in power calculation!" << endl;
        abort();
    }
}

void check_factorization_efficiency(long long factorization_tries, long long threshold) {
    if (factorization_tries > threshold) {
        cerr << "Warning: Performance bottleneck due to inefficient factorization!" << endl;
        abort();
    }
}

long long A(long long B, long long C, long long &depth) {
    depth++; // Track depth of recursion
    if (C == 0) return 1;
    if (C % 2) return (A(B, C - 1, depth) * B) % MOD;
    long long X = A(B, C / 2, depth);
    return (X * X) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long X, N;
    cin >> X >> N;

    set<long long> Y;
    long long iteration_count = 0; // Track iterations for large prime factor detection
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < (sqrt(X) + 1); j++) {
            iteration_count++;
            if (j > 1)
                if (X % j == 0) {
                    X /= j;
                    Y.insert(j);
                    break;
                }
        }

    // Check for large prime factor indicator
    check_large_prime_factors(iteration_count, 100000); // Arbitrary threshold

    Y.insert(X);
    auto itr = Y.begin();
    long long ans = 1;
    for (int i = 0; i < (Y.size()); i++) {
        long long T = (*itr);
        long long TT = T;
        long long cnt = 0;
        if (T > 1)
            while (TT <= N) {
                cnt += N / TT;
                if (N / TT >= T)
                    TT *= T;
                else
                    break;
            }
        itr++;
        
        long long depth = 0;
        ans = (ans * A(T, cnt, depth)) % MOD;

        // Check for high recursion depth
        check_power_calculation_depth(depth, 1000); // Arbitrary threshold
    }

    cout << ans << endl;
}