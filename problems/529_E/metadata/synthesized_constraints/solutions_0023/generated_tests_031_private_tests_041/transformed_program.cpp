#include <bits/stdc++.h>
using namespace std;
const int INF = 2100000000;
int n, k, q, x, ans, i, t, L, a[100005];
map<int, int> M;

// Checker functions for performance bottlenecks
void check_high_value_x(int x, int largest_denomination) {
    if (x > 10 * largest_denomination) {  // Assuming large threshold for illustrative purposes
        cerr << "Warning: Performance bottleneck condition triggered: x is too large relative to available denominations!" << endl;
        abort();
    }
}

void check_inefficient_coverage(int n, int x) {
    if (n == 1 && x > 1e6) {
        cerr << "Warning: Performance bottleneck condition triggered: Inefficient coverage with single denomination for large x!" << endl;
        abort();
    }
}

void check_single_denom_large_x(int n, int x) {
    if (n == 1 && x > 1e6) {
        cerr << "Warning: Performance bottleneck condition triggered: Single denomination used for large x!" << endl;
        abort();
    }
}

void check_map_operations(int loop_iterations) {
    if (loop_iterations > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered: Excessive map operations in loops!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d", &n, &L);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        
        // Checkers before processing each request
        check_high_value_x(x, a[n]);  // Check if x is disproportionally large
        check_inefficient_coverage(n, x);  // Check inefficient denomination coverage
        check_single_denom_large_x(n, x);  // Check single denomination effectiveness

        ans = INF;
        M.clear();
        int loop_iterations = 0;
        for (i = 1; i <= n; i++) {
            for (k = 1; k <= L; k++) {
                loop_iterations++;
                if (k * a[i] > x) continue;
                if (k * a[i] == x) {
                    ans = k;
                    continue;
                }
                t = M[x - k * a[i]];
                if (t && t + k <= L) ans = min(ans, M[x - k * a[i]] + k);
            }
            for (k = 1; k <= L; k++) {
                loop_iterations++;
                t = M[k * a[i]];
                if (!t || t > k) M[k * a[i]] = k;
            }
        }
        
        // Check map operations after key loop processing
        check_map_operations(loop_iterations);

        if (ans == INF)
            puts("-1");
        else
            printf("%d\n", ans);
    }
}