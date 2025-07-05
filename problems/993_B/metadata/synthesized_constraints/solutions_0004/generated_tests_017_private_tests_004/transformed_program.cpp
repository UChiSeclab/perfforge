#include <bits/stdc++.h>
using namespace std;

int ok(pair<int, int> x, pair<int, int> y) {
    map<int, int> S;
    ++S[x.first];
    ++S[x.second];
    ++S[y.first];
    ++S[y.second];
    if (S.size() != 3) return 0;
    for (auto x : S)
        if (x.second == 2) return x.first;
    assert(false);
    return -1;
}

// Checker functions for performance invariants
void check_nested_loop_invariant(int n, int m) {
    if (n * m > 100) {  // Threshold chosen based on potential performance concerns
        cerr << "Warning: nested_loop_invariant triggered - n * m is large, leading to many operations." << endl;
        abort();
    }
}

void check_pair_combination_invariant(int n, int m) {
    if (n * m > 100) {  // May overlap with nested loop invariant
        cerr << "Warning: pair_combination_invariant triggered - excessive pair comparisons." << endl;
        abort();
    }
}

void check_set_invariant(const set<int>& possible) {
    if (possible.size() > 5) {  // Threshold for possible set size
        cerr << "Warning: set_invariant triggered - possible set size is large." << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    
    // Invoking checks after input reading
    check_nested_loop_invariant(n, m);
    check_pair_combination_invariant(n, m);
    
    vector<pair<int, int> > a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
    }
    
    set<int> possible;
    for (auto x : a) {
        for (auto y : b) {
            int d = ok(x, y);
            if (d) {
                possible.insert(d);
                // Check possible set size in the innermost loop
                check_set_invariant(possible);
            }
        }
    }
    if (possible.size() == 1) {
        cout << *possible.begin() << "\n";
        return 0;
    }
    bool yes = true;
    for (auto x : a) {
        for (auto y : b) {
            int d = ok(x, y);
            if (d) {
                set<int> pa, pb;
                for (auto x2 : a) {
                    int t = ok(y, x2);
                    if (t) pa.insert(t);
                }
                for (auto y2 : b) {
                    int t = ok(x, y2);
                    if (t) pb.insert(t);
                }
                bool b = pa.size() == 1 && pb.size() == 1;
                yes &= b;
            }
        }
    }
    if (yes)
        cout << "0\n";
    else
        cout << "-1\n";
}