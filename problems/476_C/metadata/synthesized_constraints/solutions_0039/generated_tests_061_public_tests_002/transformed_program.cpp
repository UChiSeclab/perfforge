#include <bits/stdc++.h>
using namespace std;

// Function to check performance condition related to large 'b'
void check_large_b_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large b!" << endl;
        abort();
    }
}

long long int powmod(long long int a, int b, int n) {
    long long int rm = 1;
    while (b) {
        if (b % 2) {
            rm = (rm * a) % n;
        }
        a = (a * a) % n;
        b /= 2;
    }
    return rm;
}

int main() {
    long long int a, b, k, tsum = 0, sum2 = 0;
    cin >> a >> b;

    // Check if 'b' is large enough to cause performance issues
    check_large_b_invariant(b > 1000000); // Threshold chosen based on performance observations

    for (long long int i = 1; i < b; ++i) {
        sum2 = (a * (a + 1)) / 2;
        sum2 %= int(1e9 + 7);
        sum2 = (sum2 * i) % int(1e9 + 7);
        sum2 = (sum2 * b) % int(1e9 + 7);
        sum2 = (sum2 + (i * a) % int(1e9 + 7)) % int(1e9 + 7);
        tsum = (tsum + sum2) % int(1e9 + 7);
    }
    cout << tsum << endl;
    return 0;
}