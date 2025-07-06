#include <bits/stdc++.h>
using namespace std;

map<pair<int, long long>, int> dp;
int n, s[1000010];

void check_high_stone_count(int stones) {
    if (stones > 50) {  // Threshold is subjective but considering near upper limit
        cerr << "Warning: High stone count invariant triggered - large number of stones in a pile" << endl;
        abort();
    }
}

void check_complex_move_invariant(int recursionDepth) {
    if (recursionDepth > 20) {  // Arbitrary threshold for recursion depth
        cerr << "Warning: Complex move invariant triggered - high recursion depth" << endl;
        abort();
    }
}

void check_high_recursion(int uniqueStates) {
    if (uniqueStates > 5000) {  // Arbitrary threshold for unique game states
        cerr << "Warning: High recursion and state variation invariant triggered - many unique states" << endl;
        abort();
    }
}

int calc(pair<int, long long> u) {
    if (dp.count(u) > 0) return dp[u];
    if (u.first == 0) return dp[u] = 0;
    
    vector<bool> g(61);
    for (int i = 1; i <= u.first; ++i) {
        if (u.second & (1ll << i)) continue;
        
        // Check recursion depth or state variation before recursive call
        check_complex_move_invariant(dp.size()); // Example: checking size of memoization map
        g[calc({u.first - i, u.second | (1ll << i)})] = true;
    }
    
    int x = 0;
    while (g[x]) ++x;
    return dp[u] = x;
}

int main() {
    scanf("%d", &n);
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
        
        // Check high stone count before calculation
        check_high_stone_count(s[i]);
        
        ans = ans ^ calc({s[i], 0});
    }
    
    // Check high recursion and state variation at the end if needed
    check_high_recursion(dp.size());
    
    printf("%s\n", ans != 0 ? "NO" : "YES");
    return 0;
}