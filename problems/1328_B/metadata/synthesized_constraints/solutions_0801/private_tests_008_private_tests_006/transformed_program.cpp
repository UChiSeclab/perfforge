#include <bits/stdc++.h>
using namespace std;

// Checker function for large k relative to n
void check_large_k_invariant(int n, int k) {
    int max_k = (n * (n - 1)) / 2;
    if (k > 0.9 * max_k) { // Example threshold: 90% of max_k
        cerr << "Warning: Performance bottleneck condition triggered! k is large relative to n." << endl;
        abort();
    }
}

// Checker function for iteration complexity
void check_iteration_complexity(int n, int initial_k) {
    int max_iterations = n / 2; // Arbitrarily chosen threshold
    if (initial_k > 0.75 * (n * (n - 1)) / 2) { // Example threshold: 75% of max_k
        cerr << "Warning: Performance bottleneck condition triggered! High iteration count expected." << endl;
        abort();
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    // Check for large k relative to n
    check_large_k_invariant(n, k);

    // Check for iteration complexity
    check_iteration_complexity(n, k);

    string s(n, 'a');
    for (int i = n - 2; i >= 0; i--) {
        if (k <= (n - i - 1)) {
            s[i] = 'b';
            s[n - k] = 'b';
            cout << s << endl;
            break;
        }
        k -= (n - i - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}