#include <bits/stdc++.h>
using namespace std;

void check_bfs_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large search space explored!" << endl;
        abort();
    }
}

int bfs(int n) {
    queue<int> q;
    q.push(0);

    // Check for potential large search space before starting BFS
    check_bfs_invariant(n > 50); // Threshold based on problem constraints and observations

    while (!q.empty()) {
        int u = q.front();
        int v3, v7;
        v3 = u + 3;
        v7 = u + 7;
        if (v3 == n || v7 == n) return 1;
        if (v3 < n) q.push(v3);
        if (v7 < n) q.push(v7);
        q.pop();
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int x;
        cin >> x;
        int r;
        r = bfs(x);
        if (r == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}