#include <bits/stdc++.h>
using namespace std;

int n, k, m, i;

// Checkers from Phase 3
void check_large_median_and_k(int medianValue, int k, int thresholdMedian, int thresholdK) {
    if (medianValue > thresholdMedian && k > thresholdK) {
        cerr << "Warning: Performance bottleneck - large initial median and high `k`!" << endl;
        abort();
    }
}

void check_small_gaps(int* a, int m, int n, int thresholdGap) {
    for (int i = m - n / 2; i < m + n / 2; ++i) {
        if (a[i + 1] - a[i] < thresholdGap) {
            cerr << "Warning: Performance bottleneck - small gaps between consecutive elements!" << endl;
            abort();
        }
    }
}

void check_high_concentration(int* a, int m, int n, int concentrationThreshold) {
    int count = 0;
    for (int i = m - n / 2; i < m + n / 2; ++i) {
        if (a[i] == a[m]) {
            count++;
        }
    }
    if (count > concentrationThreshold) {
        cerr << "Warning: Performance bottleneck - high concentration of elements around the median!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> k;
    int a[200004];
    m = n / 2;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    // Insert checks after sorting and before entering the main loop
    check_large_median_and_k(a[m], k, 100000000, 500000000); // Example thresholds
    check_small_gaps(a, m, n, 10); // Small gap threshold example
    check_high_concentration(a, m, n, n / 10); // Concentration threshold example

    for (i = a[m]; k > 0; i++) {
        while (i == a[m + 1]) m++;
        k = k - (m - n / 2 + 1);
    }
    if (k == 0)
        cout << i;
    else
        cout << i - 1;
}