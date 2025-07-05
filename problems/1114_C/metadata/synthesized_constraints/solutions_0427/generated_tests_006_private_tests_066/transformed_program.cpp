#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e6 + 100;
long long n, b, mn = 1e18 + 1000;
bool mark[MX];

// Check for large number of small prime factors
void check_factorization_invariant(long long b, long long threshold) {
    long long factorCount = 0;
    long long c = b;
    for (long long i = 2; i <= sqrt(c); i++) {
        if (c % i == 0) {
            while (c % i == 0) {
                c /= i;
                factorCount++;
            }
        }
    }
    if (c > 1) factorCount++;  // account for c being a prime factor itself

    if (factorCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to many small prime factors!" << endl;
        abort();
    }
}

// Check for broad factorization range
void check_broad_factorization_range(long long b, long long rangeThreshold) {
    if (b > rangeThreshold) {
        cerr << "Warning: Performance bottleneck due to broad factorization range!" << endl;
        abort();
    }
}

// Check for excessive marking in sieve
void check_excessive_marking(long long b, long long markThreshold) {
    long long c = b;
    long long markCount = 0;
    vector<bool> mark(MX, false);
    for (long long i = 2; i <= sqrt(c); i++) {
        if (c % i == 0) {
            for (long long j = 2; j * i < MX; j++) {
                if (!mark[i * j]) {
                    mark[i * j] = true;
                    markCount++;
                }
            }
        }
    }

    if (markCount > markThreshold) {
        cerr << "Warning: Excessive marking during factorization!" << endl;
        abort();
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> b;

    // Insert the checks after reading input
    check_factorization_invariant(b, 100); // Example threshold for factor count
    check_broad_factorization_range(b, 1e6); // Example range threshold
    check_excessive_marking(b, 10000); // Example threshold for marking count

    long long c = b;
    for (long long i = 2; i <= sqrt(c); i++) {
        if (c % i != 0 || mark[i]) continue;
        for (long long j = 2; j * i < MX; j++) mark[i * j] = 1;
        long long cnt = 0;
        while (b % i == 0) cnt++, b /= i;
        long long a = n, sum = 0;
        while (a) sum += a / i, a = a / i;
        mn = min(mn, sum / cnt);
    }
    if (b > 1) {
        long long a = n, sum = 0;
        while (a) sum += a = a / b;
        mn = min(mn, sum);
    }
    cout << mn << endl;
    return 0;
}