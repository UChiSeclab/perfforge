#include <bits/stdc++.h>
using namespace std;

// Checker functions based on inferred invariants
void check_large_n_invariant(int n) {
    if (n > 2500) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of points causing excessive loop iterations!" << endl;
        abort();
    }
}

void check_binary_search_invariant(int n, int searchCount) {
    if (searchCount > n * n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive binary search operations!" << endl;
        abort();
    }
}

void check_midpoint_calculation_invariant(int calcCount) {
    if (calcCount > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient midpoint calculations!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    
    // Check for invariant about large n before heavy computation
    check_large_n_invariant(n);

    pair<double, double> p[n];
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    
    int ans = 0;
    int searchCount = 0; // Track the number of binary search operations
    int calcCount = 0;   // Track the number of midpoint calculations

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            calcCount++;  // Increment for each calculation of potential midpoint
            auto midpoint = make_pair((p[i].first + p[j].first) / 2, (p[i].second + p[j].second) / 2);
            if (binary_search(p, p + n, midpoint)) {
                ans++;
                searchCount++; // Increment for each successful binary search
            }
        }
    }

    // Check for invariants related to binary search and midpoint calculation after loops
    check_binary_search_invariant(n, searchCount);
    check_midpoint_calculation_invariant(calcCount);

    cout << ans << endl;
    return 0;
}