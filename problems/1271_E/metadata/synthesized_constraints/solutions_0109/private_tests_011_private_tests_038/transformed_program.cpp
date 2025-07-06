#include <bits/stdc++.h>
using namespace std;

// Checkers based on identified performance bottlenecks
void check_large_input_high_branching(long long n) {
    if (n > 1e17) {
        cerr << "Warning: Performance bottleneck condition triggered - n is very large!" << endl;
        abort();
    }
}

void check_frequent_calculations(long long n, long long k) {
    if (n > 10 * k) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive calculations due to n significantly larger than k!" << endl;
        abort();
    }
}

void check_high_iteration(long long N) {
    if (N > 1e17) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count expected!" << endl;
        abort();
    }
}

void check_large_multiples(long long x) {
    if (x > 1e17) {
        cerr << "Warning: Performance bottleneck condition triggered - large value handling in function calculations!" << endl;
        abort();
    }
}

const int mod = 1e9 + 7;
const int MAXN = 3e6 + 9;
long long n, k;

long long two(long long x) {
    check_large_multiples(x); // Check for large multiples
    long long base = 1, ans = 0;
    while (base * x <= n) {
        long long f = min(n, base * (x + 1) - 1);
        ans += f - base * x + 1;
        base *= 2;
    }
    return ans;
}

long long one(long long x) {
    if (x % 2 == 0) return two(x + 1) + two(x);
    return two(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--) {
        cin >> n >> k;
        
        // Insert checks after reading input
        check_large_input_high_branching(n);
        check_frequent_calculations(n, k);

        long long N = n, ans = 1;
        while (N) {
            check_high_iteration(N); // Check high iteration count
            for (long long i = 0; i <= 10; i++) {
                if (i >= N) break;
                if (one(N - i) >= k) ans = max(ans, N - i);
            }
            N /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}