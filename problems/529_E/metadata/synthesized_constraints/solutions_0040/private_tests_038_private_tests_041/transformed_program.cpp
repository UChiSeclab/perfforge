#include <bits/stdc++.h>
using namespace std;

const long long inf = 1000000000ll;
const long long inf64 = inf * inf;

void check_high_denomination_invariant(const vector<int>& a, int x) {
    if (a.size() == 1 && a[0] > x) {
        cerr << "Warning: High denomination invariant triggered - denomination too large for target sum" << endl;
        abort();
    }
}

void check_inefficient_combination_invariant(const vector<int>& a, int k) {
    if (a.size() == 1 && k > 15) {
        cerr << "Warning: Inefficient combination invariant triggered - high k with single large denomination" << endl;
        abort();
    }
}

void check_recursive_subtraction_invariant(int n, const vector<int>& a, int x) {
    if (n <= 2 && a.back() > x / 2) {
        cerr << "Warning: Recursive subtraction invariant triggered - limited denominations with large values" << endl;
        abort();
    }
}

bool solve() {
    int n, k, q, sz = -1, x;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), sz = max(sz, a[i] + 1);
    
    // Runtime checks
    check_inefficient_combination_invariant(a, k);
    
    vector<int> is(sz);
    for (int i = 0; i < n; i++) is[a[i]] = 1;
    scanf("%d", &q);
    
    while (q--) {
        scanf("%d", &x);
        
        // Runtime checks
        check_high_denomination_invariant(a, x);
        check_recursive_subtraction_invariant(n, a, x);
        
        int ans = inf;
        for (int k1 = 1; k1 <= k; k1++) {
            for (int i = 0; i < n; i++) {
                long long sum = a[i] * k1;
                if (sum > x) continue;
                if (sum == x)
                    ans = min(ans, k1);
                else {
                    sum = x - sum;
                    for (int k2 = 1; k1 + k2 <= k; k2++) {
                        if (sum % k2) continue;
                        sum /= k2;
                        if (sum >= 0 && sum < (int)is.size() && is[sum])
                            ans = min(ans, k1 + k2);
                        sum *= k2;
                    }
                }
            }
        }
        if (ans != inf)
            printf("%d\n", ans);
        else
            puts("-1");
    }
    return true;
}

int main() {
    solve();
    return 0;
}