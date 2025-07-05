#include <bits/stdc++.h>
using namespace std;

// Checker function for large initial adjustment
void check_large_initial_adjustment(int y, int k) {
    if (y > 0.9 * k) {
        cerr << "Warning: Performance bottleneck triggered - large initial adjustment needed!" << endl;
        abort();
    }
}

// Checker function for limited potential values of x
void check_limited_potential_values(int y, int n) {
    if (y >= n) {
        cerr << "Warning: Performance bottleneck triggered - no possible values for x!" << endl;
        abort();
    }
}

int ans[100010];
int main() {
    int y, n, k;
    while (scanf("%d%d%d", &y, &k, &n) != EOF) {
        // Place checkers after input is read
        check_large_initial_adjustment(y, k);
        check_limited_potential_values(y, n);
        
        int cot = 0;
        int now = k - y;
        while (now < 1) now += k;  // This loop is suspected for performance degradation
        while (now + y <= n) {
            ans[cot++] = now;
            now += k;
        }
        if (cot == 0)
            cout << "-1" << endl;
        else {
            sort(ans, ans + cot);
            cout << ans[0];
            for (int i = 1; i < cot; i++) printf(" %d", ans[i]);
            cout << endl;
        }
    }
    return 0;
}