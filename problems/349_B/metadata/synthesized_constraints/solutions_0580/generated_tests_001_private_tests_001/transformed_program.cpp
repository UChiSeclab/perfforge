#include <bits/stdc++.h>
using namespace std;

int v, a[11], f[1000005];

// Check for recursion depth and branching factor
void check_recursion_invariant(int currentDepth, int branchFactor) {
    if (currentDepth > 100 && branchFactor > 5) {
        cerr << "Warning: Performance bottleneck condition triggered - High recursion depth or branching factor!" << endl;
        abort();
    }
}

// Check for inefficient memoization
void check_memoization_invariant(int possibleCalls, int cacheHits) {
    if (possibleCalls > 1000000 && cacheHits / possibleCalls > 0.9) {
        cerr << "Warning: Performance bottleneck condition triggered - Inefficient memoization detected!" << endl;
        abort();
    }
}

// Check for closely spaced paint costs
void check_cost_distribution_invariant(vector<int>& a) {
    int minCost = *min_element(a.begin() + 1, a.end());
    int maxCost = *max_element(a.begin() + 1, a.end());
    if (maxCost - minCost < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - Closely spaced paint costs detected!" << endl;
        abort();
    }
}

int rec(int r) {
    static int callCount = 0;
    callCount++;
    int& res = f[r];
    if (res != -1) {
        return res;
    }
    res = 0;
    int branchFactor = 0;
    for (int d = 1; d <= 9; ++d) {
        if (a[d] <= r) {
            branchFactor++;
            res = max(res, 1 + rec(r - a[d]));
        }
    }
    // Check for recursion depth and branching factor
    check_recursion_invariant(callCount, branchFactor);
    return res;
}

void printAns(int r) {
    int best = 0, d = 0;
    for (int i = 1; i <= 9; ++i) {
        if (a[i] <= r && best <= f[r - a[i]]) {
            best = f[r - a[i]];
            d = i;
        }
    }
    if (!d) return;
    cout << d;
    printAns(r - a[d]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> v;
    for (int i = 1; i <= 9; ++i) {
        cin >> a[i];
    }
    
    // Check for closely spaced paint costs
    vector<int> costArray(a + 1, a + 10);
    check_cost_distribution_invariant(costArray);

    memset(f, -1, sizeof f);
    int result = rec(v);
    
    // Check for inefficient memoization
    int cacheHits = count_if(f, f + v + 1, [](int i) { return i != -1; });
    check_memoization_invariant(v, cacheHits);

    if (result == 0) {
        cout << -1;
        return 0;
    }
    printAns(v);
    return 0;
}