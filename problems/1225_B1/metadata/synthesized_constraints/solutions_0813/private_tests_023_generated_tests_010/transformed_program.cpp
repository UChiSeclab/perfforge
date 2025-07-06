#include <bits/stdc++.h>
using namespace std;

int t;
const int N = 2e5 + 2, M = 1e6 + 5;

void check_high_d_ratio_invariant(int n, int d, int k) {
    if ((d >= n * 0.8) && (k >= d * 0.8)) {
        cerr << "Warning: Performance bottleneck condition triggered - high d to n ratio with many distinct shows!" << endl;
        abort();
    }
}

void check_frequent_set_operations_invariant(int d, int k) {
    if ((d >= 50) && (k >= d * 0.7)) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent set operations due to large d and many distinct shows!" << endl;
        abort();
    }
}

void Solve() {
    int n, k, d, res = 0;
    cin >> n >> k >> d;

    // Insert invariant checks here
    check_high_d_ratio_invariant(n, d, k);
    check_frequent_set_operations_invariant(d, k);

    set<int> st;
    int c[M], a[N];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[a[i]] = 0;
    }
    for (int i = 0; i < d; ++i) {
        st.insert(a[i]);
        c[a[i]]++;
    }
    res = st.size();
    for (int i = d; i < n; ++i) {
        st.insert(a[i]);
        c[a[i]]++;
        c[a[i - d]]--;
        if (c[a[i - d]] == 0) st.erase(a[i - d]);
        res = min(res, int(st.size()));
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}