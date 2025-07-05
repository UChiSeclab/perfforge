#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
bool mark[maxn];
int p, q, l, r;
int d[maxn], c[maxn];
int ans;

// Function to check for large overlap invariant
void check_large_overlap_invariant(int le, int ri) {
    if (ri - le > 1000) { // Example threshold, considering problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - large overlap checks due to wide ranges!" << endl;
        abort();
    }
}

// Function to check for high interval checks invariant
void check_high_interval_checks_invariant(int q, int l, int r) {
    if (q * (r - l + 1) > 5000) { // Example threshold based on q and range size
        cerr << "Warning: Performance bottleneck condition triggered - high number of interval checks!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> q >> l >> r;
    for (int i = 1; i <= p; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++) mark[j] = true;
    }
    for (int i = 1; i <= q; i++) cin >> c[i] >> d[i];

    // Check invariant for high number of interval checks
    check_high_interval_checks_invariant(q, l, r);

    for (int i = l; i <= r; i++) {
        bool f = 0;
        for (int j = 1; j <= q; j++) {
            int le = c[j] + i;
            int ri = d[j] + i;

            // Check invariant for large overlap checks
            check_large_overlap_invariant(le, ri);

            for (int k = le; k <= ri; k++) {
                if (mark[k]) f = true;
            }
        }
        if (f) ans++;
    }
    cout << ans << endl;
    return 0;
}