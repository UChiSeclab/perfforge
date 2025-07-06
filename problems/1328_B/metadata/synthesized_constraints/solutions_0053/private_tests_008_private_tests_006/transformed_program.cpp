#include <bits/stdc++.h>
using namespace std;

// Checker for large k relative to n
void check_large_k_invariant(int n, int k) {
    int max_k = (n * (n - 1)) / 2;
    if (k > max_k / 2) {  // Check if k is significantly large relative to n
        cerr << "Warning: Performance bottleneck condition triggered - large k relative to n!" << endl;
        abort();
    }
}

// Checker for iteration overhead
void check_iteration_overhead_invariant(int n, int k) {
    int max_possible_iterations = n - 2;
    if (k > max_possible_iterations) {  // k requiring an extensive number of iterations
        cerr << "Warning: Performance bottleneck condition triggered - extensive loop iterations needed!" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // Performance invariants checks
        check_large_k_invariant(n, k);
        check_iteration_overhead_invariant(n, k);

        string str(n, 'a');
        for (int i = n - 2; i >= 0; --i) {
            if (k <= n - i - 1) {
                str[i] = 'b';
                str[n - k] = 'b';
                cout << str << endl;
                break;
            } else {
                k -= n - i - 1;
            }
        }
    }
    return 0;
}