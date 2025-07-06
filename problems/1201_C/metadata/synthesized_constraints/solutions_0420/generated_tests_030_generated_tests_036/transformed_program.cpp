#include <bits/stdc++.h>
using namespace std;

int n, k, m, i, l;

// Check if k is significantly larger than n
void check_large_k_invariant(int n, int k) {
    if (k > n * 1000) { // Arbitrary threshold where k is much larger than n
        cerr << "Warning: Performance bottleneck condition triggered - large number of operations relative to array size." << endl;
        abort();
    }
}

// Check for many consecutive elements equal to the current median
void check_consecutive_elements_invariant(int* a, int n, int medianIndex) {
    int consecutiveCount = 0;
    for (int i = medianIndex + 1; i < n && a[i] == a[medianIndex]; ++i) {
        consecutiveCount++;
    }
    if (consecutiveCount > n / 10) { // Arbitrary threshold for consecutive elements
        cerr << "Warning: Performance bottleneck condition triggered - many consecutive elements equal to median." << endl;
        abort();
    }
}

// Check if many elements are below the current median
void check_elements_below_median_invariant(int* a, int medianValue, int n) {
    int belowMedianCount = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < medianValue) {
            belowMedianCount++;
        }
    }
    if (belowMedianCount > n / 2) { // More than half of the elements are below median
        cerr << "Warning: Performance bottleneck condition triggered - many elements below median." << endl;
        abort();
    }
}

int main() {
    cin >> n >> k;
    int a[200004];
    m = n / 2, l = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    // Insert invariant checks after sorting
    check_large_k_invariant(n, k);
    check_consecutive_elements_invariant(a, n, m);
    check_elements_below_median_invariant(a, a[m], n);

    for (i = a[m]; k > 0; i++) {
        while (i == a[m + 1]) m++;
        k -= m - n / 2 + 1;
    }
    if (k == 0)
        cout << i << endl;
    else
        cout << i - 1 << endl;
    return 0;
}