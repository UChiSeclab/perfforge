#include <bits/stdc++.h>
using namespace std;

// Checkers to detect performance bottlenecks
void check_large_prime_invariant(int n) {
    if (n > 500000 && n % 2 != 0) {
        cerr << "Warning: Performance bottleneck condition triggered! n is large and odd, potentially prime." << endl;
        abort();
    }
}

void check_large_odd_n_invariant(int n) {
    if (n > 500000 && n % 2 != 0) {
        cerr << "Warning: Performance bottleneck condition triggered! n is large and odd." << endl;
        abort();
    }
}

void check_large_k_with_odd_n_invariant(int n, int k) {
    if (n % 2 != 0 && k > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered! Large k with odd n." << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // Perform invariant checks before computation
        check_large_prime_invariant(n);
        check_large_odd_n_invariant(n);
        check_large_k_with_odd_n_invariant(n, k);

        if (n % 2 == 0) {
            cout << n + 2 * k << endl;
            continue;
        }

        int p = 0;
        for (int i = n; i >= 2; i--) {
            if (n % i == 0) {
                p = i;
            }
        }
        cout << n + p + 2 * (k - 1) << endl;
    }
    return 0;
}