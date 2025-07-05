#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = numeric_limits<int>::max();
int a, n, m, w[2001], dp[2001];
bool rain[2000];

// Function to check quadratic loop complexity
void check_quadratic_loop_invariant(int a, int i) {
    if (i > a - 50) {  // Arbitrary, but ensures we're near the max value of `a`
        cerr << "Warning: Performance bottleneck condition triggered - approaching quadratic loop limit!" << endl;
        abort();
    }
}

// Function to check umbrella weight computation
void check_umbrella_weight_invariant(int a, int weight_updates) {
    if (weight_updates > 10000 && a > 1900) {  // Arbitrary threshold for weight updates
        cerr << "Warning: Performance bottleneck condition triggered - excessive umbrella weight computations!" << endl;
        abort();
    }
}

// Function to check dynamic programming table update
void check_dp_table_update_invariant(int a, int dp_updates) {
    if (dp_updates > 2 * a * a) {  // Captures O(a^2) behavior
        cerr << "Warning: Performance bottleneck condition triggered - excessive DP table updates!" << endl;
        abort();
    }
}

int main() {
    scanf("%d %d %d", &a, &n, &m);
    fill(dp, dp + a + 1, MAX);
    while (n-- > 0) {
        int l, r;
        scanf("%d %d", &l, &r);
        while (l < r) rain[l++] = true;
    }
    while (m-- > 0) {
        int x, p;
        scanf("%d %d", &x, &p);
        if (x < a) {
            x++;
            if (w[x] == 0 || w[x] > p) w[x] = p;
        }
    }
    
    int weight_updates = 0; // Track how often weights are updated
    int dp_updates = 0;     // Track how many times dp is updated

    for (int i = 0; i < a; i++) {
        check_quadratic_loop_invariant(a, i);
        
        int m = i == 0 ? 0 : *min_element(dp, dp + i + 1);
        dp[0] = rain[i] ? MAX : m;
        dp[i + 1] = m < MAX && w[i + 1] > 0 ? m + w[i + 1] : MAX;
        dp_updates++;

        for (int j = 1; j <= i; j++) {
            if (dp[j] < MAX) {
                dp[j] += w[j];
                weight_updates++;
            }
        }

        check_umbrella_weight_invariant(a, weight_updates);
        check_dp_table_update_invariant(a, dp_updates);
    }

    int ans = *min_element(dp, dp + a + 1);
    printf("%d\n", ans < MAX ? ans : -1);
    return 0;
}