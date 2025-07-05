#include <bits/stdc++.h>
using namespace std;

// Add checker functions for performance invariants
void check_large_k_invariant(long long n, long long k) {
    if (k > (n * (n - 1)) / 4) {
        cerr << "Warning: Performance bottleneck condition triggered - large k relative to n!" << endl;
        abort();
    }
}

void check_iteration_depth_invariant(long long n, long long k) {
    long long max_iterations = n * (n - 1) / 2;
    if (k > max_iterations / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations!" << endl;
        abort();
    }
}

void check_early_termination_invariant(long long n, long long k) {
    if (k > ((n - 2) * (n + 1)) / 4) {
        cerr << "Warning: Performance bottleneck condition triggered - early termination condition not met!" << endl;
        abort();
    }
}

long long test;
int32_t main() {
    std::cin >> test;
    while (test--) {
        long long n, k;
        std::cin >> n >> k;

        // Insert checks after reading n and k
        check_large_k_invariant(n, k);
        check_iteration_depth_invariant(n, k);
        check_early_termination_invariant(n, k);

        string str(n, 'a');
        for (long long i = n - 2; i >= 0; i--) {
            if (k <= n - i - 1) {
                str[i] = 'b';
                str[n - k] = 'b';
                break;
            } else {
                k -= (n - i - 1);
            }
        }
        std::cout << str << '\n';
    }
    return 0;
}