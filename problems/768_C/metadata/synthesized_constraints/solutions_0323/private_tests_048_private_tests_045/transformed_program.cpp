#include <bits/stdc++.h>
using namespace std;

int n, k, x, t = 0, s = 1;
const int maxn = 2e3 + 5;
int f[2][maxn];

void check_k_invariant(int k, int threshold) {
    if (k > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of operations (k)!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int k, int maxn, int threshold) {
    if (k * maxn > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive nested loop executions!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> k >> x;

    // Check for performance bottleneck based on the number of operations k
    check_k_invariant(k, 50000); // Assuming 50,000 as a threshold for demonstration

    // Iterate through ranger strengths and populate frequency array
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        f[t][x]++;
    }

    // Check for nested loops involving large operations
    check_nested_loop_invariant(k, maxn, 1e8); // Threshold based on product of k and maxn

    // Perform operations k times
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < maxn; ++j) f[s][j] = 0;
        int num = 0;
        for (int j = 0; j < maxn; ++j) {
            f[s][j] += (f[t][j] + num) / 2;
            f[s][j ^ x] += (f[t][j] + 1 - num) / 2;
            num = (num + f[t][j]) % 2;
        }
        swap(t, s);
    }

    int mn = maxn, mx = 0;
    for (int i = 0; i < maxn; ++i) {
        if (f[t][i]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    cout << mx << ' ' << mn << endl;
    return 0;
}