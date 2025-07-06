#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_difference_invariant(long long k, long long n) {
    if (n > 100 * k) { // Assuming a threshold of 100 times larger
        cerr << "Warning: Performance bottleneck condition triggered due to large n compared to k!" << endl;
        abort();
    }
}

void check_small_y_invariant(long long y, long long n, long long k) {
    if (y < k && n > y) { // Small y compared to n and k
        cerr << "Warning: Performance bottleneck condition triggered due to small y!" << endl;
        abort();
    }
}

void check_k_divides_n_invariant(long long n, long long k, long long y) {
    if ((n % k == 0) && (y < n / 2)) { // Checks if k divides n and y is relatively small
        cerr << "Warning: Performance bottleneck condition triggered due to k dividing n perfectly!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long y, k, n;
    cin >> y >> k >> n;

    // Run the performance checks
    check_large_difference_invariant(k, n);
    check_small_y_invariant(y, n, k);
    check_k_divides_n_invariant(n, k, y);

    bool flag = true;
    long long i = 1;
    while (k * i <= n) {
        if (y == n)
            break;
        else if (k * i > y) {
            cout << k * i - y << " ";
            flag = false;
        }
        i++;
    }
    if (flag) cout << -1;
}