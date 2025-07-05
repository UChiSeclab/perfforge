#include <bits/stdc++.h>
using namespace std;

// Checker for large even numbers, especially powers of two
void check_large_even_number(long long int n) {
    if (n > 2 && (n & (n - 1)) == 0) {
        cerr << "Warning: Performance bottleneck condition triggered for large even number (power of two)!" << endl;
        abort();
    }
}

// Checker for highly composite numbers
void check_highly_composite_number(long long int n) {
    int divisorCount = 0;
    for (long long int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisorCount += (i * i != n) ? 2 : 1;
        }
    }
    if (divisorCount > 20) {
        cerr << "Warning: Performance bottleneck condition triggered for highly composite number!" << endl;
        abort();
    }
}

// Checker for odd divisor optimization
void check_odd_divisor_optimization(long long int n) {
    if (n > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered for odd divisor optimization!" << endl;
        abort();
    }
}

int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;

        // Inserted checker calls before heavy computation
        check_large_even_number(n);
        check_highly_composite_number(n);
        check_odd_divisor_optimization(n);

        if (n % 2 != 0 && n != 1)
            cout << "Ashishgup" << "\n";
        else if (n == 1)
            cout << "FastestFinger" << "\n";
        else if (n == 2)
            cout << "Ashishgup" << "\n";
        else {
            bool f1 = false;
            for (long long int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    if (i % 2 != 0 || (n / i) % 2 != 0) {
                        f1 = true;
                        if ((n / i) % 2 != 0 && i <= 2) {
                            f1 = false;
                            continue;
                        }
                        break;
                    }
                }
            }
            if (f1)
                cout << "Ashishgup" << "\n";
            else
                cout << "FastestFinger" << "\n";
        }
    }
    return 0;
}