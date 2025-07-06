#include <bits/stdc++.h>
using namespace std;

// Inserted checker functions for performance invariants
void check_large_k_invariant(int n, int k) {
    int max_k = (n * (n - 1)) / 2;
    if (k > max_k * 0.9) { // Arbitrary threshold, e.g., within 10% of maximum
        cerr << "Warning: Performance bottleneck condition triggered due to large k!" << endl;
        abort();
    }
}

void check_inefficient_decrement_invariant(int n, int k) {
    if (k > (n * (n - 1)) / 4) { // Arbitrary threshold check
        cerr << "Warning: Performance bottleneck due to inefficient decrement pattern!" << endl;
        abort();
    }
}

void check_proximity_to_boundary_invariant(int n, int k) {
    int max_k = (n * (n - 1)) / 2;
    if (k > max_k - n) { // Close to maximum `k` for large `n`
        cerr << "Warning: Performance bottleneck due to proximity to loop boundary!" << endl;
        abort();
    }
}

int main() {
    int tc, n, k;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;

        // Check for performance bottleneck conditions
        check_large_k_invariant(n, k);
        check_inefficient_decrement_invariant(n, k);
        check_proximity_to_boundary_invariant(n, k);

        string str(n, 'a');
        for (int i = n - 2; i >= 0; i--) {
            if (k <= n - i - 1) {
                str[i] = 'b';
                str[n - k] = 'b';
                cout << str << endl;
                break;
            }
            k -= (n - i - 1);
        }
    }
}