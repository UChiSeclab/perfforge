#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5 + 9;
int m, n, k, t;
int a[MAXN];
int occ[MAXN];
vector<pair<pair<int, int>, int>> v;

// Checkers to detect performance bottlenecks
void check_trap_influence_invariant(int trapCount, int threshold) {
    if (trapCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - High frequency of non-zero trap influence!" << endl;
        abort();
    }
}

void check_extensive_iteration_invariant(int rangeSize, int threshold) {
    if (rangeSize > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - Extensive iteration over large range!" << endl;
        abort();
    }
}

void check_trap_density_invariant(int activeTrapCount, int threshold) {
    if (activeTrapCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - High trap density with stringent agility requirements!" << endl;
        abort();
    }
}

bool check(int x) {
    int mn = a[x - 1];
    long long int ret = 0;
    memset(occ, 0, sizeof occ);
    
    int activeTrapCount = 0;
    for (int i = 0; i < k; i++) {
        int d = v[i].second;
        int l = v[i].first.first;
        int r = v[i].first.second;
        if (d > mn) {
            occ[l]++;
            occ[r + 1]--;
            activeTrapCount++;
        }
    }
    
    // Check performance bottleneck for trap density
    check_trap_density_invariant(activeTrapCount, 1000); // arbitrary threshold
    
    for (int i = 1; i < MAXN; i++) {
        occ[i] += occ[i - 1];
        ret += 2 * (occ[i] > 0);
    }
    
    // Check performance bottleneck for extensive iteration
    check_extensive_iteration_invariant(MAXN, 100000);  // arbitrary threshold

    ret += n + 1;
    return ret <= t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n >> k >> t;
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(a, a + m);
    reverse(a, a + m);
    for (int i = 0; i < k; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        v.push_back({{l, r}, d});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int l = 1, r = m;
    while (l <= r) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << ans << "\n";
}