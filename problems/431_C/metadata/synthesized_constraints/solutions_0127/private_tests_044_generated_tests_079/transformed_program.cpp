#include <bits/stdc++.h>
using namespace std;

int dp[2][101][101], n, d, k;
bool seen[2][101][101];

// Function to check deep and frequent recursion
void check_recursion_invariant(int recursionDepth) {
    if (n >= 90 && k >= 90 && recursionDepth > 1000000) {
        cerr << "Warning: Recursion invariant triggered - deep and frequent recursion!" << endl;
        abort();
    }
}

// Function to check inefficient cache utilization
void check_cache_invariant(int cacheHitCount, int recursionCallCount) {
    if (recursionCallCount > 1000000 && cacheHitCount < recursionCallCount / 100) {
        cerr << "Warning: Cache invariant triggered - inefficient cache utilization!" << endl;
        abort();
    }
}

// Function to check high loop iteration counts
void check_loop_invariant(int loopIterations) {
    if (k >= 90 && loopIterations > 1000000) {
        cerr << "Warning: Loop invariant triggered - high loop iteration count!" << endl;
        abort();
    }
}

int sol(int index, int w, bool in, int recursionDepth, int& cacheHitCount, int& recursionCallCount) {
    recursionCallCount++;
    check_recursion_invariant(recursionDepth);
    
    if (w == n) {
        if (in) return 1;
        else return 0;
    }
    if (index == n || w > n) return 0;
    
    if (seen[in][index][w]) {
        cacheHitCount++;
        return dp[in][index][w];
    }
    
    int ans = 0;
    int loopIterations = 0;
    for (int i = 1; i <= k; i++) {
        loopIterations++;
        ans = (ans + (sol(index + 1, w + i, (in || i >= d), recursionDepth + 1, cacheHitCount, recursionCallCount) % 1000000007)) % 1000000007;
    }
    
    check_loop_invariant(loopIterations);
    
    seen[in][index][w] = true;
    return dp[in][index][w] = ans;
}

int main() {
    scanf("%d %d %d", &n, &k, &d);
    
    int cacheHitCount = 0;
    int recursionCallCount = 0;
    
    printf("%d\n", sol(0, 0, 0, 0, cacheHitCount, recursionCallCount));
    
    check_cache_invariant(cacheHitCount, recursionCallCount);
}