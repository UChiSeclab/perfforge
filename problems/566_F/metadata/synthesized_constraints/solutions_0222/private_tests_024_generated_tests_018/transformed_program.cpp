#include <bits/stdc++.h>
using namespace std;
int dp[1000005];

// Checkers for performance bottlenecks
void check_smallest_element_invariant(int a) {
    if (a == 1) {
        cerr << "Warning: Performance bottleneck condition triggered! Smallest element is 1, causing excessive iterations." << endl;
        abort();
    }
}

void check_multiples_coverage_invariant(int a) {
    if (a < 10) { // Arbitrarily chosen small threshold for demonstration purposes
        cerr << "Warning: Performance bottleneck condition triggered! Small number with extensive multiples coverage." << endl;
        abort();
    }
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    while (n--) {
        int a;
        scanf("%d", &a);

        // Call performance checks
        check_smallest_element_invariant(a);
        check_multiples_coverage_invariant(a);

        dp[a] = max(dp[a], 1);
        for (int i = 2 * a; i < 1000005; i += a) dp[i] = max(dp[i], 1 + dp[a]);
        ans = max(ans, dp[a]);
    }
    printf("%d", ans);
}