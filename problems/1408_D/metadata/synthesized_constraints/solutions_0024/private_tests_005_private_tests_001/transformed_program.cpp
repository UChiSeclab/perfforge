#include <bits/stdc++.h>
using namespace std;
const long long int inf = (long long int)2e18;
const int mod = 1e9 + 7;

void check_outer_loop_invariant(int i) {
    if (i >= 1e6) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive outer loop iterations!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n, int m) {
    if (m > n * 10) {  // Arbitrary chosen threshold indicating significant imbalance
        cerr << "Warning: Performance bottleneck condition triggered - inefficient nested loop operations!" << endl;
        abort();
    }
}

void check_position_invariant(const vector<pair<int, int>>& robber, const vector<pair<int, int>>& light) {
    for (const auto& r : robber) {
        for (const auto& l : light) {
            if (r.first <= l.first && r.second <= l.second) {
                cerr << "Warning: Performance bottleneck condition triggered - unfavorable position overlap!" << endl;
                abort();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > robber(n), light(m);
    for (int i = 0; i < n; i++) {
        cin >> robber[i].first >> robber[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> light[i].first >> light[i].second;
    }
    
    // Check for nested loop imbalance
    check_nested_loop_invariant(n, m);
    
    sort(light.begin(), light.end());
    sort(robber.begin(), robber.end());
    int sufmax[m + 1];
    sufmax[m] = 0;
    for (int i = m - 1; i >= 0; i--)
        sufmax[i] = max(sufmax[i + 1], light[i].second);
    int mini = 1e9;
    for (int i = 0; i < 1e6 + 2; i++) {
        int req = 0, k = 0, j;
        for (j = 0; j < n; j++) {
            while (k < m && light[k].first < robber[j].first + i) k++;
            if (k == m) break;
            req = max(req, sufmax[k] - robber[j].second + 1);
        }
        mini = min(mini, req + i);
        if (j == 0 || i > mini) break;
        
        // Check for excessive loop iterations
        check_outer_loop_invariant(i);
    }
    
    // Check for unfavorable position overlap
    check_position_invariant(robber, light);
    
    cout << mini << "\n";
}