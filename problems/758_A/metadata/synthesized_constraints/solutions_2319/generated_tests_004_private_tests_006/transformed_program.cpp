#include <bits/stdc++.h>
using namespace std;

// Check if n is large and may cause inefficient sorting
void check_large_n_invariant(int n) {
    if (n > 90) { // Threshold close to the maximum constraint
        cerr << "Warning: Performance bottleneck condition triggered - large n causing inefficient sorting!" << endl;
        abort();
    }
}

// Check if array has many identical elements
void check_almost_sorted_invariant(const vector<int>& a, int n) {
    int identicalCount = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            identicalCount++;
        }
    }
    if (identicalCount > n * 0.8) { // Threshold: 80% of elements are identical
        cerr << "Warning: Performance bottleneck condition triggered - many identical elements!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    
    // Run the invariant check for large n
    check_large_n_invariant(n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Run the invariant check for almost sorted or identical elements
    check_almost_sorted_invariant(a, n);

    // Bubble sort to ensure the array is sorted
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }

    int max = a[n - 1];
    int dem = 0;
    for (int i = 0; i < n - 1; i++) {
        dem += max - a[i];
    }
    cout << dem;
}