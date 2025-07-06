#include <bits/stdc++.h>
using namespace std;

// Function to check if n is prime, which could lead to performance issues
void check_prime_invariant(unsigned long long int n) {
    bool isPrime = true;
    if (n < 2) isPrime = false;
    for (unsigned long long int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime) {
        cerr << "Warning: Performance bottleneck condition triggered - number is prime, long loop expected!" << endl;
        abort();
    }
}

// Function to check for large n that might not have small divisors
void check_large_n_invariant(unsigned long long int n) {
    bool hasSmallDivisor = false;
    for (unsigned long long int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            hasSmallDivisor = true;
            break;
        }
    }
    if (!hasSmallDivisor) {
        cerr << "Warning: Performance bottleneck condition triggered - large n with no small divisors!" << endl;
        abort();
    }
}

void solve() {
    unsigned long long int n, k;
    cin >> n >> k;

    // Check for conditions that might trigger performance bottlenecks
    check_prime_invariant(n);
    check_large_n_invariant(n); 

    unsigned long long int temp = -1;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            temp = i;
            break;
        }
    }
    if (n & 1) {
        n = n + temp;
        k--;
    }
    cout << (n + k * 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned long long int test;
    cin >> test;
    while (test--) solve();
    return 0;
}