#include <bits/stdc++.h>
using namespace std;

int n, w;
vector<long long> v;

// Checker functions
void check_recursive_exploration(int w, int depth) {
    if (w <= 3 && depth > 50) { // Arbitrary depth threshold for illustration
        cerr << "Warning: Performance bottleneck triggered - excessive recursive exploration!" << endl;
        abort();
    }
}

void check_combinatorial_explosion(int w, int numCombinations) {
    if (w <= 3 && numCombinations > 1000000) { // Threshold based on potential large combination space
        cerr << "Warning: Performance bottleneck triggered - large combinatorial explosion!" << endl;
        abort();
    }
}

void solve(int i, long long a, long long b, int depth) {
    check_recursive_exploration(w, depth);

    if (a == b || w <= 3) {
        puts("YES");
        exit(0);
    }
    if (i == (int)v.size()) return;
    solve(i + 1, a + v[i], b, depth + 1);
    solve(i + 1, a, b + v[i], depth + 1);
    solve(i + 1, a, b, depth + 1);
}

int main() {
    scanf("%d%d", &w, &n);
    long long val = 1;

    for (int i = 0; i <= 16 && val <= 1e10; ++i) {
        v.push_back(val);
        val *= w;
    }

    // Check for combinatorial explosion based on the number of combinations to explore
    int numCombinations = pow(3, v.size());  // Estimate number of combinations
    check_combinatorial_explosion(w, numCombinations);

    solve(0, 0, n, 0);
    puts("NO");
    return 0;
}