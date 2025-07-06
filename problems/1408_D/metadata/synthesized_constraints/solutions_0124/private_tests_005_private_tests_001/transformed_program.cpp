#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;

void check_max_coordinate_invariant(int max_coordinate) {
    if (max_coordinate > 500000) {  // Arbitrary large threshold for demonstration
        cerr << "Warning: Performance bottleneck due to large maximum coordinate!" << endl;
        abort();
    }
}

void check_large_array_invariant(int array_size) {
    if (array_size > 500000) {  // Arbitrary large threshold for demonstration
        cerr << "Warning: Performance bottleneck due to large array size!" << endl;
        abort();
    }
}

void check_loop_iteration_invariant(int loop_range) {
    if (loop_range > 500000) {  // Arbitrary large threshold for demonstration
        cerr << "Warning: Performance bottleneck due to extensive loop iterations!" << endl;
        abort();
    }
}

void foo() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n), c(m), d(m);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        mx = max(mx, max(a[i], b[i]));
    }

    for (int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
        mx = max(mx, max(c[i], d[i]));
    }

    // Check maximum coordinate invariant after input processing
    check_max_coordinate_invariant(mx);

    vector<pair<int, int>> p;
    vector<int> v(mx + 3);

    // Check large array invariant for vector "v"
    check_large_array_invariant(v.size());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = max(0, d[j] - b[i] + 1);
            int right = max(0, c[j] - a[i] + 1);
            v[up] = max(v[up], right);
        }
    }

    vector<int> suff_max(mx + 4);

    // Check large array invariant for vector "suff_max"
    check_large_array_invariant(suff_max.size());

    for (int i = mx + 2; i >= 0; i--) {
        suff_max[i] = max(suff_max[i + 1], v[i]);
    }

    int best = INF;
    for (int i = 0; i < mx + 2; i++) {
        best = min(i + suff_max[i + 1], best);
    }

    // Check loop iteration invariant for the range of loop
    check_loop_iteration_invariant(mx + 2);

    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    foo();
}