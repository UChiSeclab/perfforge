#include <bits/stdc++.h>
using namespace std;

// Performance checker functions
void check_recursion_depth_invariant(int currentDepth, int maxDepth) {
    if (currentDepth > maxDepth) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth!" << endl;
        abort();
    }
}

void check_memoization_effectiveness_invariant(size_t uniqueStates, size_t thresholdStates) {
    if (uniqueStates > thresholdStates) {
        cerr << "Warning: Performance bottleneck condition triggered - ineffective memoization!" << endl;
        abort();
    }
}

void check_frequent_level_transition_invariant(int transitionCount, int threshold) {
    if (transitionCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent level transitions!" << endl;
        abort();
    }
}

long long n, r1, r2, r3, travelTime;
vector<long long> monsters;
vector<vector<long long>> dp;
int recursionDepth = 0;
unordered_set<string> uniqueStateHashes; // For checking unique states in memoization
int levelTransitions = 0; // For counting level transitions

long long go(int pos, int prevBoss) {
    recursionDepth++;
    check_recursion_depth_invariant(recursionDepth, 1000); // Example max depth for this problem

    if (pos == n) {
        recursionDepth--;
        return -travelTime;
    }
    if (dp[pos][prevBoss] != -1) {
        recursionDepth--;
        return dp[pos][prevBoss];
    }
    long long ans = 1e18;
    if (prevBoss) {
        ans = min(ans, r1 * monsters[pos] + r3 + travelTime + r1 + 2L * travelTime +
                       go(pos + 1, 0));
        if (pos == n - 1) ans = min(ans, r1 * monsters[pos] + r3 + travelTime + r1);
        ans = min(ans, r1 * monsters[pos] + r1 + travelTime + r1 + travelTime + r1 +
                       travelTime + go(pos + 1, 0));
        ans = min(ans, r2 + travelTime + r1 + travelTime + r1 + travelTime +
                       go(pos + 1, 0));
    } else {
        ans = min(ans, r1 * monsters[pos] + r3 + travelTime + go(pos + 1, 0));
        if (pos == n - 1)
            ans = min(ans, min(r1 * monsters[pos] + r1, r2) + 2L * travelTime + r1);
        if (pos != n - 1)
            ans = min(ans, r1 * monsters[pos] + r1 + travelTime + go(pos + 1, 1));
        if (pos != n - 1) ans = min(ans, r2 + travelTime + go(pos + 1, 1));
    }
    // Check for unique state count in memoization
    uniqueStateHashes.insert(to_string(pos) + "_" + to_string(prevBoss));
    check_memoization_effectiveness_invariant(uniqueStateHashes.size(), 5000); // Example threshold for unique states

    recursionDepth--;
    return dp[pos][prevBoss] = ans;
}

int main() {
    scanf("%lld %lld %lld %lld %lld", &n, &r1, &r2, &r3, &travelTime);
    monsters.resize(n);
    for (int i = 0; i < n; i++) scanf("%lld", &monsters[i]);
    dp.resize(n + 1, vector<long long>(2, -1));
    long long ans = go(0, 0);
    
    // Check for frequent level transitions
    check_frequent_level_transition_invariant(levelTransitions, 1000); // Example threshold for level transitions

    printf("%lld\n", ans);
    return 0;
}