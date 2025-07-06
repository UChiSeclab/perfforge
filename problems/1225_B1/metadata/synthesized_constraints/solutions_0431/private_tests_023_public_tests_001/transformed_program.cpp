#include <bits/stdc++.h>
using namespace std;

// Function to check if d is large relative to n
void check_large_d_relative_to_n(int n, int d) {
    if (d > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large d relative to n!" << endl;
        abort();
    }
}

// Function to check for frequent resets of auxiliary structures
void check_frequent_resets(int d, int numResets) {
    if (numResets > d * 2) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent resets of auxiliary structures!" << endl;
        abort();
    }
}

// Function to check for high overlap in segments
void check_high_overlap(int n, int d) {
    if (d > n / 3) {
        cerr << "Warning: Performance bottleneck condition triggered - high overlap in segments!" << endl;
        abort();
    }
}

int main() {
    int t, n, k, d, ans, count;
    cin >> t;
    vector<int> v(101);
    vector<bool> taken(101, false);

    while (t--) {
        cin >> n >> k >> d;
        // Insert checkers here to detect potential bottlenecks
        check_large_d_relative_to_n(n, d);
        check_high_overlap(n, d);

        ans = INT_MAX;
        for (int i = 0; i < n; i++) cin >> v[i];
        int numResets = 0; // Track number of resets

        for (int i = 0; i + d <= n; i++) {
            count = 0;
            fill(taken.begin(), taken.end(), 0);
            numResets++; // Increment resets count
            check_frequent_resets(d, numResets); // Check for frequent resets

            for (int j = i; j < i + d; j++) {
                if (taken[v[j]] == false) count++;
                taken[v[j]] = true;
            }
            ans = min(ans, count);
        }
        cout << ans << "\n";
    }
}