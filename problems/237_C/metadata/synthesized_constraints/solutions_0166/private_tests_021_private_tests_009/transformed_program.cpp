#include <bits/stdc++.h>
using namespace std;

// Checker function for large ranges
void check_large_range(int a, int b) {
    if (b - a + 1 > 1e6) {
        cerr << "Warning: Performance bottleneck condition triggered - large range for primality testing!" << endl;
        abort();
    }
}

// Checker function for high prime density
void check_high_prime_density(int possiblePrimes, int rangeLength) {
    if (possiblePrimes > 0.5 * rangeLength) {
        cerr << "Warning: Performance bottleneck condition triggered - high prime density in range!" << endl;
        abort();
    }
}

// Checker function for high k value
void check_high_k_value(int k, int rangeLength) {
    if (k > 0.9 * rangeLength) {
        cerr << "Warning: Performance bottleneck condition triggered - high k value relative to range length!" << endl;
        abort();
    }
}

int isPrime(int n) {
    int md = (int)(pow((float)n, 0.5)) + 1;
    int i;
    if (n < 2) return 0;
    if (n == 2) return 1;
    for (i = 2; i <= md; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int cq[1000005];

int main() {
    int i;
    int a, b, k;
    cin >> a;
    cin >> b;
    cin >> k;
    
    // Run performance checkers
    check_large_range(a, b);
    
    int l = -1;
    cq[0] = a - 1;
    int ind = 1;
    int primeCount = 0; // Track the number of primes in the range

    for (i = a; i <= b; i++) {
        if (isPrime(i) == 1) {
            primeCount++;
            cq[ind % (k + 1)] = i;
            if (ind >= k) {
                int interv = cq[ind % (k + 1)] - cq[(ind - k) % (k + 1)];
                if (l < interv) {
                    l = interv;
                }
            }
            ind++;
        }
    }

    // Run additional performance checkers
    check_high_prime_density(primeCount, b - a + 1);
    check_high_k_value(k, b - a + 1);

    if (ind >= k && b + 1 - cq[(ind - k) % (k + 1)] > l) {
        l = b + 1 - cq[(ind - k) % (k + 1)];
    }
    if (l > b - a + 1) {
        cout << "-1\n";
        return 0;
    }
    cout << l;
    return 0;
}