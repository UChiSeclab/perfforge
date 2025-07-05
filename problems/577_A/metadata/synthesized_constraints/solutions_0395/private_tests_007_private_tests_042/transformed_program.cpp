#include <bits/stdc++.h>
using namespace std;
int n, x, b[100005], l, r;
long long ans;

void check_sieve_inefficient_usage(bool condition) {
    if (condition) {
        cerr << "Warning: Inefficient sieve usage for large n" << endl;
        abort();
    }
}

void check_divisibility_invariant(int divisorCount, int n) {
    if (divisorCount > n / 2) { // Arbitrary threshold, could be adjusted
        cerr << "Warning: Complex divisibility checks - high number of divisors" << endl;
        abort();
    }
}

void check_iteration_efficiency(bool condition) {
    if (condition) {
        cerr << "Warning: Inefficient iteration over large range" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;

    // Check inefficient sieve usage
    check_sieve_inefficient_usage(n > 1000); // Assuming sieve unnecessary for large n

    // Prime sieve (might be unnecessary for the problem)
    for (int i = 2; i * i <= n; i++) {
        if (b[i] == 0) {
            for (int j = i + i; j <= n; j += i) b[j] = 1;
        }
    }

    int divisorCount = 0; // Count of divisors
    for (int i = 1; i <= n; i++) {
        if ((x % i == 0 && i <= x && x / i <= n) && (i != 1 || n >= x)) {
            ans++;
            divisorCount++;
        }
    }

    // Check complex divisibility
    check_divisibility_invariant(divisorCount, n);

    for (int i = 1; i <= n; i++) {
        if (b[i] == 0 && i == x) {
            if (n >= x)
                l = 1;
            else
                r = 1;
        }
    }

    // Check inefficient iteration (simple example)
    check_iteration_efficiency(n > 50000); // High n value indicates inefficiency

    if (x == 1)
        cout << 1;
    else if (l == 1)
        cout << 2;
    else if (r == 1)
        cout << 0;
    else
        cout << ans;
}