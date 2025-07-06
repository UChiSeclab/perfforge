#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3 * 1e3;

// Function to check the invariant for high k value
void check_high_k_invariant(int k) {
    if (k > 50000) {  // Arbitrary large threshold, considering constraints
        cerr << "Warning: Performance bottleneck condition triggered due to high k!" << endl;
        abort();
    }
}

// Function to check for large range processing
void check_large_range_invariant(int k, int maxN) {
    if (k * maxN > 150000000) {  // Threshold based on observed slowdown
        cerr << "Warning: Performance bottleneck condition triggered due to large range processing!" << endl;
        abort();
    }
}

// Function to check for frequent bitwise operations
void check_bitwise_operations_invariant(int k, int maxN) {
    if (k * maxN > 150000000) {  // Reuse threshold for consistency
        cerr << "Warning: Performance bottleneck condition triggered due to frequent bitwise operations on large arrays!" << endl;
        abort();
    }
}

// Function to check for alternating conditions in large loops
void check_alternating_conditions_invariant(int k, int maxN) {
    if (k * maxN > 150000000) {  // Reuse threshold for consistency
        cerr << "Warning: Performance bottleneck condition triggered due to alternating conditions in large loops!" << endl;
        abort();
    }
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;

    // Insert performance checker functions
    check_high_k_invariant(k); // Check for high k value
    check_large_range_invariant(k, MAXN); // Check for large range processing
    check_bitwise_operations_invariant(k, MAXN); // Check for frequent bitwise operations
    check_alternating_conditions_invariant(k, MAXN); // Check for alternating conditions

    vector<int> a(MAXN, 0);
    for (int i = 0; i < n; i++) {
        int z;
        cin >> z;
        a[z]++;
    }
    for (int i = 0; i < k; i++) {
        vector<int> b(MAXN, 0);
        bool fl = 0;
        for (int j = 0; j < MAXN; j++) {
            if (a[j] % 2) {
                if (fl) {
                    b[j ^ x] += a[j] / 2;
                    b[j] += a[j] / 2 + 1;
                } else {
                    b[j ^ x] += a[j] / 2 + 1;
                    b[j] += a[j] / 2;
                }
                fl ^= 1;
            } else {
                b[j ^ x] += a[j] / 2;
                b[j] += a[j] / 2;
            }
        }
        a = b;
    }
    for (int i = MAXN - 1; i >= 0; i--) {
        if (a[i]) {
            cout << i << " ";
            break;
        }
    }
    for (int i = 0; i < MAXN; i++) {
        if (a[i]) {
            cout << i << " ";
            break;
        }
    }
}