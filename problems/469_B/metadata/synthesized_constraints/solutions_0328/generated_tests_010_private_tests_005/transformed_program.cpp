#include <bits/stdc++.h>
using namespace std;
const int modo = 10000007, LL = 1e-9;

// Function declarations for our invariants
void check_overlap_potential(const vector<pair<int, int>>& v, const vector<pair<int, int>>& v1, int l, int r);
void check_large_range_difference(int l, int r);
void check_time_range_iteration(const vector<pair<int, int>>& v1, int r);

int main() {
    ios_base::sync_with_stdio(0);
    int p, q, r, l;
    cin >> p >> q >> l >> r;
    vector<pair<int, int>> v(p), v1(q);
    for (int i = 0; i < p; i++) cin >> v[i].first >> v[i].second;
    for (int i = 0; i < q; i++) cin >> v1[i].first >> v1[i].second;

    // Insert checks after data input and before main computation
    check_overlap_potential(v, v1, l, r);
    check_large_range_difference(l, r);
    check_time_range_iteration(v1, r);

    set<int> s;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < q; k++) {
                int a = v1[k].first + i;
                int b = v1[k].second + i;
                for (int u = a; u <= b; u++)
                    if (u >= v[j].first && u <= v[j].second) s.insert(i);
            }
        }
    }
    cout << s.size() << endl;
}