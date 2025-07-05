#include <bits/stdc++.h>
using namespace std;

// Function to check for large number with many divisors
void check_large_divisor_count(long long n, const set<int>& s) {
    if (n > 1e9 / 2 && s.size() > 1000) { // Arbitrary threshold for large numbers and divisor count
        cerr << "Warning: Performance bottleneck condition triggered - large number with many divisors!" << endl;
        abort();
    }
}

// Function to check if n is a power of two
void check_power_of_two(long long n) {
    if (n > 1 && (n & (n - 1)) == 0) { // Power of two check
        cerr << "Warning: Performance bottleneck condition triggered - power of two!" << endl;
        abort();
    }
}

// Function to check for large even numbers
void check_large_even_number(long long n) {
    if (n > 1e8 && n % 2 == 0) { // Arbitrary threshold for large even numbers
        cerr << "Warning: Performance bottleneck condition triggered - large even number!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        // Check for power of two input
        check_power_of_two(n);

        if (n == 1) {
            cout << "FastestFinger" << endl;
        } else if (n == 2) {
            cout << "Ashishgup" << endl;
        } else if (n % 2 != 0) {
            cout << "Ashishgup" << endl;
        } else {
            set<int> s;
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    if (i % 2 != 0) s.insert(i);
                    if ((n / i) % 2 != 0) s.insert(n / i);
                }
            }

            // Check for large number with many divisors
            check_large_divisor_count(n, s);

            // Check for large even numbers
            check_large_even_number(n);

            if (s.size() == 0) {
                cout << "FastestFinger" << endl;
            } else {
                auto it = s.end();
                it--;
                long long k = n / (*it);
                if (k == 2 && isPrime(*it) == true)
                    cout << "FastestFinger" << endl;
                else
                    cout << "Ashishgup" << endl;
            }
        }
    }
}