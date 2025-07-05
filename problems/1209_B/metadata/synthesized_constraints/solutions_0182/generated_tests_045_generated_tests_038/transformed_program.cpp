#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 110;
int a[MAX_N], b[MAX_N];
int n;
string s;
int bit[MAX_N];

void check_frequent_toggling(int a[], int b[], int n) {
    int small_interval_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) {
            small_interval_count++;
        }
    }
    if (small_interval_count > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - Too many lights with small toggling intervals" << endl;
        abort();
    }
}

void check_high_iteration_count(int max_iteration, int n) {
    if (max_iteration > 1e5 && n == 100) {
        cerr << "Warning: Performance bottleneck condition triggered - Excessive iteration count" << endl;
        abort();
    }
}

void check_dense_overlaps(int a[], int b[], int n) {
    int overlap_count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] == a[j] && b[i] == b[j]) {
                overlap_count++;
            }
        }
    }
    if (overlap_count > n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered - Many overlapping toggling configurations" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        bit[i] = s[i - 1] - '0';
    }

    // Insert performance checks after reading input
    check_frequent_toggling(a, b, n);
    check_high_iteration_count(1e6, n); // 1e6 is the original max iteration count
    check_dense_overlaps(a, b, n);

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += bit[i];
    }
    int ans = cnt;
    for (int now = 1; now <= 1e6; ++now) {
        bool can = true;
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (now >= b[i] && (now - b[i]) % a[i] == 0) {
                bit[i] ^= 1;
            } else {
                can = false;
            }
            cnt += bit[i];
        }
        ans = max(ans, cnt);
        if (ans == n) break;
        if (can) break;
    }
    cout << ans << endl;
    return 0;
}