#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_large_range_invariant(long long a, long long b) {
    if (b - a > 100000) { // Example broad threshold for a large range
        cerr << "Warning: Performance bottleneck condition triggered due to large range between a and b!" << endl;
        abort();
    }
}

void check_expensive_factorization_invariant(long long n) {
    if (n > 1e6) { // Arbitrary threshold to denote high computational cost for large numbers
        cerr << "Warning: Performance bottleneck condition triggered due to expensive factorization check!" << endl;
        abort();
    }
}

void check_prime_checking_invariant(long long n) {
    if (n > 1e6) { // Arbitrary threshold to indicate expensive prime checks
        cerr << "Warning: Performance bottleneck condition triggered due to expensive prime check!" << endl;
        abort();
    }
}

long long in() {
    long long a;
    scanf("%lld", &a);
    return a;
}

bool isprime(long long n) {
    if (n == 1) return 0;
    // Check expensive prime check here
    check_prime_checking_invariant(n);
    if (n == 2) return 1;
    if (n % 2) return 0;
    for (int i = 2; i <= sqrt(n) + 2; i++)
        if (n % i == 0) return 0;
    return 1;
}

long long dao(long long n) {
    // Check expensive factorization here
    check_expensive_factorization_invariant(n);
    for (int i = 2; i <= (sqrt(n)); i++)
        if (n % i == 0) return i;
    return n;
}

int main() {
    long long a = in(), b = in();
    // Check large range between a and b
    check_large_range_invariant(a, b);

    if (a == b) {
        cout << -1 << endl;
        exit(0);
    }
    if (a == 2) {
        if (b & 1)
            cout << b << endl;
        else
            cout << --b << endl;
        exit(0);
    }
    for (long long i = b; i >= a; i--) {
        if (dao(i) > a || isprime(i)) {
            cout << i << endl;
            exit(0);
        }
    }
    cout << -1 << endl;
}