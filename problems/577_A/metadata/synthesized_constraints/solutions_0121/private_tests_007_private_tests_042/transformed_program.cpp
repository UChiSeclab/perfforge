#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_small_x_invariant(int n, int x) {
    if (n > 10000 && x == 1) {
        cerr << "Warning: Performance bottleneck condition triggered for large n and small x!" << endl;
        abort();
    }
}

void check_large_n_invariant(int n) {
    if (n > 50000) {  // A threshold such as 50000 is used for large n
        cerr << "Warning: Potential performance bottleneck due to large number of iterations!" << endl;
        abort();
    }
}

void check_division_invariant(int n, int x) {
    if (n * x > 1e9) {  // An illustrative condition to check for large computational load
        cerr << "Warning: Heavy division operations detected due to large n and x!" << endl;
        abort();
    }
}

int main() {
    int n, x, ans = 0;
    cin >> n >> x;

    // Insert checkers after input and before the loop
    check_small_x_invariant(n, x);
    check_large_n_invariant(n);
    check_division_invariant(n, x);

    for (int i = 1; i <= n; ++i) {
        double j = (double)x / i;
        if (j - round(j) == 0 && j <= n) ++ans;
    }
    cout << ans << endl;
    return 0;
}