#include <bits/stdc++.h>
using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0)
            return false;
    }
    return true;
}

void check_large_odd_prime_invariant(int n) {
    if (n % 2 != 0 && isPrime(n)) {
        cerr << "Warning: Performance bottleneck condition triggered - large odd prime!" << endl;
        abort();
    }
}

void check_odd_few_divisors_invariant(int n) {
    if (n % 2 != 0) {
        int divisor_count = 0;
        for (int i = 1; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                if (i * i == n) 
                    divisor_count++;
                else
                    divisor_count += 2;
            }
        }
        if (divisor_count <= 3) {
            cerr << "Warning: Performance bottleneck condition triggered - odd number with few divisors!" << endl;
            abort();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        // Check for performance bottlenecks
        check_large_odd_prime_invariant(n);
        check_odd_few_divisors_invariant(n);

        if (n % 2 == 0) {
            cout << n + 2 * k << endl;
            continue;
        }
        int p = 0;
        for (int i = n; i >= 2; i--) {
            if (n % i == 0) {
                p = i;
            }
        }
        cout << n + p + 2 * (k - 1) << endl;
    }
    return 0;
}