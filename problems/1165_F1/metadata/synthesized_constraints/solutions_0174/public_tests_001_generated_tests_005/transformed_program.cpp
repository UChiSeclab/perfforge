#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template <class T = int>
using V = vector<T>;
template <class T = int>
using VV = V<V<T>>;

// Check for performance bottleneck due to high number of microtransaction types with high required quantities
void check_microtransaction_structure(int n, const vector<int>& k) {
    int total_microtransactions = accumulate(k.begin(), k.end(), 0);
    if (n > 900 && total_microtransactions > 900) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of microtransaction types with high required quantities!" << endl;
        abort();
    }
}

// Check for performance bottleneck due to sparse special offers
void check_special_offers_ratio(int n, int m) {
    if (m < n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to sparse special offers!" << endl;
        abort();
    }
}

// Check for performance bottleneck due to high concentration of required microtransactions on a few types
void check_concentration_of_microtransactions(const vector<int>& k) {
    int max_k = *max_element(k.begin(), k.end());
    if (max_k > 500) {
        cerr << "Warning: Performance bottleneck condition triggered due to high concentration of required microtransactions on a few types!" << endl;
        abort();
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    
    V<> k(n);
    for (auto&& e : k) cin >> e;
    
    // Insert performance checkers
    check_microtransaction_structure(n, k);
    check_special_offers_ratio(n, m);
    check_concentration_of_microtransactions(k);
    
    VV<> a(n);
    while (m--) {
        int d, t;
        cin >> d >> t, --d, --t;
        a[t].push_back(d);
    }
    
    for (auto&& v : a) sort(begin(v), end(v));
    
    auto chk = [&](int x) -> bool {
        VV<> v(4e5);
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(begin(a[i]), end(a[i]), x) - begin(a[i]) - 1;
            if (j < 0) continue;
            v[a[i][j]].push_back(i);
        }
        int c = 0;
        auto r = k;
        int y = 0;
        for (int j = 0; j < x; ++j) {
            ++c;
            for (int i : v[j]) {
                int t = min(c, r[i]);
                r[i] -= t;
                c -= t;
                y += t;
            }
        }
        return x + y >= 2 * accumulate(begin(k), end(k), 0);
    };
    
    int ng = 0, ok = 2 * accumulate(begin(k), end(k), 0);
    while (ok - ng > 1) {
        int mid = ng + ok >> 1;
        (chk(mid) ? ok : ng) = mid;
    }
    
    cout << ok << '\n';
}