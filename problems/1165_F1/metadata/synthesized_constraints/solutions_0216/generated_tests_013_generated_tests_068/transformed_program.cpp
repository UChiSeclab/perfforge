#include <bits/stdc++.h>
using namespace std;

// Check for high number of days processed
void check_days_processed(int current_day) {
    if (current_day > 1000) { // Considering the problem constraints
        cerr << "Warning: Performance bottleneck - High number of days processed!" << endl;
        abort();
    }
}

// Check for mismatch between offers and needs
void check_offer_mismatch(const vector<int>& need, int cur_money) {
    int total_need = accumulate(need.begin(), need.end(), 0);
    if (total_need > cur_money * 2) {
        cerr << "Warning: Offer mismatch - microtransaction needs not aligned with available offers!" << endl;
        abort();
    }
}

int n, m;
vector<int> k;
vector<pair<int, int>> q(1001);

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
    int cur_money = 0;
    for (int i = 0; i <= day; ++i) {
        ++cur_money;
        if (i > 1000) continue;
        for (auto it : off[i]) {
            if (cur_money >= need[it]) {
                cur_money -= need[it];
                need[it] = 0;
            } else {
                need[it] -= cur_money;
                cur_money = 0;
            }
        }
    }
    check_offer_mismatch(need, cur_money); // Check inserted for offer mismatch
    return accumulate(need.begin(), need.end(), 0) * 2 <= cur_money;
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
    for (int l = 0; l <= 2000; ++l) {
        check_days_processed(l); // Check inserted for high number of days processed
        if (can(l)) {
            cout << l + 1 << endl;
            return 0;
        }
    }
    assert(false);
    return 0;
}