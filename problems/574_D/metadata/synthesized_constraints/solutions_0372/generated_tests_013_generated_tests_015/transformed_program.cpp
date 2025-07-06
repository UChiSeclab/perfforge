#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const int INF = (1 << 29);
long long dp[2][maxn];
long long a[maxn];
int n;

// Check if the number of towers is close to the upper limit
void check_input_size_invariant(int n) {
    if (n > 100000) { // n is close to the upper constraint limit
        cerr << "Warning: Performance bottleneck condition triggered - large number of towers!" << endl;
        abort();
    }
}

// Check if there are frequent small peaks and valleys causing more operations
void check_height_variability_invariant(const vector<long long>& heights) {
    int variability_count = 0;
    for (size_t i = 1; i < heights.size() - 1; ++i) {
        if ((heights[i] > heights[i - 1] && heights[i] > heights[i + 1]) ||
            (heights[i] < heights[i - 1] && heights[i] < heights[i + 1])) {
            variability_count++;
        }
    }
    if (variability_count > heights.size() / 2) { // Heuristic condition for variability
        cerr << "Warning: Performance bottleneck condition triggered - high height variability!" << endl;
        abort();
    }
}

// Check for the presence of significantly tall peaks
void check_high_peak_invariant(const vector<long long>& heights) {
    long long max_height = *max_element(heights.begin(), heights.end());
    long long average_height = accumulate(heights.begin(), heights.end(), 0LL) / heights.size();
  
    if (max_height > 2 * average_height) { // Heuristic for a significant peak
        cerr << "Warning: Performance bottleneck condition triggered - presence of high peaks!" << endl;
        abort();
    }
}

int main() {
    cin >> n;
    check_input_size_invariant(n); // Check input size

    vector<long long> heights(n);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &heights[i-1]);
    }
    
    check_height_variability_invariant(heights); // Check for height variability
    check_high_peak_invariant(heights); // Check for high peaks

    a[0] = a[n + 1] = 1;
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= n; i++) {
        dp[0][i] = min(dp[0][i - 1] + 1, heights[i - 1]);
    }
    
    for (int i = n; i >= 0; i--) {
        dp[1][i] = min(dp[1][i + 1] + 1, heights[i - 1]);
    }
    
    long long ans = -INF;
    for (int i = 1; i <= n; i++) ans = max(ans, min(dp[0][i], dp[1][i]));
    cout << ans << endl;
    return 0;
}