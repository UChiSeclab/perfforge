#include <bits/stdc++.h>
using namespace std;

int n, m, i, j, k, ans = 0, za, ma, xi = -1, yi = -1, q, ma1 = -1, ma2 = -1, x, y, c, d, in;
vector<pair<int, int>> vx[2];
char ch;

// High cost capacity trigger
void check_high_cost_capacity(int c, int d) {
    if (c + d > 150000) {
        cerr << "Warning: Performance bottleneck condition triggered - high cost capacity!" << endl;
        abort();
    }
}

// High coin/diamond value for fountains
void check_high_value_fountains(const vector<pair<int, int>>& vxC, const vector<pair<int, int>>& vxD, int c, int d) {
    for (const auto& fountain : vxC) {
        if (fountain.first > c * 0.8) {
            cerr << "Warning: Performance bottleneck condition triggered - high coin value for a fountain!" << endl;
            abort();
        }
    }
    for (const auto& fountain : vxD) {
        if (fountain.first > d * 0.8) {
            cerr << "Warning: Performance bottleneck condition triggered - high diamond value for a fountain!" << endl;
            abort();
        }
    }
}

// Maximum search space exploration
void check_search_space_exploration(int c, int d) {
    if (c > 80000 || d > 80000) {
        cerr << "Warning: Performance bottleneck condition triggered - maximum search space exploration!" << endl;
        abort();
    }
}

int func(int p) {
    if (p == 0) {
        in = c;
    } else {
        in = d;
    }
    q = -1;
    m = vx[p].size();
    
    multiset<int> mu;
    multiset<int>::iterator it;
    for (i = 1; i < m; i++) {
        x = vx[p][i].first;
        y = vx[p][i].second;
        if (x == vx[p][i - 1].first && 2 * x <= in) {
            q = max(q, y + vx[p][i - 1].second);
        }
    }
    for (i = 0; i < m; i++) {
        x = vx[p][i].first;
        y = vx[p][i].second;
        if (2 * x <= in) {
            mu.insert(y);
        }
    }
    if (mu.size() > 1) {
        it = mu.end();
        it--;
        x = *it;
        it--;
        y = *it;
        q = max(q, x + y);
    }
    int dp[100005] = {0};
    for (i = 0; i < m; i++) {
        x = vx[p][i].first;
        y = vx[p][i].second;
        dp[x] = max(dp[x], y);
    }
    for (i = 1; 2 * i <= in; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
    }
    for (i = in; i > 0; i--) {
        j = in - i;
        if (dp[i] > 0 && dp[j] > 0 && i != j) {
            q = max(q, dp[i] + dp[j]);
        }
    }
    return q;
}

int main() {
    cin >> n >> c >> d;

    // Run initial checks after reading input
    check_high_cost_capacity(c, d);
    check_search_space_exploration(c, d);

    for (i = 0; i < n; i++) {
        cin >> x >> y >> ch;
        if (ch == 'C') {
            vx[0].push_back(make_pair(y, x));
        } else {
            vx[1].push_back(make_pair(y, x));
        }
    }

    // Check for high value fountains
    check_high_value_fountains(vx[0], vx[1], c, d);

    sort(vx[0].begin(), vx[0].end());
    sort(vx[1].begin(), vx[1].end());

    for (i = 0; i < vx[0].size(); i++) {
        x = vx[0][i].first;
        y = vx[0][i].second;
        if (x <= c) {
            xi = max(xi, y);
        }
    }
    for (i = 0; i < vx[1].size(); i++) {
        x = vx[1][i].first;
        y = vx[1][i].second;
        if (x <= d) {
            yi = max(yi, y);
        }
    }
    za = func(0);
    ma = max(ma, za);
    za = func(1);
    ma = max(ma, za);
    if (ma == -1) {
        if (xi == -1 || yi == -1) {
            cout << "0";
        } else {
            cout << xi + yi;
        }
    } else {
        if (xi == -1 || yi == -1) {
            cout << ma;
        } else {
            cout << max(ma, xi + yi);
        }
    }
    return 0;
}