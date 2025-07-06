#include <bits/stdc++.h>
using namespace std;

// Check for excessive loop iterations based on n/k ratio
void check_iteration_invariant(int n, int k) {
    if (n / k > 100000) {  // Arbitrary threshold based on constraints and analysis
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations due to high n/k ratio!" << endl;
        abort();
    }
}

// Check for intense loop operations due to high n/k ratio and low y
void check_loop_intensity_invariant(int n, int k, int y) {
    if (n / k > 100000 && y < k) {
        cerr << "Warning: Performance bottleneck condition triggered - high loop intensity due to n/k ratio and low y!" << endl;
        abort();
    }
}

int main() {
    int y, k, n;
    cin >> y >> k >> n;

    // Insert checks after reading inputs
    check_iteration_invariant(n, k);
    check_loop_intensity_invariant(n, k, y);

    vector<int> ans;
    for (int i = 0; i <= n / k; i++) {  // Loop susceptible to performance issues
        int num = i * k;
        if (num <= y) continue;
        ans.push_back(num - y);
    }
    if ((int)ans.size() == 0)
        cout << -1 << endl;
    else {
        for (int x : ans) cout << x << ' ';
        cout << endl;
    }
    return 0;
}