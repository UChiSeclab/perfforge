#include <bits/stdc++.h>
using namespace std;

long long n, m;

void check_temperature_invariant(long long t, long long T) {
    if (t >= T) {
        cerr << "Warning: Temperature invariant triggered - stable temperature exceeds threshold!" << endl;
        abort();
    }
}

void check_compensation_invariant(long long t, long long T) {
    if (t >= T) {
        cerr << "Warning: Compensation invariant triggered - compensation required for all schoolchildren!" << endl;
        abort();
    }
}

long long min_fee(long long t, long long T, long long x, long long cost) {
    // Check for temperature invariant
    check_temperature_invariant(t, T);

    if (t >= T) return cost + m * x;
    
    long long case_1, case_2, case_3;
    
    // Check for compensation invariant
    if (m + t > T) {
        check_compensation_invariant(t, T);
        case_1 = cost + m * x;
    } else {
        case_1 = cost;
        return case_1;
    }
    
    long long bus = (long long)ceil((double)m / (T - t));
    case_2 = cost * bus;
    
    if (bus > 1) {
        bus -= 1;
        case_3 = cost * bus;
        long long p = m - (T - t) * (bus - 1);
        if (p + t > T)
            case_3 += cost + p * x;
        else
            case_3 += cost;
        return min(case_3, min(case_1, case_2));
    } else
        return min(case_1, case_2);
}

int main() {
    long long ans = 0;
    long long t, T, x, cost;
    scanf("%I64d%I64d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%I64d%I64d%I64d%I64d", &t, &T, &x, &cost);
        ans += min_fee(t, T, x, cost);
    }
    printf("%I64d\n", ans);
    return 0;
}