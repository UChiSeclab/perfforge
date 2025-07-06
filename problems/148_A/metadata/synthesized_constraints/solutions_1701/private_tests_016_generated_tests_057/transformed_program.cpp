#include <bits/stdc++.h>
using namespace std;

// Checker function for the first invariant
void check_divisibility_invariant(int k, int l, int m, int n, int d) {
    if ((k != 1 && l != 1 && m != 1 && n != 1) && d > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - high d with no divisor being 1" << endl;
        abort();
    }
}

// Checker function for the second invariant
void check_common_multiple_invariant(int k, int l, int m, int n, int d) {
    if ((k != 1 && l != 1 && m != 1 && n != 1) && d > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - ineffective divisor set for large d" << endl;
        abort();
    }
}

int main() {
    int k, l, m, n, d, count = 0;
    cin >> k >> l >> m >> n >> d;
    
    // Invariant checks after reading input
    check_divisibility_invariant(k, l, m, n, d);
    check_common_multiple_invariant(k, l, m, n, d);

    count = d;
    if (k == 1 || l == 1 || m == 1 || n == 1) {
        cout << d;
    } else {
        for (int i = 1; i <= d; i++) {
            if (i % k != 0 && i % l != 0 && i % m != 0 && i % n != 0) count--;
        }
        cout << count;
    }
}