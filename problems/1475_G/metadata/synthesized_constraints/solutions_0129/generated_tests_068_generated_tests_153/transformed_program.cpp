#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define Max(x, y) ((x) > (y) ? x : y)
#define For(i, x, y) for (i = x; i <= (y); i++)
int a[N], f[N];

int read() {
    int A;
    bool K;
    char C;
    C = A = K = 0;
    while (C < '0' || C > '9') K |= C == '-', C = getchar();
    while (C > '/' && C < ':') A = (A << 3) + (A << 1) + (C ^ 48), C = getchar();
    return (K ? -A : A);
}

// Invariant checkers
void check_divisor_invariant(int number, int divisorCountThreshold) {
    int divisorCount = 0;
    for (int i = 1; i <= sqrt(number); i++) {
        if (number % i == 0) {
            if (i * i == number) { // Perfect square
                divisorCount++;
            } else {
                divisorCount += 2; // Pair of divisors
            }
        }
    }
    if (divisorCount > divisorCountThreshold) {
        cerr << "Warning: Performance bottleneck due to high number of divisors!" << endl;
        abort();
    }
}

void check_initialization_invariant(int n, int rangeThreshold) {
    if (n < rangeThreshold) {
        cerr << "Warning: Inefficient initialization for small n!" << endl;
        abort();
    }
}

void check_update_invariant(int updateCount, int updateThreshold) {
    if (updateCount > updateThreshold) {
        cerr << "Warning: Performance bottleneck due to frequent updates!" << endl;
        abort();
    }
}

int main() {
    int t, n, i, j;
    t = read();
    while (t--) {
        n = read();
        
        // Check initialization invariant
        check_initialization_invariant(n, 100000);

        For(i, 1, 200000) a[i] = 0;
        For(i, 1, n) a[read()]++;
        For(i, 0, 200000) f[i] = a[i];

        For(i, 1, 200000) {
            // Check each number for the divisor condition
            check_divisor_invariant(i, 32); // Arbitrary threshold for divisors

            For(j, 2, 200000 / i) {
                f[i * j] = Max(f[i * j], f[i] + a[i * j]);
                
                // Check for frequent updates
                check_update_invariant(f[i * j], 1000); // Arbitrary threshold for updates
            }
            f[0] = Max(f[0], f[i]);
        }
        cout << n - f[0] << endl;
    }
    return 0;
}