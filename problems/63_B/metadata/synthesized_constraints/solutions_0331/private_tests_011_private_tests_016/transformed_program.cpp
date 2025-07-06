#include <bits/stdc++.h>
using namespace std;

// Phase 3: Add the helper functions for invariants
void check_uniform_low_ranks_invariant(int n, const vector<int>& ranks, int k) {
    if (n == 100 && ranks.front() == 1 && ranks.back() < k) {
        cerr << "Warning: Performance bottleneck condition triggered - uniform low ranks with large n." << endl;
        abort();
    }
}

void check_minimal_ranks_with_large_n_invariant(int n, const vector<int>& ranks) {
    int uniqueRanks = std::set<int>(ranks.begin(), ranks.end()).size();
    if (n == 100 && uniqueRanks == 1 && ranks.front() == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - minimal ranks with maximum soldiers." << endl;
        abort();
    }
}

void check_maximum_upgrades_needed_invariant(int n, const vector<int>& ranks, int k) {
    if (n == 100 && std::all_of(ranks.begin(), ranks.end(), [&](int rank) { return rank == 1; })) {
        cerr << "Warning: Performance bottleneck condition triggered - all soldiers require maximum upgrades." << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    // Phase 4: Insert checks after reading input
    check_uniform_low_ranks_invariant(n, t, m);
    check_minimal_ranks_with_large_n_invariant(n, t);
    check_maximum_upgrades_needed_invariant(n, t, m);

    if (n == 1) {
        cout << m - t[0];
        return 0;
    }
    int ans = 0;
    for (int k = 0; k < n * n * n; k++) {
        set<int> st;
        for (int i = 0; i < n; i++) {
            if (st.count(t[i]) == 0 && t[i] < m) {
                st.insert(t[i]);
                t[i]++;
            }
        }
        if (st.size()) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}