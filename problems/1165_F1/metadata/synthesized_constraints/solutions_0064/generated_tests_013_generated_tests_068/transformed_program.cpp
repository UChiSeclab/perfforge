#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<pair<int, int>> b;

// Checker for high number of days with sales
void check_days_invariant(int d1) {
    if (d1 > 1000) { // Given the constraints, you might not want d1 to exceed the total number of days
        cerr << "Warning: Performance bottleneck due to high number of days being checked for sales!" << endl;
        abort();
    }
}

// Checker for complex sales conditions
void check_sales_conditions_invariant(const vector<int>& c, int n) {
    int complexCount = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] != -1) complexCount++;
    }
    if (complexCount > n * 0.5) { // Assuming complex conditions if more than half of the types are affected by sales
        cerr << "Warning: Performance bottleneck due to complex sales conditions!" << endl;
        abort();
    }
}

// Checker for large transaction requirements
void check_transaction_requirements_invariant(const vector<int>& a, const vector<int>& c, int n) {
    int highDemand = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 500 && c[i] == -1) { // Threshold for high demand without sales offers
            highDemand++;
        }
    }
    if (highDemand > n * 0.2) { // If more than 20% of types have high demand without sales
        cerr << "Warning: Performance bottleneck due to large transaction requirements!" << endl;
        abort();
    }
}

bool can(int d1) {
    vector<int> c(n, -1);
    for (int i = 0; i < m; i++) {
        if (b[i].first <= d1) c[b[i].second] = max(c[b[i].second], b[i].first);
    }
    check_sales_conditions_invariant(c, n); // Check complex sales conditions here

    vector<int> d[2005];
    for (int i = 0; i < n; i++) {
        if (c[i] != -1) d[c[i]].push_back(i);
    }
    vector<int> e = a;
    int k = 0;
    for (int i = 0; i <= d1; i++) {
        k++;
        for (int j = 0; j < d[i].size() && k; j++) {
            if (k >= e[d[i][j]]) {
                k -= e[d[i][j]];
                e[d[i][j]] = 0;
            } else {
                e[d[i][j]] -= k;
                k = 0;
            }
        }
    }
    int l = 0;
    for (int i = 0; i < n; i++) l += e[i];
    return l * 2 <= k;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }

    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        b.push_back(make_pair(v1 - 1, v2 - 1));
    }
    
    check_transaction_requirements_invariant(a, vector<int>(n, -1), n); // Initial transaction requirement check

    int i = 0;
    while (!can(i)) {
        check_days_invariant(i); // Check number of days with sales
        i++;
    }
    cout << i + 1;
    return 0;
}