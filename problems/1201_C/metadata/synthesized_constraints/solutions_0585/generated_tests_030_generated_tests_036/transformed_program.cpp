#include <bits/stdc++.h>
using namespace std;

// Function to check repeated increment operations
void check_repeated_increment_operations(int k, int n, const vector<int>& g) {
    int median_index = (n - 1) / 2;
    if (k > n * (g[median_index + 1] - g[median_index])) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated increment operations!" << endl;
        abort();
    }
}

// Function to check large operational budget relative to element gaps
void check_large_operational_budget(int k, int n, const vector<int>& g) {
    int median_index = (n - 1) / 2;
    int max_gap = 0;
    for (int j = 0; j < n / 2; ++j) {
        max_gap = max(max_gap, g[median_index + j + 1] - g[median_index + j]);
    }
    if (k > n * max_gap) {
        cerr << "Warning: Performance bottleneck condition triggered - large operational budget relative to element gaps!" << endl;
        abort();
    }
}

// Function to check costly element updates in a loop
void check_costly_element_updates(int k, int n, const vector<int>& g) {
    int median_index = (n - 1) / 2;
    int nearby_updates = 0;
    for (int j = 0; j < n / 2; ++j) {
        nearby_updates += g[median_index + j + 1] - g[median_index + j] <= 1;
    }
    if (k > n && nearby_updates > n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered - costly element updates in a loop!" << endl;
        abort();
    }
}

int main() {
    int n, k, a;
    cin >> n >> k;
    vector<int> g;
    for (int i = 0; i < n; i++) {
        cin >> a;
        g.push_back(a);
    }
    sort(g.begin(), g.end());

    // Insert checks after sorting
    check_repeated_increment_operations(k, n, g);
    check_large_operational_budget(k, n, g);
    check_costly_element_updates(k, n, g);

    for (int j = 0; j < (n + 1) / 2; j++) {
        if (j == (n + 1) / 2 - 1) {
            while (k >= j + 1) {
                k -= (j + 1);
                g[((n - 1) / 2)]++;
            }
        } else {
            while (k >= (j + 1) && g[((n - 1) / 2) + j] < g[((n - 1) / 2) + j + 1]) {
                g[((n - 1) / 2)]++;
                if (j) {
                    g[((n - 1) / 2) + j]++;
                }
                k -= (j + 1);
            }
        }
    }
    cout << g[((n - 1) / 2)];
    return 0;
}