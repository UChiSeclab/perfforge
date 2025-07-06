#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_size_invariant(int n) {
    if (n > 2500) {
        cerr << "Warning: Performance bottleneck condition triggered - n is large, leading to quadratic operations." << endl;
        abort();
    }
}

void check_midpoints_invariant(int midpoint_checks, int threshold) {
    if (midpoint_checks > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many midpoint checks." << endl;
        abort();
    }
}

void check_lookup_invariant(int lookup_count, int threshold) {
    if (lookup_count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent set lookups." << endl;
        abort();
    }
}

void check_geometric_configuration_invariant(int configuration_count, int threshold) {
    if (configuration_count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - unfavorable geometric configuration." << endl;
        abort();
    }
}

int main() {
    double n, m, i, s = 0, d = 0, h, j;

    // Read the number of points
    cin >> n;
    
    // Check size invariant
    check_size_invariant(n);
    
    vector<vector<double>> b(n, vector<double>(2));
    set<pair<double, double>> a;
    for (i = 0; i < n; i++) {
        cin >> b[i][0] >> b[i][1];
        a.insert(make_pair(b[i][0], b[i][1]));
    }

    // Accumulators for checking performance characteristics
    int midpoint_checks = 0;
    int lookup_count = 0;
    int configuration_count = 0;
    const int threshold = 100000; // Example threshold for the checks

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            d = b[i][0] + b[j][0];
            d /= 2;
            h = b[i][1] + b[j][1];
            h /= 2;
            
            midpoint_checks++;
            if (a.find(make_pair(d, h)) != a.end()) {
                s++;
                lookup_count++;
            }
        }
    }

    // Check performance invariants based on accumulators
    check_midpoints_invariant(midpoint_checks, threshold);
    check_lookup_invariant(lookup_count, threshold);
    check_geometric_configuration_invariant(configuration_count, threshold);
    
    cout << s << endl;
}