#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
int n, a, b;

void check_recursive_depth_invariant(int a1, int b1) {
    if (a1 + b1 > 4) { // Total number of sides needed for two doors is 4
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive depth due to small `a` and `b` values." << endl;
        abort();
    }
}

void check_nested_loop_invariant(const vector<int>& rem) {
    int totalBars = 0;
    for (int i = 1; i <= 1000; ++i) {
        totalBars += rem[i];
    }
    if (totalBars > 500) { // Arbitrary threshold for large number of bar configurations
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop iterations due to many bar configurations." << endl;
        abort();
    }
}

int dfs(int a1, int b1, vector<int> &rem) {
    check_recursive_depth_invariant(a1, b1); // Check for excessive recursive depth

    if (a1 == 0 && b1 == 0) {
        return 0;
    }
    int cnt = inf;
    if (a1 != 0) {
        rem[n - a]++;
        cnt = min(cnt, 1 + dfs(a1 - 1, b1, rem));
        rem[n - a]--;
        for (int i = a; i <= 1000; i++) {
            if (rem[i] > 0) {
                rem[i]--;
                rem[i - a]++;
                cnt = min(cnt, dfs(a1 - 1, b1, rem));
                rem[i]++;
                rem[i - a]--;
            }
        }
    }
    if (b1 != 0) {
        rem[n - b]++;
        cnt = min(cnt, 1 + dfs(a1, b1 - 1, rem));
        rem[n - b]--;
        for (int i = b; i <= 1000; i++) {
            if (rem[i] > 0) {
                rem[i]--;
                rem[i - b]++;
                cnt = min(cnt, dfs(a1, b1 - 1, rem));
                rem[i]++;
                rem[i - b]--;
            }
        }
    }
    check_nested_loop_invariant(rem); // Check for excessive nested loop iterations
    return cnt;
}

int main() {
    scanf("%d %d %d", &n, &a, &b);
    vector<int> rem(1001);
    cout << dfs(4, 2, rem) << endl;
}