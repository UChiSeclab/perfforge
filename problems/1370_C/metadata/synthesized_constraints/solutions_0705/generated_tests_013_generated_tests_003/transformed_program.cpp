#include <bits/stdc++.h>
using namespace std;

long long t, n;

void check_odd_divisors_invariant(long long n, long long divisorCount) {
    if (divisorCount > 100) { // Assuming a threshold indicating excessive divisor iterations
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations due to numerous or large powers of odd divisors!" << endl;
        abort();
    }
}

void check_large_power_of_two_invariant(long long n) {
    if ((n & (n - 1)) == 0 && ((n / 2) % 2 == 1)) { // Check if n is a power of two and n/2 is odd
        cerr << "Warning: Performance bottleneck condition triggered - large power of two with odd n/2!" << endl;
        abort();
    }
}

bool solve() {
    if (n == 2) return true;
    int n1 = 0;
    long long t = n;
    long long divisorCount = 0;
    for (long long a = 2; a <= sqrt(n) && a <= t; a++) {
        while (t % a == 0) {
            t /= a;
            if (a % 2 == 1) n1++;
            divisorCount++;
        }
    }

    check_odd_divisors_invariant(n, divisorCount); // Check the first performance invariant

    if (t > 1 && t % 2 == 1) {
        n1++;
    }
    if (n % 2 == 0 && (n / 2) % 2 == 1) {
        return n1 > 1;
    }
    return n1 >= 1;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        check_large_power_of_two_invariant(n); // Check the second performance invariant
        if (solve()) {
            cout << "Ashishgup" << endl;
        } else {
            cout << "FastestFinger" << endl;
        }
    }
    return 0;
}