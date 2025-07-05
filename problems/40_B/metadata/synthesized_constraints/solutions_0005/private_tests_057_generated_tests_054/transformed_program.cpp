#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1e5 + 5;

// Checker functions
void check_large_dimensions_invariant(int transformed_n, int transformed_m) {
    if (transformed_n > 1000 && transformed_m > 1000) { // Arbitrary threshold
        cerr << "Warning: Large dimensions invariant triggered - potential performance bottleneck due to large effective dimensions." << endl;
        abort();
    }
}

void check_input_size_invariant(int n, int m) {
    if (n > 4000 || m > 4000) { // Arbitrary threshold close to the upper constraint
        cerr << "Warning: Input size invariant triggered - inputs near upper limits may cause large computation time." << endl;
        abort();
    }
}

void check_minimal_reduction_invariant(int original_n, int original_m, int x) {
    if (original_n - 2 * x + 2 > 1000 && original_m - 2 * x + 2 > 1000) { // Arbitrary large threshold
        cerr << "Warning: Minimal reduction invariant triggered - `x` is insufficient for reducing dimensions." << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, x;
    cin >> n >> m >> x;

    // Invariant checks
    check_input_size_invariant(n, m); // Check input size close to limits before transformation

    int transformed_n = n - 2 * x + 2;
    int transformed_m = m - 2 * x + 2;

    check_large_dimensions_invariant(transformed_n, transformed_m); // Check large effective dimensions
    check_minimal_reduction_invariant(n, m, x); // Check minimal reduction by `x`

    if (transformed_n < 0 or transformed_m < 0) return cout << 0, 0;
    
    int result = 0;
    for (int i = 0; i < transformed_n; i++)
        for (int j = 0; j < transformed_m; j++)
            if (i == 0 or j == 0 or i == transformed_n - 1 or j == transformed_m - 1)
                if ((i + j) % 2 == 0) result++;
    
    cout << result << endl;
}