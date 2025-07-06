#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_power_of_two_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large power of two detected!" << endl;
        abort();
    }
}

void check_large_prime_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large number with few divisors!" << endl;
        abort();
    }
}

void check_divisor_density_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - dense divisor set detected near sqrt(n)!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;

        // Check if n is a large power of two
        check_power_of_two_invariant((n & (n - 1)) == 0 && n > 2);

        if (n == 1) {
            cout << "FastestFinger" << endl;
        } else if (n == 2) {
            cout << "Ashishgup" << endl;
        } else {
            if (n % 2 != 0) {
                cout << "Ashishgup" << endl;
            } else {
                int flag = 0;
                int oddDivisorCount = 0;
                for (int i = 2; i <= sqrtl(n); i++) {
                    if (n % i == 0) {
                        if (i % 2 != 0) {
                            if (n / i != 2) flag = 1;
                        } else {
                            if (i != 2 && (n / i) % 2 != 0) flag = 1;
                        }
                        if (i % 2 != 0 || (n / i) % 2 != 0)
                            oddDivisorCount++;
                    }
                }
                
                // Check if n is a large number with few divisors (prime or near-prime)
                check_large_prime_invariant(oddDivisorCount == 0 && n > 2);
                
                // Check for dense divisor set near sqrt(n)
                check_divisor_density_invariant(oddDivisorCount > sqrt(n) / 2);

                if (flag == 0)
                    cout << "FastestFinger" << endl;
                else {
                    cout << "Ashishgup" << endl;
                }
            }
        }
    }
    return 0;
}