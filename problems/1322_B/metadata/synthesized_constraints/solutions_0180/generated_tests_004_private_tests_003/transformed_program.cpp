#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_sort_and_binary_operations(int n, int bitLevel) {
    if (n > 80 && bitLevel > 20) { // Example threshold
        cerr << "Warning: Potential slowdown due to large n and high bit levels in nested loop operations!" << endl;
        abort();
    }
}

void check_range_queries(int n) {
    if (n > 80) { // Example threshold
        cerr << "Warning: Performance bottleneck - excessive range queries with large n!" << endl;
        abort();
    }
}

void check_nested_loop_complexity(int n) {
    if (n > 80) { // Example threshold for problematic nested loops
        cerr << "Warning: Performance bottleneck - nested loop complexity increases with large n!" << endl;
        abort();
    }
}

// Original main function with integrated checks
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;

    // Insert checks after reading input
    check_range_queries(n);
    check_nested_loop_complexity(n);

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    int ans = 0;
    for (int b = 0; b < 30; b++) {
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = b; j >= 0; j--) {
                num *= 2;
                if (a[i] & (1 << j)) {
                    num++;
                }
            }
            A[i] = num;
        }

        // Check for sorting and binary operation bottleneck
        check_sort_and_binary_operations(n, b);

        sort(A.begin(), A.end());
        int B = b + 1;
        int64_t cntPairs = 0;
        for (int i = 0; i < n; i++) {
            cntPairs += getInRange(A, i + 1, (1 << (B - 1)) - A[i], (1 << B) - 1 - A[i]);
            cntPairs += getInRange(A, i + 1, (1 << B) + (1 << (B - 1)) - A[i], (int)1e9);
        }
        if (cntPairs % 2 != 0) {
            ans |= (1 << b);
        }
    }
    cout << ans << "\n";
    return 0;
}