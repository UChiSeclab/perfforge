#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 7, NS = 2e3 + 7, inf = 2e9 + 7;
int cnt[2000], nw[2000];

// Checker for Invariant 1: Large number of operations
void check_large_k_invariant(int k) {
    if (k > 10000) {
        cerr << "Warning: large_k_invariant triggered - k is very large, causing potential performance degradation!" << endl;
        abort();
    }
}

// Checker for Invariant 2: Repeated operations on similar strength values
void check_repeated_operations_invariant(int k, int n) {
    if (k > n * 10) {
        cerr << "Warning: repeated_operations_invariant triggered - high k relative to n may cause performance issues." << endl;
        abort();
    }
}

void solve() {
    int n, k, first;
    cin >> n >> k >> first;

    check_large_k_invariant(k); // Check for large k
    check_repeated_operations_invariant(k, n); // Check for high k relative to n

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int it = 0; it < k; it++) {
        int cur = 0;
        fill(nw, nw + 2000, 0);
        for (int i = 0; i < 2000; i++) {
            int t;
            if (cur % 2 == 0) {
                t = (cnt[i] + 1) / 2;
            } else {
                t = cnt[i] / 2;
            }
            nw[i ^ first] += t;
            nw[i] += cnt[i] - t;
            cur += cnt[i];
        }
        for (int i = 0; i < 2000; i++) cnt[i] = nw[i];
    }
    int mx, mn;
    for (int i = 0; i < 2000; i++) {
        if (cnt[i]) {
            mn = i;
            break;
        }
    }
    for (int i = 1999; i >= 0; i--) {
        if (cnt[i]) {
            mx = i;
            break;
        }
    }
    cout << mx << ' ' << mn;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}