#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_high_divisor_checks(long long n) {
    if ((n & (n - 1)) == 0 && n > 2) {
        cerr << "Warning: Performance bottleneck condition triggered - high divisor checks for large even number!" << endl;
        abort();
    }
}

void check_repeated_set_operations(long long n, const set<int>& st) {
    if (!st.empty() && n % 2 == 0 && n > 2 && (n / 2) % 2 == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated set operations for large even base!" << endl;
        abort();
    }
}

void check_large_even_factor(long long n) {
    if ((n > 2) && (n % 2 == 0) && (n & (n - 1)) != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - large even factor causing loop overhead!" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        // Performance checker - High number of divisor checks
        check_high_divisor_checks(n);

        if (n == 1)
            cout << "FastestFinger" << endl;
        else if (n == 2)
            cout << "Ashishgup" << endl;
        else if (n % 2)
            cout << "Ashishgup" << endl;
        else {
            set<int> st;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    if (i % 2) st.insert(i);
                    if ((n / i) % 2) st.insert(n / i);
                }
            }

            // Performance checker - Repeated set operations
            check_repeated_set_operations(n, st);

            if (st.size() == 0)
                cout << "FastestFinger" << endl;
            else {
                int f = 0;
                for (auto i : st) {
                    if (i != n / 2) {
                        cout << "Ashishgup" << endl;
                        f = 1;
                        break;
                    }
                }
                if (f == 0) cout << "FastestFinger" << endl;
            }
        }

        // Performance checker - Loop overhead with large even n
        check_large_even_factor(n);
    }
    return 0;
}