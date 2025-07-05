#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: High iteration invariant triggered - too many squares to evaluate." << endl;
        abort();
    }
}

void check_fund_allocation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Fund allocation invariant triggered - complex money management." << endl;
        abort();
    }
}

void check_conditional_branching_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Conditional branching invariant triggered - frequent logic execution." << endl;
        abort();
    }
}

int main() {
    long long n, k, scur, s, sum = 0, i, cur, cmin;
    cin >> n >> k >> s;
    vector<pair<long long, long long>> r(n), r_sort = r;

    // Check for high iteration invariant
    check_high_iteration_invariant(n > 1000);  // Assuming high when n is above a reasonable threshold

    cmin = n - 1;
    n--;

    if (k == 1) {
        for (i = 0; i < n; i++) {
            cin >> r[i].first;
            if (r[i].first > s) cmin = min(cmin, i);
        }
    } else {
        for (i = 0; i < n; i++) {
            cin >> r[i].first;
            r[i].second = i;
        }
        r_sort = r;
        sort(r_sort.rbegin(), r_sort.rend());

        // Check fund allocation complexity
        check_fund_allocation_invariant(s <= *min_element(r.begin(), r.end())->first);

        for (i = 0; i < n && i < k; i++) sum += r_sort[i].first;
        for (cur = 0; cur < n; cur++) {
            scur = sum;
            if (r[cur].first >= r_sort[k - 1].first) {
                scur -= r[cur].first;
            } else {
                scur -= r_sort[k - 1].first;
            }

            // Check for frequent conditional branching
            check_conditional_branching_invariant(scur == s - r[cur].first);

            if (r[cur].first > s - scur) cmin = min(cmin, cur);
        }
    }
    cout << cmin + 1;
}