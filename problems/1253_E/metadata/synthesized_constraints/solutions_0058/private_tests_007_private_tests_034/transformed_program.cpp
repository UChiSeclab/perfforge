#include <bits/stdc++.h>
using namespace std;

// Function to check for large overlapping segments
void check_input_size_and_segment_range(int n, int m, const vector<pair<int, int>>& ranges) {
    int overlapCount = 0;
    for (size_t i = 0; i < ranges.size(); ++i) {
        for (size_t j = i + 1; j < ranges.size(); ++j) {
            if (max(ranges[i].first, ranges[j].first) <= min(ranges[i].second, ranges[j].second)) {
                ++overlapCount;
            }
        }
    }
    if (n >= 70 && overlapCount > (n * (n - 1)) / 4) {
        cerr << "Warning: Potential slowdown due to large number of overlapping segments!" << endl;
        abort();
    }
}

// Function to check for sparse initial coverage
void check_sparse_coverage(int m, const vector<pair<int, int>>& initialCoverages) {
    int coveredPositions = 0;
    vector<bool> covered(m + 1, false);
    for (const auto& range : initialCoverages) {
        for (int i = max(1, range.first); i <= min(m, range.second); ++i) {
            if (!covered[i]) {
                covered[i] = true;
                ++coveredPositions;
            }
        }
    }
    if (coveredPositions < m / 2) {
        cerr << "Warning: Sparse initial coverage detected, leading to potential high expansion costs!" << endl;
        abort();
    }
}

// Function to check for small initial scope antennas
void check_small_initial_scope(const vector<pair<int, int>>& antennas, int m) {
    int smallScopeCount = 0;
    for (const auto& antenna : antennas) {
        int initialCoverage = antenna.second - antenna.first;
        if (initialCoverage < m / 10) {
            ++smallScopeCount;
        }
    }
    if (smallScopeCount > antennas.size() / 2) {
        cerr << "Warning: Many antennas with small initial scope detected!" << endl;
        abort();
    }
}

vector<pair<int, int> > seg[100002];
int n, m, dp[100002], x, y, l;

int solve(int x) {
    if (x > m) return 0;
    if (dp[x] != -1) return dp[x];
    dp[x] = 1 + solve(x + 1);
    for (auto it : seg[x]) dp[x] = min(dp[x], it.second + solve(it.first + 1));
    return dp[x];
}

int main() {
    cin >> n >> m;
    vector<pair<int, int>> initialCoverages;
    vector<pair<int, int>> antennas;

    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        for (int j = 1; j <= x - y; j++) {
            seg[j].push_back({2 * x - j, max(0, x - j - y)});
        }
        for (int j = max(1, x - y); j <= min(m, x + y); j++)
            seg[j].push_back({x + y, 0});
        
        // Record initial coverages and antennas
        initialCoverages.push_back({x - y, x + y});
        antennas.push_back({x, y});
    }

    // Execute performance checks
    check_input_size_and_segment_range(n, m, initialCoverages);
    check_sparse_coverage(m, initialCoverages);
    check_small_initial_scope(antennas, m);

    memset(dp, -1, sizeof(dp));
    cout << solve(1);
    return 0;
}