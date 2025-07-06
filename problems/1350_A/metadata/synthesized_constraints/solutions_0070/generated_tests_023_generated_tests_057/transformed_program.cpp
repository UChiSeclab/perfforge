#include <bits/stdc++.h>
using namespace std;

// Check if the divisor search in `f(n)` becomes inefficient
void check_divisor_search_efficiency(long long n, int iterations) {
    if (iterations > 1000) { // Assuming 1000 as a threshold for excessive iterations
        cerr << "Warning: Performance bottleneck condition triggered - inefficient divisor search!" << endl;
        abort();
    }
}

// Check if `f(n)` is repeatedly called without finding a small divisor
void check_repeated_calls(long long n, long long k) {
    if (k > 100000 && n > 1000000) { // Hypothetical threshold for detecting repeated calls inefficiency
        cerr << "Warning: Performance bottleneck condition triggered - excessive repeated divisor calculations!" << endl;
        abort();
    }
}

long long f(long long n) {
    int iterations = 0;
    for (int i = 2; i <= n; i++) {
        iterations++;
        if (n % i == 0) {
            check_divisor_search_efficiency(n, iterations); // Check for inefficient search
            return i;
        }
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    long long n, k;
    while (t--) {
        cin >> n >> k;
        check_repeated_calls(n, k); // Check for repeated call inefficiency
        long long ans = n;
        while (k--) {
            long long d = f(n);
            ans += f(n);
            n = ans;
            if (d == 2) {
                ans += k * 2ll;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}