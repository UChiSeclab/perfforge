#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int ans = 10000;

void check_small_side_lengths(int n, int a, int b) {
    if (a + b <= n / 3) {
        cerr << "Warning: Performance bottleneck condition triggered - small side lengths allow extensive recursion!" << endl;
        abort();
    }
}

void check_recursive_depth(int n, int a, int b) {
    if (n / a > 10 && n / b > 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursive depth and branching!" << endl;
        abort();
    }
}

void check_bitmask_complexity(int n, int a, int b) {
    if (a <= n / 4 && b <= n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered - bitmask completion complexity!" << endl;
        abort();
    }
}

void go(int msk, int carry, int tot) {
    if (tot > 6) return;
    if (msk == 63) {
        ans = min(ans, tot);
        return;
    }
    for (int i = 0; i < 6; i++) {
        if ((msk & (1 << i)) == 0) {
            if (i <= 3) {
                if (carry >= a) go(msk | (1 << i), carry - a, tot);
                go(msk | (1 << i), n - a, tot + 1);
            } else {
                if (carry >= b) go(msk | (1 << i), carry - b, tot);
                go(msk | (1 << i), n - b, tot + 1);
            }
        }
    }
}

int main() {
    int i, j;
    cin >> n >> a >> b;

    // Insert performance checkers before running the main logic
    check_small_side_lengths(n, a, b);
    check_recursive_depth(n, a, b);
    check_bitmask_complexity(n, a, b);

    go(0, 0, 0);
    cout << ans << endl;
}