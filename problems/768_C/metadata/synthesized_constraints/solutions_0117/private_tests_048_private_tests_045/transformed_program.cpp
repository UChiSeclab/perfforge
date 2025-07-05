#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
int cnt[N];
int a[N][2];

// Checker functions
void check_high_iteration(int k, int threshold) {
    if (k > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high iteration count!" << endl;
        abort();
    }
}

void check_nested_loop(int k, int n, int max_allowed_operations) {
    if (k * n > max_allowed_operations) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive nested loop execution!" << endl;
        abort();
    }
}

void check_bitwise_operations(int k, int threshold) {
    if (k > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high bitwise operation overhead!" << endl;
        abort();
    }
}

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);

    // Insert checks after reading input
    check_high_iteration(k, 50000); // Threshold for high iteration count
    check_nested_loop(k, n, 1e10);  // Arbitrary large number, to detect excessive operations
    check_bitwise_operations(k, 50000); // Threshold for bitwise operation overhead

    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i) {
        int foo;
        scanf("%d", &foo);
        ++cnt[foo];
    }
    while (k--) {
        for (int i = 0, j = 0; i < N; ++i) {
            a[i][j] = cnt[i] / 2;
            a[i][1 - j] = (cnt[i] + 1) / 2;
            j = (j + cnt[i]) % 2;
        }
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < N; ++i) {
            cnt[i] += a[i][0];
            cnt[i ^ x] += a[i][1];
        }
    }
    int mx = -1, mn = N;
    for (int i = 0; i < N; ++i) {
        if (cnt[i]) mx = i;
        if (cnt[N - 1 - i]) mn = N - 1 - i;
    }
    printf("%d %d", mx, mn);
}