#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_b_invariant(const std::set<int>& b) {
    int threshold = 500; // Arbitrary threshold for demonstration
    if (b.size() > threshold) {
        cerr << "Warning: large_b_invariant triggered - excessive operations due to large schedule range for `b`" << endl;
        abort();
    }
}

void check_large_r_l_range_invariant(int l, int r) {
    int threshold = 300; // Arbitrary threshold for demonstration
    if ((r - l) > threshold) {
        cerr << "Warning: large_r_l_range_invariant triggered - many shifts causing excessive set operations" << endl;
        abort();
    }
}

int main() {
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    set<int> a, b, tmp;
    int t1, t2;
    
    for (int i = 0; i < p; i++) {
        cin >> t1 >> t2;
        for (; t1 <= t2; t1++) a.insert(t1);
    }
    
    for (int i = 0; i < q; i++) {
        cin >> t1 >> t2;
        for (; t1 <= t2; t1++) {
            b.insert(t1);
        }
    }
    
    // Run the invariants after data setup
    check_large_b_invariant(b); // Check condition for large schedule range for `b`
    check_large_r_l_range_invariant(l, r); // Check condition for extensive time shifts
    
    int ans = 0;
    for (; l <= r; l++) {
        tmp.clear();
        for (set<int>::iterator it = b.begin(); it != b.end(); it++) {
            tmp.insert(*it + l);
        }
        vector<int> c(min(a.size(), tmp.size()));
        vector<int>::iterator it;
        it = set_intersection(a.begin(), a.end(), tmp.begin(), tmp.end(), c.begin());
        c.resize(it - c.begin());
        ans += c.size() > 0;
    }
    cout << ans << "\n";
    return 0;
}