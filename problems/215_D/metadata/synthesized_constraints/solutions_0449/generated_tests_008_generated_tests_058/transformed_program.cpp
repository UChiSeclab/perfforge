#include <bits/stdc++.h>
using namespace std;

// Check if the temperature exceeds the limit frequently due to large 'M'
void check_temperature_exceedance(long long t, long long T, long long M) {
    if (t + M > T) {
        cerr << "Warning: Performance bottleneck condition triggered! Temperature exceeds limit frequently." << endl;
        abort();
    }
}

// Check if the comfortable margin in temperature is too small
void check_small_comfortable_margin(long long t, long long T) {
    if (T - t < 10) { // Arbitrary small margin threshold
        cerr << "Warning: Performance bottleneck condition triggered! Small comfortable margin." << endl;
        abort();
    }
}

// Check if the cost per region is high due to large 'N' and bus cost
void check_high_cost_per_region(long long N, long long cost, long long compensation) {
    if (N > 1000 && cost > compensation) { // 1000 is an arbitrary large threshold for regions
        cerr << "Warning: Performance bottleneck condition triggered! High cost per region." << endl;
        abort();
    }
}

int main() {
    long long N, M, t, T, x, cost;
    scanf("%I64d %I64d", &N, &M);
    long long res = 0;
    for (int i = 0, max_ = (N); i < max_; ++i) {
        scanf("%I64d %I64d %I64d %I64d", &t, &T, &x, &cost);

        // Apply the invariant checks
        check_temperature_exceedance(t, T, M);
        check_small_comfortable_margin(t, T);
        check_high_cost_per_region(N, cost, M * x);

        long long cost1 = cost;
        if (t + M > T) cost1 += M * x;
        long long cost2 = numeric_limits<long long>::max();
        if (T > t) {
            long long count = M / (T - t);
            if (M % (T - t)) ++count;
            cost2 = count * cost;
        }
        res += min(cost1, cost2);
    }
    printf("%I64d\n", res);
    return 0;
}