#include <bits/stdc++.h>
using namespace std;

// Invariant checkers
void check_large_b_invariant(int b) {
    if (b > 5000) { // Choosing a threshold for large b
        cerr << "Warning: Performance bottleneck condition triggered due to large b!" << endl;
        abort();
    }
}

void check_large_tmp1_invariant(unsigned long long tmp1) {
    if (tmp1 > 5000) { // Choosing a threshold for large tmp1
        cerr << "Warning: Performance bottleneck condition triggered due to large tmp1!" << endl;
        abort();
    }
}

void check_combined_invariant(int m, int b) {
    if (m * b > 500000) { // Arbitrary threshold for large configuration space
        cerr << "Warning: Performance bottleneck due to large m * b configuration!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    unsigned long long b, m, ans, x, tmp, tmp1, kq;
    cin >> m >> b;

    // Check invariants based on input
    check_large_b_invariant(b);
    check_combined_invariant(m, b);

    if (b == 1) {
        cout << (m * (m + 1)) / 2;
    } else {
        x = m;
        ans = 0;
        while (true) {
            if (x / m == b) {
                unsigned long long a = ((x * (x + 1)) / 2) % 1000000000000000000;
                ans = max(ans, a);
                ans %= 1000000000000000000;
                break;
            }
            tmp = x;
            tmp1 = b - (tmp / m);

            // Check invariant inside loop
            check_large_tmp1_invariant(tmp1);

            kq = 0;
            for (int i = tmp1; i >= 0; i--) {
                kq = (kq + (tmp * (tmp + 1)) / 2 + (tmp * i)) % 1000000000000000000;
            }
            kq = (kq + (tmp1 * (tmp1 + 1)) / 2) % 1000000000000000000;
            ans = max(ans, kq);
            ans %= 1000000000000000000;
            x += m;
        }
        cout << (ans + 1000000000000000000) % 1000000000000000000;
    }
}