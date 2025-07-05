#include <bits/stdc++.h>
using namespace std;

int n, k, l;
const int MAX1 = 100;
const int MAX2 = 2000;
int dp[MAX1 + 1][MAX2 + 1];

// Checker functions
void check_recursion_depth(int currentDepth, int maxDepth, int threshold) {
    if (currentDepth > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth!" << endl;
        abort();
    }
}

void check_memoization_effectiveness(int memoizationHits, int recursionCalls, double threshold) {
    if (recursionCalls > 0 && (double)memoizationHits / recursionCalls < threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - ineffective memoization!" << endl;
        abort();
    }
}

void check_tide_modulation(int k, int modCycle) {
    if (modCycle > k * 2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive tide modulation complexity!" << endl;
        abort();
    }
}

void check_depth_variability(const vector<int>& depths, int l, int variabilityThreshold) {
    int variabilityCount = 0;
    for (int depth : depths) {
        if (depth > l - variabilityThreshold) {
            variabilityCount++;
        }
    }
    if (variabilityCount > variabilityThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high depth variability!" << endl;
        abort();
    }
}

int solve(int d[], int p[], int pos, int t, int& recursionDepth) {
    if (pos == n) return 1;

    int curr = d[pos] + p[t % (2 * k)];
    if (curr > l) return 0;

    if (dp[pos][t] != -1) return dp[pos][t];

    int good = 0;
    recursionDepth++;
    check_recursion_depth(recursionDepth, n, 50); // Check excessive recursion depth

    for (int i = 0; i < 2 * k; i++) {
        curr = d[pos] + p[(t + i) % (2 * k)];
        if (curr > l) break;
        good = max(good, solve(d, p, pos + 1, t + i + 1, recursionDepth));
    }

    recursionDepth--;
    return dp[pos][t] = good;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> l;
        int d[n];
        vector<int> depths(n);
        int p[2 * k];

        for (int i = 0; i < n; i++) {
            cin >> d[i];
            depths[i] = d[i];
        }

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i <= k; i++) p[i] = i;
        for (int i = k + 1; i < 2 * k; i++) p[i] = p[i - 1] - 1;

        int good = 0;
        int recursionDepth = 0;
        int memoizationHits = 0;
        int recursionCalls = 0;

        check_depth_variability(depths, l, 10); // Check high depth variability

        for (int i = 0; i < 2 * k; i++) {
            check_tide_modulation(k, i); // Check tide modulation complexity
            recursionCalls++;
            good = max(good, solve(d, p, 0, i + 1, recursionDepth));
            if (dp[0][i + 1] != -1) memoizationHits++;
        }

        check_memoization_effectiveness(memoizationHits, recursionCalls, 0.5); // Check ineffective memoization

        if (good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}