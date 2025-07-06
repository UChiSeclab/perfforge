#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int dp[N][2];
int arr[10];

// Checkers for performance bottlenecks

// Checks if the recursion may lead to a high branching factor
void check_recursion_invariant(int* costs, int size) {
    int minCost = *std::min_element(costs, costs + size);
    int closeCosts = 0;
    for (int i = 0; i < size; ++i) {
        if (costs[i] <= minCost + 10) { // Arbitrary threshold for close costs
            closeCosts++;
        }
    }
    if (closeCosts > 3) { // More than 3 digits with close paint costs
        cerr << "Warning: Performance bottleneck condition triggered - "
                "high branching factor due to similar digit costs!" << endl;
        abort();
    }
}

// Checks if the reconstruction might lead to performance issues
void check_reconstruction_invariant(int maxLength) {
    if (maxLength > 50) { // Arbitrary threshold for a long number
        cerr << "Warning: Performance bottleneck condition triggered - "
                "reconstruction of a very long number!" << endl;
        abort();
    }
}

void build(int l) {
    if (dp[l][1] == -1) {
        cout << -1 << endl;
        return;
    }
    int maxLength = 0;
    while (dp[l][1] != -1) {
        cout << dp[l][1] + 1;
        l -= arr[dp[l][1]];
        maxLength++;
    }
    check_reconstruction_invariant(maxLength); // Check during reconstruction
}

int rec(int l) {
    if (dp[l][0] != -1) return dp[l][0];
    for (int i = 8; i >= 0; i--) {
        if (l >= arr[i]) {
            int k = rec(l - arr[i]) + 1;
            if (k > dp[l][0]) dp[l][0] = k, dp[l][1] = i;
        }
    }
    if (dp[l][0] == -1) return 0;
    return dp[l][0];
}

int main() {
    int l;
    cin >> l;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 9; i++) cin >> arr[i];
    
    check_recursion_invariant(arr, 9); // Check after reading costs
    
    rec(l), build(l);
}