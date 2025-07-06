#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_vector_size_and_window_interaction(int n, int k, int d) {
    if (d > n / 2 && k > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large d and k relative to n causing frequent updates to 'used' vector." << endl;
        abort();
    }
}

void check_sliding_window_mechanics(int n, int d) {
    if (d > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large window size d relative to n." << endl;
        abort();
    }
}

void check_sparse_show_appearance(int k, int d) {
    if (k - d < 5) { // Arbitrary threshold for sparseness
        cerr << "Warning: Performance bottleneck condition triggered - frequent reevaluation due to sparse shows." << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Insert checks based on derived invariants
        check_vector_size_and_window_interaction(n, k, d);
        check_sliding_window_mechanics(n, d);
        check_sparse_show_appearance(k, d);

        vector<int> used(2000005, 0);
        int res = k;
        int cur = 0;
        for (int i = 0; i < d; i++) {
            if (!used[a[i]]) {
                cur++;
            }
            used[a[i]]++;
        }
        res = min(cur, res);
        for (int i = d; i < n; i++) {
            if (!used[a[i]]) {
                cur++;
            }
            used[a[i]]++;
            if (used[a[i - d]] == 1) {
                cur--;
            }
            used[a[i - d]]--;
            res = min(res, cur);
        }
        cout << res << endl;
    }
}