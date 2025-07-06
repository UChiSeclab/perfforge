#include <bits/stdc++.h>
using namespace std;

// Function to check for wide range invariant
void check_wide_range_invariant(int p, const vector<pair<int, int>>& intervals) {
    int totalRange = 0;
    for (const auto& interval : intervals) {
        totalRange += (interval.second - interval.first + 1);
    }
    if (totalRange > 500) { // Arbitrarily chosen threshold based on the problem constraints
        cerr << "Warning: wide_range_invariant triggered - Little Z's intervals cover a wide range." << endl;
        abort();
    }
}

// Function to check for large wake-up time range invariant
void check_large_wake_up_range_invariant(int l, int r) {
    if ((r - l) > 100) { // Arbitrary threshold considering the problem constraints
        cerr << "Warning: large_wake_up_range_invariant triggered - Large range of wake-up times." << endl;
        abort();
    }
}

// Function to check for dense intervals invariant
void check_dense_intervals_invariant(int p, const vector<pair<int, int>>& intervals) {
    for (size_t i = 0; i < intervals.size(); ++i) {
        for (size_t j = i + 1; j < intervals.size(); ++j) {
            if (intervals[i].second >= intervals[j].first) {
                cerr << "Warning: dense_intervals_invariant triggered - Overlapping intervals detected." << endl;
                abort();
            }
        }
    }
}

int main() {
    int p, q, l, r, x, y;
    cin >> p >> q >> l >> r;

    vector<pair<int, int>> z_intervals(p);
    for (int i = 0; i < p; i++) {
        cin >> x >> y;
        z_intervals[i] = {x, y};
    }

    // Perform invariant checks on Little Z's intervals
    check_wide_range_invariant(p, z_intervals);
    check_dense_intervals_invariant(p, z_intervals);

    // Perform invariant check on the range of wake-up times
    check_large_wake_up_range_invariant(l, r);

    map<int, int> mp;
    set<int> st;
    
    for (const auto& [x, y] : z_intervals) {
        for (int j = x; j <= y; j++) {
            mp[j] = 1;
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        for (int j = l; j <= r; j++)
            for (int z = x + j; z <= y + j; z++)
                if (mp[z]) {
                    st.insert(j);
                }
    }

    cout << st.size() << endl;
    return 0;
}