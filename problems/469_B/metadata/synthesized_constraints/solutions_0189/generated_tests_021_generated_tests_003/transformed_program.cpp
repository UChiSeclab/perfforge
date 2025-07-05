#include <bits/stdc++.h>
using namespace std;

void check_large_time_range(int l, int r) {
    if (r - l > 500) { // Arbitrary threshold chosen based on constraints
        cerr << "Warning: Performance bottleneck condition triggered due to large time range!" << endl;
        abort();
    }
}

void check_dense_overlaps(int q, int p) {
    if (q * p > 1000) { // Arbitrary threshold considering q and p max values
        cerr << "Warning: Performance bottleneck due to dense overlaps!" << endl;
        abort();
    }
}

void check_extensive_schedule_range(int l, int r, int max_a, int max_b, int max_c, int max_d) {
    if ((r - l) * (max_b - max_a + max_d - max_c) > 100000) { // Threshold based on potential range interactions
        cerr << "Warning: Performance bottleneck due to extensive schedule range!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int p, q, l, r, a, b;
    cin >> p >> q >> l >> r;
    
    // Insert checks after reading inputs
    check_large_time_range(l, r);
    check_dense_overlaps(q, p);

    map<int, bool> m;
    int max_a = 0, max_b = 0; // Track max values for schedules
    for (int i = 0; i < p; ++i) {
        cin >> a >> b;
        max_a = max(max_a, a);
        max_b = max(max_b, b);
        for (int i = a; i <= b; ++i) m[i] = true;
    }
    
    int max_c = 0, max_d = 0; // Track max values for X's schedule
    set<int> res;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        max_c = max(max_c, a);
        max_d = max(max_d, b);
        for (int j = l; j <= r; ++j) {
            for (int k = a + j; k <= b + j; ++k) {
                if (m[k]) res.insert(j);
            }
        }
    }
    
    // Insert range-related check after processing schedules
    check_extensive_schedule_range(l, r, max_a, max_b, max_c, max_d);
    
    cout << res.size() << endl;
    return 0;
}