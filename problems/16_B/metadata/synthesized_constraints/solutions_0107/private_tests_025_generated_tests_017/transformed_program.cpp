#include <bits/stdc++.h>
using namespace std;

int n, m, ans, c[10];

// Checker functions
void check_high_iteration_invariant(int n, int a[], int b[], int m) {
    int maxMatchesPerBox = 0;
    for (int i = 0; i < m; ++i) {
        if (b[i] > maxMatchesPerBox) {
            maxMatchesPerBox = b[i];
        }
    }
    if (n > 1e8 && maxMatchesPerBox >= 9) {
        cerr << "Warning: Performance bottleneck condition triggered due to high iteration count!" << endl;
        abort();
    }
}

void check_inefficient_loop_execution(int n, int a[], int m) {
    int totalMatchboxes = 0;
    for (int i = 0; i < m; ++i) {
        totalMatchboxes += a[i];
    }
    if (n > 1e8 && totalMatchboxes > 1e8) {
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient loop execution!" << endl;
        abort();
    }
}

void check_excessive_resource_consumption(int b[], int m) {
    int highMatchCount = 0;
    for (int i = 0; i < m; ++i) {
        if (b[i] > 8) {
            ++highMatchCount;
        }
    }
    if (highMatchCount == m) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive resource consumption!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int a[m], b[m];

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        if (c[b[i] - 1] == 0) {
            c[b[i] - 1] = i + 1;
        } else {
            a[c[b[i] - 1] - 1] += a[i];
        }
    }

    // Performance checkers to detect bottleneck scenarios
    check_high_iteration_invariant(n, a, b, m);
    check_inefficient_loop_execution(n, a, m);
    check_excessive_resource_consumption(b, m);

    sort(b, b + m, greater<int>());
    for (int i = 0; i < m && b[i] && n > 0; i++) {
        while (a[c[b[i] - 1] - 1]-- > 0 && n-- > 0) {
            ans += b[i];
        }
    }
    cout << ans;
}