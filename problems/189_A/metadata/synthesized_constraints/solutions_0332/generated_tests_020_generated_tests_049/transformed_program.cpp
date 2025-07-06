#include <bits/stdc++.h>
using namespace std;

// Helper function to calculate gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Checker for large search space combinations
void check_large_search_space(int n, int a, int b, int c) {
    if (n > 1000 && (n % gcd(gcd(a, b), c) == 0)) {
        cerr << "Warning: Performance bottleneck condition triggered due to large search space combinations!" << endl;
        abort();
    }
}

// Checker for exponential growth in iterations
void check_exponential_iterations(int n, int a, int b, int c) {
    if (n > 3500) {
        cerr << "Warning: Performance bottleneck condition triggered due to exponential growth in iterations!" << endl;
        abort();
    }
}

int main() {
    int n, a, b, c, sum = 0;
    cin >> n >> a >> b >> c;

    // Insert checks before starting the loops
    check_large_search_space(n, a, b, c);
    check_exponential_iterations(n, a, b, c);

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            int s = a * x + b * y;
            int z = abs(n - s) / c;
            if (sum < x + y + z && s + c * z == n) {
                sum = x + y + z;
            }
        }
    }

    cout << sum;
}