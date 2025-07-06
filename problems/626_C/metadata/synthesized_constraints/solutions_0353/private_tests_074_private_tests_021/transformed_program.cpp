#include <bits/stdc++.h>
using namespace std;
const int MX = 30 * 1e6 + 10;

void check_imbalance_invariant(int n, int m) {
    if (n == 0 || m >= 10 * n) {
        cerr << "Warning: Imbalance invariant triggered - large imbalance between `n` and `m`." << endl;
        abort();
    }
}

void check_large_m_invariant(int m) {
    if (m > 500000) { // Arbitrary large threshold for demonstration
        cerr << "Warning: Large `m` invariant triggered - large number of three-block students." << endl;
        abort();
    }
}

int main() {
    int o, oo, n, m;
    cin >> o >> oo;
    
    // Check for imbalance invariant
    check_imbalance_invariant(o, oo);
    
    // Check for large `m` invariant
    check_large_m_invariant(oo);

    for (int j = 1; j <= MX; j++) {
        int two = j / 2, three = j / 3, six = j / 6;
        two -= six;
        three -= six;
        n = o, m = oo;
        n -= min(n, two);
        m -= min(m, three);
        if (six >= n + m) {
            cout << j << endl;
            return 0;
        }
    }
}