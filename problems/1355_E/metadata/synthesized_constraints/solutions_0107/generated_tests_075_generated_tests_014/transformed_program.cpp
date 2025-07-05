#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
int va[N], x, y, z, n;

// Invariant 1: Large disparity among initial pillar heights
void check_height_disparity_invariant(const vector<int>& heights) {
    int minHeight = *min_element(heights.begin(), heights.end());
    int maxHeight = *max_element(heights.begin(), heights.end());
    if (maxHeight - minHeight > 1000000) { // Arbitrary threshold indicating large disparity
        cerr << "Warning: Performance bottleneck condition triggered - large height disparity!" << endl;
        abort();
    }
}

// Invariant 2: Frequent costly operations due to intermediate heights
void check_costly_operations_invariant(long long a, long long b) {
    if (abs(a - b) > 1000000) { // Arbitrary threshold indicating high cost disparity
        cerr << "Warning: Performance bottleneck condition triggered - frequent costly operations!" << endl;
        abort();
    }
}

// Invariant 3: Inefficient search range narrowing
void check_search_range_invariant(int initialRange) {
    if (initialRange > 1000000000) { // Arbitrary large range threshold
        cerr << "Warning: Performance bottleneck condition triggered - inefficient search range!" << endl;
        abort();
    }
}

long long getans(long long h) {
    long long ans = 0, a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (va[i] > h)
            a += va[i] - h;
        else
            b += h - va[i];
    }
    // Checking invariant 2: Costly operation conditions
    check_costly_operations_invariant(a, b);

    ans += 1ll * z * min(a, b);
    if (a > b)
        ans += 1ll * y * (a - b);
    else
        ans += 1ll * x * (b - a);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> x >> y >> z;
    z = min(z, x + y);

    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> va[i];
    
    // Convert input heights into a vector for easier processing
    for (int i = 0; i < n; ++i) heights[i] = va[i];

    // Check for large height disparity (Invariant 1)
    check_height_disparity_invariant(heights);

    int l = 0, r = 1e9 + 7;
    
    // Check initial range for inefficiency (Invariant 3)
    check_search_range_invariant(r - l);

    while (r - l > 5) {
        int midl = l + (r - l + 1) / 3 - 1, midr = r - (r - l + 1) / 3 + 1;
        if (getans(midl) < getans(midr))
            r = midr;
        else
            l = midl;
    }

    long long ans = inf;
    for (int i = l; i <= r; i++) ans = min(getans(i), ans);
    cout << ans << endl;
}