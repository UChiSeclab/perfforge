#include <bits/stdc++.h>
using namespace std;

// Function to check large range between smallest and largest indices
void check_range_invariant(int p, int q, int n) {
    if ((q - p) > 1000 * n) { // A threshold considering n <= 1000
        cerr << "Warning: Performance bottleneck condition triggered - large range between smallest and largest indices!" << endl;
        abort();
    }
}

// Function to check sparse distribution of indices
void check_sparse_distribution(int p, int q, int n) {
    if ((q - p + 1) > 2 * n) { // Threshold for sparsity: more than double the remaining count
        cerr << "Warning: Performance bottleneck condition triggered - indices are sparsely distributed over a large interval!" << endl;
        abort();
    }
}

// Function to check excessive loop iterations
void check_iteration_invariant(int p, int q, int n) {
    if ((q - p + 1) > 10000) { // A conservative limit on total iterations
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations in the loop!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int p = a[1];
    int q = a[n];
    
    // Check for performance bottlenecks before entering the main loop
    check_range_invariant(p, q, n);
    check_sparse_distribution(p, q, n);
    check_iteration_invariant(p, q, n);

    int k = 1, cnt = 0;
    for (int i = p; i <= q; i++) {
        if (i == a[k]) {
            k++;
        } else {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}