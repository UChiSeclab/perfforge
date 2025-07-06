#include <bits/stdc++.h>
using namespace std;

int n, c, d, a, b, ans, cmax, dmax;
char type;
vector<pair<int, int>> coin_list, diamond_list;

// Performance checker functions
void check_large_list_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large list with repeated combinations" << endl;
        abort();
    }
}

void check_cost_threshold_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - cost thresholds allow extensive searches" << endl;
        abort();
    }
}

void check_insufficient_constraints_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - insufficient constraints on search space" << endl;
        abort();
    }
}

void calc(vector<pair<int, int>> x, int avail) {
    int sz = x.size();
    if (sz < 2) return;

    // Check for large list condition
    check_large_list_invariant(sz > 1000);  // arbitrary threshold for demonstration

    vector<int> vect(100007);
    vect[0] = x[0].second;
    for (int i = 1; i < sz; i++) vect[i] = max(vect[i - 1], x[i].second);
    for (int i = sz - 1; i > 0; i--) {
        int j;
        for (j = 0; j < i; j++)
            if (x[i].first + x[j].first > avail) break;
        j -= 1;
        if (j - 1 == i) break;
        if (j >= 0) ans = max(ans, x[i].second + vect[j]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c >> d;

    // Check for cost threshold condition
    check_cost_threshold_invariant(c > 90000 || d > 90000); // arbitrary high threshold

    while (n--) {
        cin >> a >> b >> type;
        if (type == 'C') {
            if (b > c) continue;
            coin_list.push_back(make_pair(b, a));
            cmax = max(cmax, a);
        } else {
            if (b > d) continue;
            diamond_list.push_back(make_pair(b, a));
            dmax = max(dmax, a);
        }
    }

    // Check for insufficient constraints on search space
    check_insufficient_constraints_invariant((coin_list.size() > 10) && (diamond_list.size() > 10)); // arbitrary combined condition

    sort(coin_list.begin(), coin_list.end());
    sort(diamond_list.begin(), diamond_list.end());
    calc(coin_list, c);
    calc(diamond_list, d);
    if (diamond_list.size() && coin_list.size()) ans = max(ans, cmax + dmax);
    cout << ans;
}