#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // for abort()

using namespace std;

void check_large_variable_heights(int n, const vector<int>& heights) {
    int max_height = *max_element(heights.begin(), heights.end());
    if (n > 10000 && max_height > 500) { // Example threshold values
        cerr << "Warning: Performance bottleneck due to large and variable tower heights!" << endl;
        abort();
    }
}

void check_complex_boundary_adjustments(const vector<int>& heights) {
    int changes = 0;
    for (size_t i = 1; i < heights.size(); ++i) {
        if (abs(heights[i] - heights[i - 1]) > 10) { // Example threshold
            ++changes;
        }
    }
    if (changes > heights.size() / 10) { // More than 10% changes
        cerr << "Warning: Performance bottleneck due to complex boundary adjustments!" << endl;
        abort();
    }
}

void check_full_array_scans(int n) {
    if (n > 50000) { // Example threshold for large inputs
        cerr << "Warning: Performance bottleneck due to full array scans with large n!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> k(n);
    for (int i = 0; i < n; ++i) cin >> k[i];

    // Insert checks after input is read and before processing
    check_large_variable_heights(n, k);
    check_complex_boundary_adjustments(k);
    check_full_array_scans(n);

    for (int i = 0; i < n; ++i) {
        k[i] = min(k[i], i + 1);
        if (i > 0) k[i] = min(k[i], k[i - 1] + 1);
    }
    for (int i = n - 1; i >= 0; --i) {
        k[i] = min(k[i], n - i);
        if (i < n - 1) k[i] = min(k[i], k[i + 1] + 1);
    }
    int m = 0;
    for (int i = 0; i < n; ++i) m = max(m, k[i]);
    cout << m << endl;
}