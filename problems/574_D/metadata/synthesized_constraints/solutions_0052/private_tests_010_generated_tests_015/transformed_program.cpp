#include <bits/stdc++.h>
using namespace std;

// Invariant Checkers
void check_large_input_size_invariant(int n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - large input size!" << endl;
        abort();
    }
}

void check_tower_height_variability_invariant(const vector<long long>& heights) {
    long long max_height = *max_element(heights.begin(), heights.end());
    long long min_height = *min_element(heights.begin(), heights.end());
    if (max_height - min_height > 1000) { // Arbitrary threshold for variability
        cerr << "Warning: Performance bottleneck condition triggered - significant tower height variability!" << endl;
        abort();
    }
}

void check_nested_array_operations_invariant(int n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - nested array operations!" << endl;
        abort();
    }
}

void check_maximum_height_calculation_invariant(int n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - maximum height calculation for large input!" << endl;
        abort();
    }
}

int main() {
    long long a, s, d, i, j, k;
    cin >> a;

    // Check for large input size
    check_large_input_size_invariant(a);

    vector<long long> v;
    for (i = 0; i < a; i++) {
        cin >> s;
        long long pol = min(s, i + 1);
        pol = min(pol, a - i);
        v.push_back(pol);
    }

    // Check for tower height variability
    check_tower_height_variability_invariant(v);

    vector<long long> v2;
    long long now = 1e18;
    for (i = 0; i < a; i++) {
        now = min(now + 1, v[i]);
        v[i] = now;
    }

    now = 1e18;
    for (i = a - 1; i >= 0; i--) {
        now = min(now + 1, v[i]);
        v[i] = now;
    }

    // Check for nested array operations
    check_nested_array_operations_invariant(a);

    long long ma = 0;
    for (i = 0; i < a; i++) ma = max(ma, v[i]);

    // Check for maximum height calculation
    check_maximum_height_calculation_invariant(a);

    cout << ma;
}