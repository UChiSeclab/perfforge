#include <bits/stdc++.h>
using namespace std;

// Invariant Checkers
void check_participant_invariant(int m) {
    if (m > 90) {
        cerr << "Warning: Performance bottleneck condition triggered - too many participants!" << endl;
        abort();
    }
}

void check_range_invariant(const vector<vector<pair<int, pair<int, int>>>> &holder) {
    for (const auto &section : holder) {
        if (section.size() > 20) {
            cerr << "Warning: Performance bottleneck condition triggered - too many participants in a section!" << endl;
            abort();
        }
    }
}

void check_sort_invariant(const vector<vector<pair<int, pair<int, int>>>> &holder) {
    for (const auto &section : holder) {
        if (section.size() > 20) {
            cerr << "Warning: Performance bottleneck condition triggered - excessive sorting due to too many participants!" << endl;
            abort();
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Check invariant on number of participants
    check_participant_invariant(m);

    vector<vector<pair<int, pair<int, int>>>> holder(n);

    for (int i = 0; i < m; i++) {
        int l, r, t, c;
        cin >> l >> r >> t >> c;
        l--, r--;
        for (int j = l; j <= r; j++) {
            holder[j].push_back(make_pair(t, make_pair(i, c)));
        }
    }

    // Check range invariant before sorting
    check_range_invariant(holder);

    for (int i = 0; i < n; i++) {
        sort(holder[i].begin(), holder[i].end());
    }

    // Check sort invariant
    check_sort_invariant(holder);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!holder[i].empty()) {
            ans += holder[i][0].second.second;
        }
    }
    cout << ans << endl;
    return 0;
}