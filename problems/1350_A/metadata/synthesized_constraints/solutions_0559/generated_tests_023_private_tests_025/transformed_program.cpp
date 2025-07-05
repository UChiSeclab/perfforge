#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_odd_invariant(long long n) {
    if (n % 2 != 0 && n > 100000) { // Large arbitrary threshold for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - large odd number" << endl;
        abort();
    }
}

void check_repeated_loop_invariant(long long n, long long k) {
    if (n % 2 != 0 && k > 1000) { // Arbitrary threshold for k indicating many iterations
        cerr << "Warning: Performance bottleneck condition triggered - repeated loop execution" << endl;
        abort();
    }
}

void check_large_factor_invariant(long long n) {
    if (n % 2 != 0 && n > 50000) { // Assume that large factors will be problematic
        cerr << "Warning: Performance bottleneck condition triggered - large factor range" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long int n, k;
        cin >> n >> k;

        // Insert checks after reading inputs
        check_large_odd_invariant(n);
        check_repeated_loop_invariant(n, k);
        check_large_factor_invariant(n);

        if (n % 2 == 0) {
            cout << n + k * 2 << "\n";
        } else {
            long long int x = n;
            while (x % 2 != 0 && k > 0) {
                long long int a = 0;
                for (int i = 2; i <= x; i++) {
                    if (x % i == 0) {
                        a = i;
                        break;
                    }
                }
                x += a;
                k--;
            }
            cout << x + k * 2 << "\n";
        }
    }
    return 0;
}