#include <bits/stdc++.h>
using namespace std;

int n, t, a, b, c, ans;

// Checker function implementations
void check_large_n_with_small_pieces(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large n with small a, b, c leading to excessive loop iterations!" << endl;
        abort();
    }
}

void check_high_unsuccessful_checks(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of unsuccessful checks due to divisibility conditions!" << endl;
        abort();
    }
}

void check_relative_size_inefficiency(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient relative sizes of n vs a, b, c!" << endl;
        abort();
    }
}

void solve() {
    ans = -1;

    // Check for large n with small piece sizes
    check_large_n_with_small_pieces((n > 3000) && (a < 10 || b < 10 || c < 10));

    for (int i = 0, _b = n; i <= _b; i++) {
        for (int j = 0, _b = n; j <= _b; j++) {
            int tmp = n - i - j;
            if (tmp < 0) continue;
            
            // Check for high number of unsuccessful checks
            check_high_unsuccessful_checks((i % a != 0 || j % b != 0 || tmp % c != 0) && (i + j < 10));

            if (i % a == 0 && j % b == 0 && tmp % c == 0) {
                int tmp2 = i / a + j / b + tmp / c;
                ans = max(ans, tmp2);
            }
        }
    }

    cout << ans << endl;
}

int main() {
    scanf("%d", &n);
    scanf("%d %d %d", &a, &b, &c);
    
    // Check for inefficient relative size of n vs a, b, c
    check_relative_size_inefficiency(n > 3500 && a + b + c < 30);

    solve();
    return 0;
}