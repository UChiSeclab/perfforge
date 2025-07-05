#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_overlap_invariant(const set<pair<int, int>>& o, int current_position) {
    if (!o.empty() && (*o.begin()).first < current_position) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive overlaps!" << endl;
        abort();
    }
}

void check_set_operation_invariant(int erase_count) {
    if (erase_count > 1000) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - frequent set operations!" << endl;
        abort();
    }
}

void check_nested_iteration_invariant(int iteration_count) {
    if (iteration_count > 1000) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested iterations!" << endl;
        abort();
    }
}

void solve() {
    int n;
    cin >> n;
    int N = 2e6 + 1;
    set<pair<int, int> > o;
    string s[n], ans(N, ' ');
    int l = 0, k[n];
    int erase_count = 0;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int M = s[i].size();
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            int p;
            cin >> p;
            p--;
            l = max(l, p + M);
            o.insert({p, i});
        }
    }

    int iteration_count = 0;
    for (int i = 0; i < l;) {
        check_overlap_invariant(o, i);
        while (!o.empty() && (*o.begin()).first + s[(*o.begin()).second].size() - 1 < i) {
            o.erase(*o.begin());
            erase_count++;
            check_set_operation_invariant(erase_count);
        }
        if ((*o.begin()).first > i) {
            ans[i] = 'a';
            i++;
        } else {
            int kk = (*o.begin()).second;
            int p = i;
            for (int j = i - (*o.begin()).first; j < s[kk].size(); j++, p++) {
                ans[p] = s[kk][j];
                iteration_count++;
            }
            check_nested_iteration_invariant(iteration_count);
            i = p;
        }
    }
    for (int i = 0; i < l; i++) cout << ans[i];
}

int main() {
    int q = 1;
    for (int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}