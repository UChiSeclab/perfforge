#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_sliding_window_invariant(int n, int d, int unique_shows_in_window, int k) {
    if ((d < n / 2) && (unique_shows_in_window >= k)) {
        cerr << "Warning: Performance bottleneck due to small d relative to n and high diversity in window!" << endl;
        abort();
    }
}

void check_show_frequency_invariant(int unique_shows_in_window, int d) {
    if (unique_shows_in_window >= d) {
        cerr << "Warning: Performance bottleneck due to high overlap of unique shows in window!" << endl;
        abort();
    }
}

void check_large_n_small_d_invariant(int n, int d, int k) {
    if ((n > 50) && (d < n / 2) && (k >= d / 2)) {
        cerr << "Warning: Performance bottleneck due to large n and small d!" << endl;
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
        vector<int> used(2000005, 0);
        int res = 0;
        for (int i = 0; i < d; i++) {
            if (!used[a[i]]) {
                res++;
            }
            used[a[i]]++;
        }
        int cur = res;

        check_large_n_small_d_invariant(n, d, k); // Check invariant before the sliding window loop
        
        for (int i = d; i < n; i++) {
            if (!used[a[i]]) {
                cur++;
            }
            used[a[i]]++;
            if (used[a[i - d]] == 1) {
                cur--;
            }
            used[a[i - d]]--;
            if (cur < res) {
                res = cur;
            }
            // Check invariants inside loop to capture the dynamic nature of the sliding window
            int unique_shows_in_window = cur; // Approximation for unique shows in the current window
            check_sliding_window_invariant(n, d, unique_shows_in_window, k);
            check_show_frequency_invariant(unique_shows_in_window, d);
        }
        cout << res << endl;
    }
}