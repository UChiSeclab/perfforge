#include <bits/stdc++.h>
using namespace std;

void check_large_n_invariant(long long n) {
    if (n > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - large effective value of n." << endl;
        abort();
    }
}

void check_frequent_large_condition(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent large condition execution in loop." << endl;
        abort();
    }
}

int main() {
    long long n, m, k, ans = 1;
    cin >> n >> m >> k;
    if (k == -1) {
        if ((n + m) % 2 == 1) {
            cout << 0;
            return 0;
        }
    }
    n--;
    m--;
    n = n % (1000000007 - 1);
    m = m % (1000000007 - 1);
    n = (n * m) % (1000000007 - 1);

    // Check for large effective value of n
    check_large_n_invariant(n);

    long long i2_in_10_6 = 1;
    for (int i = 0; i < 1000000; i++) {
        i2_in_10_6 = (i2_in_10_6 * 2) % 1000000007;
    }
    
    while (n > 0) {
        // Check for frequent large condition execution
        check_frequent_large_condition(n > 1000000);

        if (n > 1000000) {
            ans = (ans * i2_in_10_6) % 1000000007;
            n -= 1000000;
        } else {
            ans = (ans * 2) % 1000000007;
            n--;
        }
    }
    cout << ans;
}