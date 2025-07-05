#include <bits/stdc++.h>
using namespace std;

map<pair<long long, int>, int> memo;
int n, s, Xor;

// Invariant checkers
void check_large_pile_invariant(int stoneCount) {
    if (stoneCount > 50) {
        cerr << "Warning: Large pile detected, leading to deep recursion and large search space!" << endl;
        abort();
    }
}

void check_repeated_subproblem_invariant(int totalStones) {
    if (totalStones > 500) {
        cerr << "Warning: High total stone count leading to repeated subproblem solving!" << endl;
        abort();
    }
}

void check_high_variability_invariant(int maxStone, int minStone) {
    if (maxStone - minStone > 40) {
        cerr << "Warning: High variability in stone counts detected!" << endl;
        abort();
    }
}

void check_high_branching_factor_invariant(int stoneCount) {
    if (stoneCount > 40) {
        cerr << "Warning: High branching factor detected, leading to computational explosion!" << endl;
        abort();
    }
}

int solve(int x, long long mask) {
    if (memo.count({mask, x})) return memo[{mask, x}];
    if (x == 0) {
        memo[{mask, x}] = 0;
        return 0;
    }
    int grundy = 0;
    map<int, int> ump;
    for (int i = 1; i <= x; i++) {
        if (mask & (1ll << i)) continue;
        ump[solve(x - i, mask | (1ll << i))] = 1;
        while (ump.count(grundy)) grundy++;
    }
    ump.clear();
    memo[{mask, x}] = grundy;
    return grundy;
}

int main() {
    scanf("%d", &n);
    int totalStones = 0;
    int maxStone = 0;
    int minStone = INT_MAX;

    vector<int> piles(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s);
        piles[i] = s;
        totalStones += s;
        maxStone = max(maxStone, s);
        minStone = min(minStone, s);

        // Check large pile invariant
        check_large_pile_invariant(s);
        // Check high branching factor invariant
        check_high_branching_factor_invariant(s);
    }

    // Check repeated subproblem invariant
    check_repeated_subproblem_invariant(totalStones);
    // Check high variability invariant
    check_high_variability_invariant(maxStone, minStone);

    for (int pile : piles) {
        Xor ^= solve(pile, 0);
    }

    printf((Xor) ? "NO" : "YES");
    return 0;
}