#include <bits/stdc++.h>
using namespace std;

void ok(int x) {
    cout << x << '\n';
    exit(0);
}

void check_loop_iteration_invariant(int p, long long n1, int k) {
    if (k >= 50000000 && n1 >= 0 && n1 < k && (p > 0 || p < -100)) {
        cerr << "Warning: Excessive loop iterations due to input combination!" << endl;
        abort();
    }
}

void check_arithmetic_invariant(int k, long long n1) {
    if (n1 >= 0 && n1 < k && k >= 50000000) {
        cerr << "Warning: Arithmetic condition rarely satisfied, causing slow execution!" << endl;
        abort();
    }
}

void check_condition_invariant(int k, long long n1) {
    if (k >= 50000000 && n1 >= 0 && k < __builtin_popcountll(n1)) {
        cerr << "Warning: Condition on k and popcount not satisfied within bounds!" << endl;
        abort();
    }
}

int main() {
    int n, p;
    cin >> n >> p;
    for (int k = 0; k < int(1e8); k++) {
        long long n1 = n - 1LL * p * k;
        if (n1 < 0) continue;

        // Check for performance bottlenecks
        check_loop_iteration_invariant(p, n1, k);
        check_arithmetic_invariant(k, n1);
        check_condition_invariant(k, n1);

        if (n1 >= k && k >= __builtin_popcountll(n1)) ok(k);
    }
    ok(-1);
}