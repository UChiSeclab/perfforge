#include <bits/stdc++.h>
using namespace std;

// Invariant 1: Check for high loop iterations due to large discrepancies
void check_large_discrepancy_invariant(int iterations) {
    if (iterations > 100000000) { // Arbitrary threshold for excessive iterations
        cerr << "Warning: Large discrepancy causing excessive loop iterations!" << endl;
        abort();
    }
}

// Invariant 2: Check for significant difference around the median
void check_median_difference_invariant(int median, int nextElement) {
    if (nextElement - median > 1000000) { // Arbitrary threshold for significant difference
        cerr << "Warning: Significant difference around median detected!" << endl;
        abort();
    }
}

// Invariant 3: Check for inefficient use of operations
void check_operations_usage_invariant(int k, int iterations) {
    if (k < iterations / 2) { // Arbitrary threshold; too many operations for iterations
        cerr << "Warning: Inefficient use of operations - possible performance bottleneck!" << endl;
        abort();
    }
}

int bin_search(int *arr, int l, int r, int key) {
    int mid;
    int ans = l;
    while (l < r) {
        mid = ((l + r) / 2) + 1;
        if (arr[mid] == key) {
            l = mid;
            ans = l;
        } else if (arr[mid] > key) {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int el = arr[n / 2];
    int pos = 0;
    int left = n / 2;
    int size = 0;
    int maxmedian = el;
    int totalIterations = 0; // Track total iterations for check

    while (k > 0) {
        pos = bin_search(arr, left, n - 1, el);
        if (pos == n - 1) {
            break;
        }
        size += pos - left + 1;
        
        // Check for significant difference around the median
        check_median_difference_invariant(el, arr[pos + 1]);

        while (el < arr[pos + 1]) {
            k -= size;
            if (k >= 0) {
                el++;
                maxmedian++;
                totalIterations++;
            } else {
                break;
            }
        }
        left = pos + 1;
        el = arr[left];
    }

    // Check for high loop iterations after processing
    check_large_discrepancy_invariant(totalIterations);

    if (k > 0) {
        maxmedian += k / ((n + 1) / 2);
    }

    // Check for inefficient use of operations before final output
    check_operations_usage_invariant(k, totalIterations);

    cout << maxmedian;
}