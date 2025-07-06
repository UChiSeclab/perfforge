#include <bits/stdc++.h>
using namespace std;

void check_large_prime_invariant(int n) {
    bool isPrime = true;
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime) {
        cerr << "Warning: Performance bottleneck condition triggered - large prime number!" << endl;
        abort();
    }
}

void check_odd_high_value_invariant(int n) {
    if (n % 2 != 0 && n > 1000000 / 2) { // example threshold
        cerr << "Warning: Performance bottleneck condition triggered - large odd number with no small divisors!" << endl;
        abort();
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        
        // Insert performance checks after reading input
        check_large_prime_invariant(n);
        check_odd_high_value_invariant(n);

        if (n % 2 == 0) {
            cout << n + 2 * k << endl;
            continue;
        }
        int p = 0;
        for (int i = n; i >= 2; i--) {
            if (n % i == 0) p = i;
        }
        cout << n + p + 2 * (k - 1) << endl;
    }
    return 0;
}