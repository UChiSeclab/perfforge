#include <bits/stdc++.h>
using namespace std;

// Define the checker functions
void check_high_rank_invariant(int k) {
    if (k > 80) { // threshold chosen based on maximum constraint
        cerr << "Warning: High rank invariant triggered - large k value may cause slowdown!" << endl;
        abort();
    }
}

void check_initial_rank_distribution_invariant(const vector<int>& ranks) {
    int low_rank_count = count(ranks.begin(), ranks.end(), 1);
    if (low_rank_count > 0.5 * ranks.size()) { // more than 50% of soldiers at lowest rank
        cerr << "Warning: Initial rank distribution invariant triggered - many soldiers at lowest rank!" << endl;
        abort();
    }
}

void check_single_soldier_invariant(int n, int first_rank, int k) {
    if (n == 1 && k - first_rank > 80) { // large difference between k and the soldier's rank
        cerr << "Warning: Single soldier invariant triggered - single soldier with low initial rank!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // Check high rank invariant
    check_high_rank_invariant(k);

    vector<int> ranks(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranks[i];
    }

    // Check initial rank distribution invariant
    check_initial_rank_distribution_invariant(ranks);

    // Check single soldier invariant
    // Since ranks are in non-decreasing order, the first element is the lowest rank
    check_single_soldier_invariant(n, ranks[0], k);

    map<int, int> m, tmp;
    for (int i = 0; i < n; i++) {
        m[ranks[i]]++;
    }
    int cnt = 0;
    bool flag;
    while (++cnt) {
        tmp = m;
        for (int i = 1; i < k; i++)
            if (m[i]) {
                tmp[i]--;
                tmp[i + 1]++;
                flag = true;
            }
        if (flag)
            flag = false;
        else
            break;
        m = tmp;
    }
    cout << cnt - 1 << endl;

    return 0;
}