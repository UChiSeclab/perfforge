#include <bits/stdc++.h>
using namespace std;

long long t[100001], T[100001], x[100001], cost[1000001], n, m, k, j, i, ans;

void check_temperature_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: High temperature causing frequent compensation demands!" << endl;
        abort();
    }
}

void check_cost_calculation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Small temperature difference leading to complex cost calculation!" << endl;
        abort();
    }
}

void check_region_complexity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: High number of regions with complex bus cost calculations!" << endl;
        abort();
    }
}

int main() {
    scanf("%I64d%I64d", &m, &n);
    for (i = 1; i <= m; i++)
        scanf("%I64d%I64d%I64d%I64d", &t[i], &T[i], &x[i], &cost[i]);
    ans = 0;
    
    // Check for high number of regions
    check_region_complexity_invariant(m > 50000); // Arbitrary threshold, adjust based on realistic conditions
    
    for (i = 1; i <= m; i++) {
        long long mi;
        
        // Check for high temperature leading to frequent compensation
        check_temperature_invariant(t[i] >= T[i]);
        
        if (t[i] >= T[i]) {
            ans += x[i] * n + cost[i];
            continue;
        }
        
        long long tmp = x[i] * n + cost[i], tmp2 = 0, tmp1 = 0;
        long long d = T[i] - t[i];
        
        // Check for small temperature difference leading to complex cost calculations
        check_cost_calculation_invariant(d < 10); // Arbitrary threshold for small d
        
        k = n / d;
        tmp1 += k * cost[i];
        if (n % d != 0) tmp1 += cost[i];
        mi = min(tmp, tmp1);
        ans += mi;
    }
    printf("%I64d", ans);
}