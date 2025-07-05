#include <bits/stdc++.h>
using namespace std;

// Checker to detect when `d` is close to `n`, potentially causing performance issues
void check_consecutive_days_invariant(int n, int d) {
    if (d >= n - 10) {  // Arbitrary threshold to capture cases where d is close to n
        cerr << "Warning: Performance bottleneck condition triggered - `d` is close to `n`!" << endl;
        abort();
    }
}

// Checker to detect when segment length `d` approaches `n`, leading to excessive operations
void check_segment_length_invariant(int n, int d) {
    if (d > n - 10) {  // Use a similar threshold approach as above
        cerr << "Warning: Segment length invariant triggered - high `d` value!" << endl;
        abort();
    }
}

int main() {
    int t, max = 9999999;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int r[105];
        int n, k1, d;
        cin >> n >> k1 >> d;
        
        // Apply checkers based on the performance-characterizing invariants
        check_consecutive_days_invariant(n, d);
        check_segment_length_invariant(n, d);
        
        vector<vector<int>> a;
        for (int j = 0; j < n; ++j) {
            int a1;
            cin >> a1;
            r[j] = 0;
            a.push_back({});
            if (j + 1 > d) {
                for (int k = j - d + 1; k <= j; k++) {
                    if (!binary_search(a[k].begin(), a[k].end(), a1)) {
                        r[k]++;
                        a[k].push_back(a1);
                        sort(a[k].begin(), a[k].end());
                    }
                }
            } else {
                for (int k = 0; k <= j; k++) {
                    if (!binary_search(a[k].begin(), a[k].end(), a1)) {
                        r[k]++;
                        a[k].push_back(a1);
                        sort(a[k].begin(), a[k].end());
                    }
                }
            }
        }
        sort(r, r + n - d + 1);
        cout << r[0] << endl;
    }
}