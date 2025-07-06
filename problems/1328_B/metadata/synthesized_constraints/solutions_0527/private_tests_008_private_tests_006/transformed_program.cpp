#include <bits/stdc++.h>
using namespace std;

// Function to check if k is large relative to its max possible value
void check_large_k_invariant(int n, int k) {
    if (k > 0.9 * (n * (n - 1) / 2)) { // Arbitrary threshold for large k
        cerr << "Warning: Performance bottleneck condition triggered - large k value causing high iteration count!" << endl;
        abort();
    }
}

// Function to check if n is too large
void check_large_n_invariant(int n) {
    if (n > 10000) { // Arbitrary large threshold for n
        cerr << "Warning: Performance bottleneck condition triggered - large n value causing slow k adjustment!" << endl;
        abort();
    }
}

// Function to check if the loop isn't breaking early
void check_early_break_invariant(int initial_k, int current_k) {
    if (current_k - initial_k > 0.8 * initial_k) { // Arbitrary threshold for lack of early break
        cerr << "Warning: Performance bottleneck condition triggered - inefficient loop break!" << endl;
        abort();
    }
}

int main() {
    int t, i;
    cin >> t;
    for (i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        // Insert checks for performance bottlenecks
        check_large_n_invariant(n);
        check_large_k_invariant(n, k);

        string s(n, 'a');
        int initial_k = k;
        for (int i = n - 2; i >= 0; i--) {
            if (k <= (n - i - 1)) {
                s[i] = 'b';
                s[n - k] = 'b';
                cout << s << endl;

                // Check if we met an inefficient early loop break condition
                check_early_break_invariant(initial_k, k);

                break;
            }
            k -= n - i - 1;
        }
    }
}