#include <bits/stdc++.h>
using namespace std;

// Checker for the primality invariant
void check_primality_invariant(long long n) {
    if (n > 1e7 && n % 2 == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - checking primality for large odd number!" << endl;
        abort();
    }
}

// Checker for the even reduction invariant
void check_even_reduction_invariant(int powerOf2Factor) {
    if (powerOf2Factor > 20) {  // Threshold for detecting quick reduction
        cerr << "Warning: Quick reduction detected - large power of 2 factor!" << endl;
        abort();
    }
}

void solve() {
    long long int n;
    cin >> n;

    if (n == 1) {
        cout << "FastestFinger" << "\n";
        return;
    }
    if (n % 2) {
        cout << "Ashishgup" << "\n";
        return;
    }

    long long int c = 0;
    while (n % 2 == 0) {
        c++;
        n /= 2;
    }

    // Check for large power of 2 reduction
    check_even_reduction_invariant(c);

    if (n == 1) {
        if (c == 1) {
            cout << "Ashishgup" << "\n";
            return;
        } else {
            cout << "FastestFinger" << "\n";
            return;
        }
    } else {
        // Check for primality of large odd numbers
        check_primality_invariant(n);

        bool prime = true;
        for (long long int i = 2; i * i <= n; i++) {
            if (n % i == 0) prime = false;
        }
        if (prime) {
            if (c == 1) {
                cout << "FastestFinger" << "\n";
                return;
            } else {
                cout << "Ashishgup" << "\n";
                return;
            }
        } else {
            cout << "Ashishgup" << "\n";
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}