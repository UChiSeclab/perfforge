#include <bits/stdc++.h>
using namespace std;

// Checker for large gap invariant
void check_large_gap_invariant(int x, int last, int n) {
    if ((last - x) > 10 * n) { // Condition: Large range compared to the number of keyboards
        cerr << "Warning: Performance bottleneck condition triggered due to large index range!" << endl;
        abort();
    }
}

// Checker for sparse distribution invariant
void check_sparse_distribution_invariant(int x, int last, int n) {
    if ((last - x) > 2 * n) { // Condition: Sparse distribution
        cerr << "Warning: Performance bottleneck condition triggered due to sparse distribution!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int x = arr[0];
    int last = arr[n - 1];

    // Perform checks after sorting and identifying the range
    check_large_gap_invariant(x, last, n);
    check_sparse_distribution_invariant(x, last, n);

    int stolen = 0;
    int c = 0;
    for (int i = x; i <= last; i++) {
        if (arr[c] != i)
            stolen++;
        else
            c++;
    }
    cout << stolen;
    return 0;
}