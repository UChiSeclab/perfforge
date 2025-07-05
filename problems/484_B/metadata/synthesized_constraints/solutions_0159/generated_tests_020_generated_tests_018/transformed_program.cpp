#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
vector<int> a;

void check_small_value_invariant(vector<int>& a, int maxValue) {
    if (!a.empty() && a[0] * 2 < maxValue) {
        cerr << "Warning: Small value invariant triggered - excessive iterations possible!" << endl;
        abort();
    }
}

void check_iteration_count_invariant(int element, int maxValue) {
    if (element < maxValue / 2) {
        cerr << "Warning: High iteration count invariant triggered - may lead to slowdown!" << endl;
        abort();
    }
}

void check_distribution_invariant(vector<int>& a) {
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] - a[i-1] > 1000) {  // Arbitrary gap threshold for large distribution
            cerr << "Warning: Distribution invariant triggered - suboptimal element distribution!" << endl;
            abort();
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    set<int> s(a.begin(), a.end());
    a.assign(s.begin(), s.end());
    sort(a.begin(), a.end());

    // Check invariants after sorting
    check_small_value_invariant(a, 2 * MAXN);
    check_distribution_invariant(a);

    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        // Check invariant for each element before entering the inner loop
        check_iteration_count_invariant(a[i], 2 * MAXN);
        
        for (int j = 2; a[i] * j <= 2 * MAXN; j++) {
            int d = lower_bound(a.begin(), a.end(), j * a[i]) - a.begin();
            if (d >= i + 1 && d - 1 < a.size()) ans = max(ans, a[d - 1] % a[i]);
        }
    }
    printf("%d\n", ans);
}