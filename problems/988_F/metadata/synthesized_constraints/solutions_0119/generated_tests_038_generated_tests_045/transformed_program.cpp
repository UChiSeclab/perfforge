#include <bits/stdc++.h>
using namespace std;
int n, m, a;
long long memo[2020][2020];
long long umb[2020];
int rain[2020];

void check_memoization_efficiency(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck detected due to inadequate memoization!" << endl;
        abort();
    }
}

void check_umbrella_states(bool condition) {
    if (condition) {
        cerr << "Warning: Potential slowdown from evaluating large combinations of umbrella states!" << endl;
        abort();
    }
}

void check_rain_transition(bool condition) {
    if (condition) {
        cerr << "Warning: Performance issue due to frequent transitions between rain segments!" << endl;
        abort();
    }
}

long long dp(int i, int u) {
    // Check for high recursive depth without effective memoization
    check_memoization_efficiency(memo[i][u] == -1 && i > 1500); // Example threshold
    
    if (i == a) return 0;
    long long &ret = memo[i][u];
    if (ret != -1) return ret;
    
    if (rain[i]) {
        ret = umb[i] + dp(i + 1, i);
        if (u != a) ret = min(ret, umb[u] + dp(i + 1, u));
    } else {
        long long w = (u == a) ? 0 : umb[u];
        ret = w + dp(i + 1, u);
        ret = min(ret, dp(i + 1, a));
        ret = min(ret, umb[i] + dp(i + 1, i));
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> n >> m;
    
    // Check for large umbrella states
    check_umbrella_states(m > 1800); // Example threshold

    for (int i = 0; i < n; i++) {
        int L, R;
        cin >> L >> R;
        
        // Check for frequent transitions between rain segments
        check_rain_transition((R - L) < 2 && i > 0); // Example threshold
        
        for (int j = L; j < R; j++) rain[j] = 1;
    }
    
    for (int i = 0; i < a + 10; i++) umb[i] = 1e14;
    
    for (int i = 0; i < m; i++) {
        long long x, p;
        cin >> x >> p;
        umb[x] = min(umb[x], p);
    }
    
    memset(memo, -1, sizeof memo);
    long long ans = dp(0, a);
    if (ans > 1e13) ans = -1;
    cout << ans << endl;
    return 0;
}