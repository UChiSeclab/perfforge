#include <bits/stdc++.h>

// Checker for Invariant #1: Region Temperature and Capacity
void check_region_temp_capacity_invariant(int t, int T, long long m) {
    if (t < T && m > 1000) { // Example threshold for m
        std::cerr << "Warning: Performance bottleneck - complex path for many children in regions with t < T!" << std::endl;
        abort();
    }
}

// Checker for Invariant #2: Calculation of Bus Capacity
void check_bus_capacity_invariant(int t, int T) {
    if ((T - t) < 5) { // Example threshold for small temperature difference
        std::cerr << "Warning: Performance bottleneck - small temperature difference leading to high bus count!" << std::endl;
        abort();
    }
}

// Checker for Invariant #3: Cost Optimization Checks
void check_cost_optimization_invariant(long long cost, long long tmp, long long m, long long x) {
    if ((tmp > cost + m * x) && (m * x < cost)) { // Conditions where cost optimization is significant
        std::cerr << "Warning: Performance bottleneck - frequent cost optimization calculations!" << std::endl;
        abort();
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long t, T, x, cost;
        scanf("%I64d%I64d%I64d%I64d", &t, &T, &x, &cost);
        
        // Check for Region Temperature and Capacity Invariant
        check_region_temp_capacity_invariant(t, T, m);
        
        if (t >= T) {
            ans += cost + m * x;
            continue;
        }
        
        long long cap = T - t;
        // Check for Bus Capacity Invariant
        check_bus_capacity_invariant(t, T);
        
        long long car = (long long)ceil(m / double(cap));
        long long cap2 = cap - car * cap + m;
        long long tmp = car * cost;
        if (car > 1) {
            if (car > cap2 && (cap2 + cap) * x < cost)
                tmp = (car - 1) * cost + (cap2 + cap) * x;
            if (car <= cap2 && m * x < cost) tmp = (car - 1) * cost + m * x;
        }
        
        // Check for Cost Optimization Invariant
        check_cost_optimization_invariant(cost, tmp, m, x);
        
        if (tmp > cost + m * x) tmp = cost + m * x;
        ans += tmp;
    }
    printf("%I64d\n", ans);
    return 0;
}