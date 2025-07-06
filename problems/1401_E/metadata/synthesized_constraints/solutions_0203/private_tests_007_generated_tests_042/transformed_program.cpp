#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_loop_overhead_invariant(int last_x_max, int x) {
    if (last_x_max - x > 100000) { // Arbitrary threshold; detects large ranges
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations in loop due to large x range!" << endl;
        abort();
    }
}

void check_segment_coverage_invariant(int l, int r, int max_val) {
    if ((r - l) > 0.9 * max_val) { // Set as 90% of the maximum range arbitrarily
        cerr << "Warning: Performance bottleneck condition triggered - segment spans nearly the full dimension of the square!" << endl;
        abort();
    }
}

void check_large_scale_operations_invariant(int n, int m) {
    if (n + m > 150000) { // Arbitrary threshold; close to constraint limits
        cerr << "Warning: Performance bottleneck condition triggered - excessive segments leading to high processing load!" << endl;
        abort();
    }
}

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int _n) {
        n = _n + 1;
        bit.assign(n + 1, 0);
    }
    void upd(int i, int delta) {
        i++;
        while (i < n + 1) {
            bit[i] += delta;
            i += i & -i;
        }
    }
    long long query(int i) {
        i++;
        long long sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
    long long query(int i, int j) { return query(j) - query(i - 1); }
};

vector<pair<pair<int, int>, int>> h;
vector<pair<int, pair<int, int>>> v;
Fenwick ft = Fenwick(1000005);
vector<vector<int>> active(1000005);

void solve() {
    int n, m;
    cin >> n >> m;

    // Check for large-scale operations invariant
    check_large_scale_operations_invariant(n, m);

    long long count = 1;
    for (int i = 0; i < n; ++i) {
        int y, l, r;
        cin >> y >> l >> r;

        // Check segment coverage invariant
        check_segment_coverage_invariant(l, r, 1000000);

        if (l == 0 && r == 1000000) count++;
        h.push_back({{l, r}, y});
    }

    h.push_back({{0, 1000000}, 0});
    h.push_back({{0, 1000000}, 1000000});

    for (int i = 0; i < m; ++i) {
        int x, l, r;
        cin >> x >> l >> r;
        v.push_back({x, {l, r}});
    }

    v.push_back({0, {0, 1000000}});
    sort(begin(v), end(v));
    sort(begin(h), end(h));

    int last_x = 0;
    int last_h_idx = 0;
    for (auto &vertical : v) {
        int x = vertical.first;

        // Check loop overhead invariant
        check_loop_overhead_invariant(last_x, x);

        while (last_h_idx < (int)(h).size() && h[last_h_idx].first.first <= x) {
            pair<pair<int, int>, int> horizontal = h[last_h_idx];
            active[horizontal.first.second].push_back(horizontal.second);
            ft.upd(horizontal.second, 1);
            last_h_idx++;
        }
        while (last_x < x) {
            for (auto &yy : active[last_x]) ft.upd(yy, -1);
            active[last_x].clear();
            last_x++;
        }
        if (x != 0) {
            count += ft.query(vertical.second.first, vertical.second.second) - 1;
        }
    }
    cout << count << endl;
}

int main() {
    long long t = 1;
    for (int i = 0; i < t; ++i) solve();
}