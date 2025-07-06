#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_nested_loops_invariant(int n, int m) {
    if (n * m > 50) {
        cerr << "Warning: Nested loops invariant triggered - high number of combinations." << endl;
        abort();
    }
}

void check_contains_invocation_invariant(int n, int m) {
    if (n + m > 20) {
        cerr << "Warning: Contains function invocation invariant triggered - excessive calls expected." << endl;
        abort();
    }
}

void check_combination_invariant(int n, int m) {
    if (n > 8 || m > 8) {
        cerr << "Warning: Combination invariant triggered - large input sizes." << endl;
        abort();
    }
}

// Original program with integrated checks
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
int n, m;
vector<pair<int, int> > a, b;
vector<pair<int, int> > read(int n) {
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        ans.push_back(make_pair(x, y));
    }
    return ans;
}
bool contains(vector<pair<int, int> > &v, int x, int y) {
    pair<int, int> p = make_pair(x, y);
    pair<int, int> q = make_pair(y, x);
    for (__typeof(v.begin()) it = v.begin(); it != v.end(); it++) {
        if ((*it) == p || (*it) == q) return true;
    }
    return false;
}
bool ok(vector<pair<int, int> > a, vector<pair<int, int> > b) {
    for (int i = 0; i < (int)a.size(); i++) {
        pair<int, int> p = a[i];
        set<int> same;
        for (int j = 0; j < (int)b.size(); j++) {
            if (a[i] == b[j]) continue;
            set<int> cur;
            cur.insert(a[i].first);
            cur.insert(a[i].second);
            cur.insert(b[j].first);
            cur.insert(b[j].second);
            if (cur.size() != 3) continue;
            if (a[i].first == b[j].first || a[i].first == b[j].second)
                same.insert(a[i].first);
            else if (a[i].second == b[j].first || a[i].second == b[j].second)
                same.insert(a[i].second);
        }
        if (same.size() == 0) continue;
        if (same.size() > 1) return false;
    }
    return true;
}
int main() {
    cin >> n >> m;

    // Perform invariant checks
    check_nested_loops_invariant(n, m);
    check_contains_invocation_invariant(n, m);
    check_combination_invariant(n, m);

    a = read(n);
    b = read(m);
    set<int> ans;
    for (int x = 1; x < 10; x++) {
        for (int y = 1; y < 10; y++) {
            for (int z = 1; z < 10; z++) {
                if (x == y || x == z || y == z) continue;
                if (contains(a, x, y) && contains(b, x, z)) {
                    ans.insert(x);
                }
            }
        }
    }
    if (ans.size() == 1) {
        cout << (*ans.begin()) << endl;
        return 0;
    }
    if (ok(a, b) && ok(b, a))
        cout << 0 << endl;
    else
        cout << -1 << endl;
    return 0;
}