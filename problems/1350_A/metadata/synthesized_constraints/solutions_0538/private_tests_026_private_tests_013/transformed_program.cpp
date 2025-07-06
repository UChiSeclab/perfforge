#include <bits/stdc++.h>
using namespace std;

// Check if n is large and will lead to heavy computation in the sieve
void check_prime_complexity(long long n) {
    if (n > 900000) {
        cerr << "Warning: Performance bottleneck condition triggered! Large n may cause sieve complexity." << endl;
        abort();
    }
}

// Check if n is large and odd, leading to expensive divisor search
void check_odd_divisor_complexity(long long n) {
    if (n > 900000 && (n & 1)) {
        cerr << "Warning: Performance bottleneck condition triggered! Large odd n may cause divisor search complexity." << endl;
        abort();
    }
}

// Check if n and k combination lead to significant overhead
void check_iteration_overhead(long long n, long long k) {
    if (k > 100000000 && n > 900000) {
        cerr << "Warning: Performance bottleneck condition triggered! Large n and k lead to iterative addition complexity." << endl;
        abort();
    }
}

bool SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
    return prime[n] == true;
}

int factors(int n) {
    int result;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            result = i;
            break;
        }
    }
    return result;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Insert checkers after reading input
        check_prime_complexity(n);
        check_odd_divisor_complexity(n);
        check_iteration_overhead(n, k);

        if (SieveOfEratosthenes(n) && n != 2) {
            n += n;
            k--;
        }
        if (n & 1) {
            int result = factors(n);
            n += result;
            k--;
        }
        n = n + k * 2;
        cout << n << endl;
    }
}