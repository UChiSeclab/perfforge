#include <bits/stdc++.h>
using namespace std;

// Function to check for unaligned starting index with large gap
void check_unaligned_start_and_large_gap(int a_min, int a_next, int n) {
    if (n > 1 && (a_next - a_min > n)) {
        cerr << "Warning: Unaligned start with a large index gap detected!" << endl;
        abort();
    }
}

// Function to check for large gaps between consecutive indices
void check_large_gaps_between_indices(const vector<int>& a, int n) {
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > n) {
            cerr << "Warning: Large gaps between consecutive indices detected!" << endl;
            abort();
        }
    }
}

// Function to check if the starting point is too far from the median
void check_start_far_from_median(int x, int median) {
    if (abs(x - median) > 100000) { // Arbitrary threshold for deviation
        cerr << "Warning: Starting point significantly different from median index!" << endl;
        abort();
    }
}

int main() {
    int n, i, x, c = 0;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    // Calculate the median of the sorted indices
    int median = a[n / 2];
    
    // Run checks
    check_unaligned_start_and_large_gap(a[0], a[1], n);
    check_large_gaps_between_indices(a, n);
    check_start_far_from_median(a[0], median);
    
    x = a[0];
    for (i = 0; i < n; i++, x++) {
        if (a[i] == x)
            continue;
        else {
            c++;
            i--;
        }
    }
    cout << c;
    return 0;
}