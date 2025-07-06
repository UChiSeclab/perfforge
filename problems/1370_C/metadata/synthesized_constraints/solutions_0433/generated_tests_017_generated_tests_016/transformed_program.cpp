#include <bits/stdc++.h>
using namespace std;

// Invariant Checkers
void check_large_power_of_two_invariant(long long n) {
    if ((n & (n - 1)) == 0 && n > 1) { // Check if n is a power of 2 and greater than 1
        cerr << "Warning: Performance bottleneck condition triggered - n is a large power of 2!" << endl;
        abort();
    }
}

void check_dense_divisor_invariant(long long n, const set<long long>& s) {
    if (n % 2 == 0 && s.size() > 10) { // Arbitrary threshold for large number of small factors
        cerr << "Warning: Performance bottleneck condition triggered - dense divisor checks!" << endl;
        abort();
    }
}

void check_high_loop_iteration_invariant(long long n, long long i) {
    if (i > sqrt(2 * n) && n > 1) { // Check if loop variable exceeds a threshold related to n
        cerr << "Warning: Performance bottleneck condition triggered - high loop iteration count!" << endl;
        abort();
    }
}

void solve() {
    long long n;
    cin >> n;

    // Check for large power of two invariant before entering heavy loop
    check_large_power_of_two_invariant(n);

    if (n == 1) {
        cout << "FastestFinger\n";
        return;
    }
    if (n == 2) {
        cout << "Ashishgup\n";
        return;
    }
    if (n % 2 == 1) {
        cout << "Ashishgup\n";
        return;
    }
    long long ok = -1;
    set<long long> s;
    for (long long i = 3; i * i <= n * 2; i += 2) {
        // Check for high loop iteration invariant
        check_high_loop_iteration_invariant(n, i);

        if (n % i == 0) {
            s.insert(i);
            ok = i;
        }
        if (n % (i - 1) == 0 && n / (i - 1) % 2 != 0) {
            s.insert(n / (i - 1));
            ok = n / (i - 1);
        }
    }

    // Check for dense divisor invariant after loop
    check_dense_divisor_invariant(n, s);

    if (s.size() == 0 || (n / ok == 2 && s.size() == 1)) {
        cout << "FastestFinger\n";
        return;
    }
    cout << "Ashishgup\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(30);
    long long t = 1;
    cin >> t;
    while (t--) solve();
}