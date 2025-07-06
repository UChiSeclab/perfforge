#include <bits/stdc++.h>
using namespace std;

// Checker functions based on the identified performance invariants
void check_participant_overlap(int totalParticipants, int sections, int maxSections) {
    if (totalParticipants > 20 && sections > 10) {
        cerr << "Warning: Performance bottleneck due to high participant overlap across sections!" << endl;
        abort();
    }
}

void check_large_vector_sorting(vector<pair<pair<int, int>, int>>& v) {
    for (int i = 1; i <= 100; ++i) {
        if (v[i].size() > 10) {
            cerr << "Warning: Performance bottleneck due to sorting large vectors!" << endl;
            abort();
        }
    }
}

void check_extensive_range(int l, int r, int maxSections) {
    if ((r - l + 1) > (maxSections / 2)) {
        cerr << "Warning: Performance bottleneck due to extensive section range for a participant!" << endl;
        abort();
    }
}

long long int maxx(long long int a, long long int b) { return a > b ? a : b; }
vector<pair<pair<int, int>, int>> v[101];

void solve() {
    int n, m;
    cin >> n >> m;

    // Check for potential overlap issues with participants and sections
    check_participant_overlap(m, n, 100);

    for (int i = 0; i < m; i++) {
        int l, r, t, c;
        cin >> l >> r >> t >> c;

        // Check for extensive range of sections for each participant
        check_extensive_range(l, r, n);

        for (int j = l; j <= r; j++) {
            v[j].push_back({{t, i}, c});
        }
    }

    // Check for large vector sorting issues in each section after data input
    check_large_vector_sorting(v);

    for (int i = 1; i <= 100; i++) {
        sort(v[i].begin(), v[i].end());
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        if (v[i].size() > 0) ans += v[i][0].second;
    }
    cout << ans << endl;
}

int main() {
    solve();
}