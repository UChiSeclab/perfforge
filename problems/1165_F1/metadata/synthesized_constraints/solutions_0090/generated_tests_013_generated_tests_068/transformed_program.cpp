#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> k;
vector<pair<int, int>> q(1001);

// Checker for high iteration count in the day loop
void check_iteration_invariant(int day) {
    if (day > 1000) {
        cerr << "Warning: High iteration count in day loop!" << endl;
        abort();
    }
}

// Checker for frequent processing of offers
void check_offer_processing_invariant(const vector<vector<int>>& off, int day) {
    int offerDays = 0;
    for (int i = 0; i <= day; ++i) {
        if (!off[i].empty()) {
            ++offerDays;
        }
    }
    if (offerDays > 500) { // Arbitrary threshold based on potential slowdown
        cerr << "Warning: Frequent processing of offers!" << endl;
        abort();
    }
}

// Checker for large cumulative need of microtransactions
void check_cumulative_need_invariant(const vector<int>& need) {
    int totalNeed = accumulate(need.begin(), need.end(), 0);
    if (totalNeed > 750) { // Based on the constraint that the sum of k_i is <= 1000
        cerr << "Warning: Large cumulative need for microtransactions!" << endl;
        abort();
    }
}

bool can(int day) {
    vector<int> lst(n, -1);
    for (int i = 0; i < m; ++i) {
        if (q[i].first <= day) {
            lst[q[i].second] = max(lst[q[i].second], q[i].first);
        }
    }
    vector<vector<int>> off(1001);
    for (int i = 0; i < n; ++i) {
        if (lst[i] != -1) {
            off[lst[i]].push_back(i);
        }
    }
    vector<int> need = k;

    // Check invariant for large cumulative need
    check_cumulative_need_invariant(need);

    int money = 0;
    for (int i = 0; i <= day; ++i) {
        ++money;
        if (i > 1000) continue;
        for (auto it : off[i]) {
            if (money >= need[it]) {
                money -= need[it];
                need[it] = 0;
            } else {
                need[it] -= money;
                money = 0;
                break;
            }
        }
    }

    // Check invariant for frequent processing of offers
    check_offer_processing_invariant(off, day);

    return accumulate(need.begin(), need.end(), 0) * 2 <= money;
}

int main() {
    cin >> n >> m;
    k = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
        --q[i].first;
        --q[i].second;
    }
    for (int j = 0; j <= 2000; ++j) {
        // Check invariant for high iteration count
        check_iteration_invariant(j);

        if (can(j)) {
            cout << j + 1 << endl;
            return 0;
        }
    }
    assert(false);
    return 0;
}