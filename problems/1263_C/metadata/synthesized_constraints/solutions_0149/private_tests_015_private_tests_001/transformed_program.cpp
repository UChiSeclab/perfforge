#include <bits/stdc++.h>
using namespace std;

// Invariant Checker for large n
void check_large_n_invariant(long long n) {
    if (n > 1e8) { // Arbitrary threshold for large n
        cerr << "Warning: large_n_invariant triggered - n is very large" << endl;
        abort();
    }
}

// Invariant Checker for high set operation overhead
void check_high_set_overhead_invariant(const set<int>& ans) {
    if (ans.size() > 1e5) { // Arbitrary threshold for large set size
        cerr << "Warning: high_set_overhead_invariant triggered - excessive set operations" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        
        // Check for large n
        check_large_n_invariant(n); // Check if n is too large

        set<int> ans;
        ans.insert(0);
        for (long long j = 1; j * j <= n; ++j) {
            int k = n / j;
            if (n - k * j < j) {
                ans.insert(k);
            }
            k = n / (n / j);
            if (n - k * (n / j) < n / j) {
                ans.insert(k);
            }
        }
        
        // Check for high set operation overhead
        check_high_set_overhead_invariant(ans); // Check if set size is too large

        cout << ans.size() << endl;
        vector<int> res(ans.begin(), ans.end());
        for (int j = 0; j < res.size(); ++j) {
            if (j == 0)
                cout << res[j];
            else
                cout << " " << res[j];
        }
        cout << endl;
    }
    return 0;
}