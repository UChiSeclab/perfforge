#include <bits/stdc++.h>
using namespace std;

// Checker functions from Phase 3 are included here

vector<int> a, b;

int solve(int d) {
    int dd = d + d;
    map<int, int> fa, fb;
    for (int x : a) fa[x % dd]++;
    for (int x : b) fb[x % dd]++;
    
    // Check for high number of unique remainders
    check_remainder_invariant(fa.size(), fb.size());
    
    // Check for similar modulo values causing inefficiencies
    check_similar_modulo_invariant(fa);
    check_similar_modulo_invariant(fb);

    int ans = 0;
    for (auto it : fa) {
        int i = it.first;
        int tmp = fb[(i + d) % dd] + it.second;
        ans = max(ans, tmp);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, y1;
    cin >> n >> y1;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int m, y2;
    cin >> m >> y2;
    b.resize(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    
    // Check for large input arrays
    check_large_input_invariant(n, m);

    int ans = 2;
    for (int i = 0; i < 31; i++) {
        ans = max(ans, solve(1 << i));

        // Check for frequent recalculations with minimal gain
        check_reflection_invariant(1 << i, 1 << 20); // Example max_possible_d
    }
    swap(a, b);
    for (int i = 0; i < 31; i++) {
        ans = max(ans, solve(1 << i));

        // Check for frequent recalculations with minimal gain
        check_reflection_invariant(1 << i, 1 << 20); // Example max_possible_d
    }
    cout << ans << endl;
    return 0;
}