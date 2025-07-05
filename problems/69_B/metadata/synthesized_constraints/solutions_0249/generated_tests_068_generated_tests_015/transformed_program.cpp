#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

struct item {
    int c, t, num;
};

bool boolf(item p, item p1) {
    return p.t < p1.t || (p.t == p1.t && p.num < p1.num);
}

// Checker functions for performance invariants
void check_sort_invariant(int total_athletes, int total_sections) {
    if (total_athletes / total_sections > 10) { // Example threshold
        cerr << "Warning: sort_invariant triggered - too many athletes per section." << endl;
        abort();
    }
}

void check_overlap_invariant(int max_overlap, int threshold = 20) {
    if (max_overlap > threshold) {
        cerr << "Warning: overlap_invariant triggered - excessive overlap in sections." << endl;
        abort();
    }
}

void check_coverage_invariant(int total_coverage, int num_athletes) {
    if (total_coverage / num_athletes > 15) { // Example threshold
        cerr << "Warning: coverage_invariant triggered - high average section coverage." << endl;
        abort();
    }
}

int main() {
    int n, m, i, j;
    cin >> n >> m;
    vector<item> a[200];
    int total_coverage = 0;
    int max_overlap = 0;

    for (int i = 0; i < m; i++) {
        int l, r, t, c;
        cin >> l >> r >> t >> c;
        item tt;
        tt.num = i;
        tt.t = t;
        tt.c = c;
        total_coverage += (r - l + 1);
        for (j = l; j <= r; j++) {
            a[j].push_back(tt);
            max_overlap = max(max_overlap, (int)a[j].size());
        }
    }

    // Execute checkers after data input
    check_sort_invariant(m, n); // Check for sorting bottleneck
    check_overlap_invariant(max_overlap); // Check for section overlap issues
    check_coverage_invariant(total_coverage, m); // Check for average coverage issues

    int ans = 0;
    for (i = 1; i <= n; i++) {
        if (a[i].empty()) continue;
        sort(a[i].begin(), a[i].end(), boolf);
        item anst = a[i][0];
        ans += anst.c;
    }
    cout << ans;
    return 0;
}