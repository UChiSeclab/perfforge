#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, l[N], r[N], a[N];

// Add helper functions for invariant checks
void check_high_overlap_invariant(int max_overlap) {
    if (max_overlap > 2) {
        cerr << "Warning: High overlap invariant triggered - too many overlapping lessons!" << endl;
        abort();
    }
}

void check_long_interval_range_invariant(int le, int rg) {
    if (le != 2e9 && rg - le > 10000) {  // arbitrary threshold for large range
        cerr << "Warning: Long interval range invariant triggered - large time range overlap!" << endl;
        abort();
    }
}

void check_dense_collision_invariant(int overlap_slots) {
    if (overlap_slots > 1000) {  // arbitrary threshold for dense collision
        cerr << "Warning: Dense collision invariant triggered - dense overlaps!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        r[i]--;
        a[l[i]]++, a[r[i] + 1]--;
    }

    int max_overlap = 0, overlap_slots = 0;
    for (int i = 1; i < N; i++) {
        a[i] += a[i - 1];
        max_overlap = max(max_overlap, a[i]);
        if (a[i] >= 2) overlap_slots++;
    }

    // Insert checks after processing the array `a`
    check_high_overlap_invariant(max_overlap);
    check_dense_collision_invariant(overlap_slots);

    int le = 2e9, rg = n;
    for (int i = 1; i < N; i++) {
        if (a[i] > 2) {
            le = -1;
            break;
        }
        if (a[i] == 2) {
            le = min(le, i);
            rg = max(rg, i);
        }
    }

    // Another check after determining the overlap range
    check_long_interval_range_invariant(le, rg);

    vector<int> res;
    for (int i = 1; i <= n; i++)
        if (le == 2e9 || (l[i] <= le && r[i] >= rg)) res.push_back(i);

    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
    return 0;
}