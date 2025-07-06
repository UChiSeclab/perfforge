#include <bits/stdc++.h>
using namespace std;

// Add checker functions here
void check_prime_invariant(int n) {
    if (n % 2 != 0) {
        bool isPrime = true;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cerr << "Warning: Performance bottleneck condition triggered - likely prime number." << endl;
            abort();
        }
    }
}

void check_high_odd_invariant(int n) {
    if (n > 100000 && n % 2 != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - high odd number." << endl;
        abort();
    }
}

void check_loop_iteration_invariant(int n, int currentIteration) {
    if (currentIteration > n * 0.9) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations." << endl;
        abort();
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        
        // Check for high odd number before any operations
        check_high_odd_invariant(n);

        if (n % 2 == 0) {
            cout << n + 2 * k << endl;
            continue;
        }

        // Check if the number is prime, which may lead to inefficiency
        check_prime_invariant(n);

        int p = 0;
        for (int i = n; i >= 2; i--) {
            if (n % i == 0) {
                p = i;
                break; // Early break once the smallest divisor is found
            }
            // Check for excessive loop iterations
            check_loop_iteration_invariant(n, n - i + 1);
        }
        cout << n + p + 2 * (k - 1) << endl;
    }
    return 0;
}