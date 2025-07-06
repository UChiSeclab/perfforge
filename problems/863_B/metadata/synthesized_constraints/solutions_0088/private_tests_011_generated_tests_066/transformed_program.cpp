#include <bits/stdc++.h>
using namespace std;

// High Combination Overhead Check
void check_combination_invariant(int n) {
    if (n >= 45) { // Threshold chosen close to upper constraint to detect high overhead.
        cerr << "Warning: Performance bottleneck condition triggered due to high combination overhead!" << endl;
        abort();
    }
}

// Repeated Sorting Check
void check_sorting_invariant(int iterationCount) {
    if (iterationCount > 10000) { // Arbitrary threshold indicating repeated sorting operations.
        cerr << "Warning: Performance bottleneck condition triggered due to repeated sorting operations!" << endl;
        abort();
    }
}

// Instability Calculation Check
void check_instability_invariant(int n) {
    if ((n * (n - 1) / 2) > 1000) { // Checks potential expensive instability calculations.
        cerr << "Warning: Performance bottleneck condition triggered in instability calculations!" << endl;
        abort();
    }
}

signed main() {
    long long int n;
    cin >> n;
    n *= 2;
    
    // Check for high combination overhead early
    check_combination_invariant(n / 2);
    
    long long int arr[n];
    long long int hash[1000 + 100] = {0};
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    long long int ans = INT_MAX;
    
    // Calculate potential number of iterations for sorting invariant check
    int iterationCount = (n / 2) * (n / 2);
    check_sorting_invariant(iterationCount);
    
    for (long long int i = 0; i < n; i++) {
        for (long long int j = 0; j < n; j++) {
            vector<long long int> v;
            for (long long int k = 0; k < n; k++) {
                if (k != i && k != j) v.push_back(arr[k]);
            }
            sort(v.begin(), v.end());
            
            // Instability calculation check
            check_instability_invariant(n / 2);
            
            long long int maxx = 0;
            for (long long int k = 0; k < v.size() - 1; k += 2) {
                maxx = maxx + abs(v[k] - v[k + 1]);
            }
            ans = min(ans, maxx);
        }
    }
    cout << ans;
    return 0;
}