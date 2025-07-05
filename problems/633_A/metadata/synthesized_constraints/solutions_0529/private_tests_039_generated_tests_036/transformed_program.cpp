#include <bits/stdc++.h>
using namespace std;

// Function checking if c is a prime number
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Checker for invariant 1: Same damage per shot
void check_same_damage_invariant(int a, int b, int c) {
    if (a == b && c % a != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - same damage per shot with non-multiple target." << endl;
        abort();
    }
}

// Checker for invariant 2: Prime target larger than both damages
void check_prime_target_invariant(int a, int b, int c) {
    if (is_prime(c) && c > a && c > b) {
        cerr << "Warning: Performance bottleneck condition triggered - prime number target larger than both damage amounts." << endl;
        abort();
    }
}

int main() {
    long long int a, b, c;
    cin >> a >> b >> c;

    // Apply invariant checks after reading inputs
    check_same_damage_invariant(a, b, c);
    check_prime_target_invariant(a, b, c);

    for (int i = 0; i <= 10000; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (a * i + b * j == c) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}