#include <bits/stdc++.h>
using namespace std;

// Declare the checker functions
void check_complex_pattern_invariant(const vector<int>& heights, int n);
void check_small_tower_density_invariant(const vector<int>& heights, int n);
void check_gradual_height_change_invariant(const vector<int>& heights, int n);
void check_min_max_operations_invariant(const vector<int>& heights, int n);

int dp[100009], l, r, n, p, pr, q, k;

int main() {
    cin >> n;
    r = n;
    vector<int> heights(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
    }
    
    // Insert our performance checks here
    check_complex_pattern_invariant(heights, n);
    check_small_tower_density_invariant(heights, n);
    check_gradual_height_change_invariant(heights, n);
    check_min_max_operations_invariant(heights, n);
    
    // Original computation logic
    for (int i = 1; i <= n; i++)
        dp[i] = min(n - i + 1, min(i, min(heights[i], min(heights[i - 1] + 1, heights[i + 1] + 1))));
    
    for (int i = n; i >= 1; i--)
        dp[i] = min(n - i + 1, min(i, min(dp[i], min(heights[i - 1] + 1, heights[i + 1] + 1))));
    
    for (int i = 1; i <= n; i++) 
        k = max(k, dp[i]);
    
    cout << k;
}