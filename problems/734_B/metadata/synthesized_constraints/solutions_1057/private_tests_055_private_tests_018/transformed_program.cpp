#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_counts_invariant(long long a, long long c, long long d) {
    if (a > 1000000 && c > 1000000 && d > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - large counts for digits forming 256!" << endl;
        abort();
    }
}

void check_balanced_availability_invariant(long long a, long long c, long long d) {
    if (a > 0 && c > 0 && d > 0 && a == c && c == d) {
        cerr << "Warning: Performance bottleneck condition triggered - balanced availability for 256 digits!" << endl;
        abort();
    }
}

void check_imbalance_invariant(long long a, long long c, long long d) {
    if (a > 10 * (c + d) || c > 10 * (a + d) || d > 10 * (a + c)) {
        cerr << "Warning: Performance bottleneck condition triggered - significant imbalance in digits!" << endl;
        abort();
    }
}

int main() {
    long long int a, b, c, d, ans = 0;
    cin >> a >> b >> c >> d;

    // Apply invariant checks after reading the input
    check_large_counts_invariant(a, c, d);
    check_balanced_availability_invariant(a, c, d);
    check_imbalance_invariant(a, c, d);

    while (true) {
        if (a != 0 && c != 0 && d != 0) {
            ans += 256;
            a--;
            c--;
            d--;
        } else if (a != 0 && b != 0) {
            ans += 32;
            a--;
            b--;
        } else {
            break;
        }
    }
    cout << ans;
}