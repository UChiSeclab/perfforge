#include <bits/stdc++.h>
using namespace std;
const int z = (int)1e5 + 111;
int t[z], k[z], d[z], dp[111], n, q, j;

// Function to check high time range iteration
void check_time_range_invariant(int max_t) {
    if (max_t > 900000) {
        cerr << "Warning: Performance bottleneck condition triggered - High time range iteration!" << endl;
        abort();
    }
}

// Function to check high task server requirement
void check_server_requirement_invariant(int ki, int n) {
    if (ki > 0.9 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - High task server requirement!" << endl;
        abort();
    }
}

// Function to check long server occupancy duration
void check_long_duration_invariant(int di) {
    if (di > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - Long server occupancy duration!" << endl;
        abort();
    }
}

// Function to check combined conditions for maximal time and server demands
void check_combined_conditions_invariant(int ti, int ki, int di, int n) {
    if (ti > 900000 && ki > 0.8 * n && di > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - Maximal time and server conditions!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d", &n, &q);
    int max_t = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", &t[i], &k[i], &d[i]);
        max_t = max(max_t, t[i]);
        
        // Check performance invariants
        check_server_requirement_invariant(k[i], n);
        check_long_duration_invariant(d[i]);
        check_combined_conditions_invariant(t[i], k[i], d[i], n);
    }
    
    check_time_range_invariant(max_t);
    
    for (int i = 1; i <= (int)1e6; i++) {
        int p = 0, ans = 0;
        while (t[j] < i) j++;
        if (j >= q) break;
        for (int i = 1; i <= n; i++) {
            if (dp[i]) dp[i]--;
            if (!dp[i]) p++;
        }
        if (t[j] > i) continue;
        if (k[j] <= p) {
            for (int i = 1; i <= n; i++)
                if (!dp[i] && k[j]) {
                    ans += i;
                    dp[i] = d[j];
                    k[j]--;
                }
            cout << ans << '\n';
        } else
            cout << -1 << '\n';
    }
    return 0;
}