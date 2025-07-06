#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_capacity_invariant(int m) {
    if (m > 100000000) { // Arbitrary threshold to detect large m close to its max constraint
        cerr << "Warning: Performance bottleneck condition triggered - large bus capacity!" << endl;
        abort();
    }
}

void check_wide_range_invariant(int a, int b) {
    if ((a - b) > 1000000) { // Arbitrary threshold for a wide range of possible initial passengers
        cerr << "Warning: Performance bottleneck condition triggered - wide range of possible initial passenger counts!" << endl;
        abort();
    }
}

void check_minimal_variation_invariant(vector<long long int>& v) {
    bool all_zero = all_of(v.begin(), v.end(), [](long long int x) { return x == 0; });
    if (all_zero) {
        cerr << "Warning: Performance bottleneck condition triggered - large capacity with minimal variation in a_i!" << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long int> v;
    for (int i = 0; i < n; i++) {
        long long int a;
        cin >> a;
        v.push_back(a);
    }
    
    // Apply initial checkers
    check_large_capacity_invariant(m);
    check_minimal_variation_invariant(v);

    int x = 0;
    int a = 0, b = 0;
    for (int j = 0; j < n; j++) {
        x = x + v[j];
        b = min(x, b);
        a = max(x, a);
    }
    
    // Apply range checker
    check_wide_range_invariant(a, b);

    int y = 0;
    for (int i = 0; i <= m; i++) {
        if (i + b >= 0 and i + a <= m) {
            y++;
        }
    }
    cout << y;
    return 0;
}