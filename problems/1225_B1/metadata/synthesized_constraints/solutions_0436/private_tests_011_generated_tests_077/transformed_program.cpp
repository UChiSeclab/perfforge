#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int a[N], kol[N], del, k, d, n;

void check_initialization_invariant(int kol_size, int k) {
    if (kol_size > k + 1) {
        cerr << "Warning: Performance bottleneck condition triggered - unnecessary large initialization of kol array!" << endl;
        abort();
    }
}

void check_sliding_window_invariant(int n, int d) {
    if (d < n / 2) { // Arbitrarily considering d < n/2 as a threshold for inefficient execution
        cerr << "Warning: Performance bottleneck condition triggered - repeated recalculations due to small d!" << endl;
        abort();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int u = 0; u < t; u++) {
        cin >> n >> k >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];

        // Check for initialization overhead
        check_initialization_invariant(1000000, k);

        for (int i = 0; i <= 1000000; i++) kol[i] = 0;

        del = 0;
        int ans = n;

        // Check for sliding window execution inefficiency
        check_sliding_window_invariant(n, d);

        for (int i = 1; i <= d; i++) {
            kol[a[i]]++;
            if (kol[a[i]] == 1) del++;
        }
        ans = del;
        for (int i = d + 1; i <= n; i++) {
            kol[a[i - d]]--;
            if (kol[a[i - d]] == 0) del--;
            kol[a[i]]++;
            if (kol[a[i]] == 1) del++;
            ans = min(ans, del);
        }
        cout << ans << "\n";
    }
    return 0;
}