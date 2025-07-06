#include <bits/stdc++.h>
using namespace std;

// Check for deep recursion
void check_recursion_depth_invariant(int n) {
    if (n > 18) {  // A threshold close to the maximum constraint
        cerr << "Warning: Performance bottleneck condition triggered due to deep recursion!" << endl;
        abort();
    }
}

// Check for lack of memoization
void check_memoization_invariant(std::unordered_map<int, int>& memo, int an) {
    if (memo.find(an) != memo.end()) {
        cerr << "Warning: Performance bottleneck condition triggered due to lack of memoization!" << endl;
        abort();
    }
}

int a0, a1, n;
unordered_map<int, int> memo; // Memoization map

int getans(int an) {
    check_memoization_invariant(memo, an); // Check for lack of memoization

    if (an == 0) return a0;
    if (an == 1) return a1;

    if (memo.find(an) != memo.end()) return memo[an]; // Use memoized result if available

    int result = getans(an - 1) + getans(an - 2);
    memo[an] = result; // Store the result in the memo map
    return result;
}

int main() {
    scanf("%d%d%d", &a0, &a1, &n);

    check_recursion_depth_invariant(n); // Check for deep recursion right after reading input

    printf("%d\n", getans(n));
    return 0;
}