#include <bits/stdc++.h>
using namespace std;

// Function to check excessive recursion depth
void check_recursion_depth_invariant(int currentDepth, int maxDepth) {
    if (currentDepth > maxDepth) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth!" << endl;
        abort();
    }
}

// Function to check excessive state revisitation
void check_state_revisitation_invariant(int combinationsTested, int threshold) {
    if (combinationsTested > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive state revisitation!" << endl;
        abort();
    }
}

// Function to check high branching factor
void check_branching_factor_invariant(int branchingFactor, int threshold) {
    if (branchingFactor > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor!" << endl;
        abort();
    }
}

// Recursive function to calculate maximum rounds Alice can win
long long go(vector<long long> v, int currentDepth, int &combinationsTested) {
    combinationsTested++;
    
    // Check recursion depth and state revisitation
    check_recursion_depth_invariant(currentDepth, 100); // Assume max depth is 100 for safety
    check_state_revisitation_invariant(combinationsTested, 1000); // Arbitrary threshold for demonstration

    long long t1 = 0;
    t1 = v[1] + v[2] + v[3];
    if (t1 == 0) return t1;

    long long ans = 0;
    vector<long long> p;
    p = v;
    long long tt = min(p[1], p[4]);
    p[1] -= tt;
    p[4] -= tt;
    if (tt != 0) ans = max(ans, tt + go(p, currentDepth + 1, combinationsTested));
    
    // Check branching factor before each recursive call
    check_branching_factor_invariant(9, 10); // 9 branches checked, threshold can be adjusted
    
    p = v;
    tt = min(p[1], p[5]);
    p[1] -= tt;
    p[5] -= tt;
    if (tt != 0) ans = max(ans, go(p, currentDepth + 1, combinationsTested));
    
    p = v;
    tt = min(p[1], p[6]);
    p[1] -= tt;
    p[6] -= tt;
    if (tt != 0) ans = max(ans, tt + go(p, currentDepth + 1, combinationsTested));
    
    p = v;
    tt = min(p[2], p[4]);
    p[2] -= tt;
    p[4] -= tt;
    if (tt != 0) ans = max(ans, tt + go(p, currentDepth + 1, combinationsTested));
    
    p = v;
    tt = min(p[2], p[5]);
    p[2] -= tt;
    p[5] -= tt;
    if (tt != 0) ans = max(ans, tt + go(p, currentDepth + 1, combinationsTested));
    
    p = v;
    tt = min(p[2], p[6]);
    p[2] -= tt;
    p[6] -= tt;
    if (tt != 0) ans = max(ans, go(p, currentDepth + 1, combinationsTested));
    
    p = v;
    tt = min(p[3], p[4]);
    p[3] -= tt;
    p[4] -= tt;
    if (tt != 0) ans = max(ans, go(p, currentDepth + 1, combinationsTested));
    
    p = v;
    tt = min(p[3], p[5]);
    p[3] -= tt;
    p[5] -= tt;
    if (tt != 0) ans = max(ans, tt + go(p, currentDepth + 1, combinationsTested));
    
    p = v;
    tt = min(p[3], p[6]);
    p[3] -= tt;
    p[6] -= tt;
    if (tt != 0) ans = max(ans, tt + go(p, currentDepth + 1, combinationsTested));
    
    return ans;
}

void query() {
    long long n;
    cin >> n;
    long long r, c, p;
    long long R, C, P;
    vector<long long> a(7);
    for (long long i = 1; i <= 6; i++) cin >> a[i];
    r = a[4];
    c = a[5];
    p = a[6];
    R = a[1];
    P = a[3];
    C = a[2];
    long long ans = 0;
    long long tt = min(R, c);
    R -= tt;
    c -= tt;
    ans += tt;
    tt = min(C, p);
    C -= tt;
    p -= tt;
    ans += tt;
    tt = min(P, r);
    P -= tt;
    r -= tt;
    ans += tt;

    int combinationsTested = 0; // Initialize combinations tested counter
    cout << a[1] + a[2] + a[3] - go(a, 0, combinationsTested) << " " << ans << "\n"; // Start recursive call with depth 0
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t = 1;
    while (t--) {
        query();
    }
}