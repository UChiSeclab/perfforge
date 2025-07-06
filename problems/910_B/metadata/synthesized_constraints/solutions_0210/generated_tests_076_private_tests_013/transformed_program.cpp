#include <bits/stdc++.h>
using namespace std;

int A[10];
int a, b, n, ans = 6;
vector<int> G[10];

// Check for high recursion depth and branching factor
void check_dfs_invariant(int depth, int branching_factor) {
    if (depth >= 6 && branching_factor >= 6) {
        cerr << "Warning: DFS invariant triggered - high recursion depth and branching factor!" << endl;
        abort();
    }
}

// Check if component sizes are too small relative to bar length
void check_component_size_invariant(int a, int b, int n) {
    if (a < n / 10 && b < n / 10) {
        cerr << "Warning: Component size invariant triggered - small component sizes relative to bar length!" << endl;
        abort();
    }
}

// Check for repeated operations in nested loops
void check_nested_loops_invariant(const vector<int> G[], int n) {
    for (int i = 1; i <= 6; i++) {
        if (G[i].size() > n / 2) {
            cerr << "Warning: Nested loops invariant triggered - repeated operations in nested loops!" << endl;
            abort();
        }
    }
}

void dfs(int pos) {
    check_dfs_invariant(pos, 6); // Check DFS invariant

    if (pos == 6) {
        int tmp = 0;
        for (int i = 1; i <= 6; i++) {
            int sum = 0;
            for (int j = 0; j < G[i].size(); j++) {
                sum += G[i][j];
            }
            if (sum > n) {
                tmp = 8;
                break;
            }
            if (G[i].size() != 0) tmp++;
        }
        ans = min(ans, tmp);
        return;
    }

    for (int i = 1; i <= 6; i++) {
        G[i].push_back(A[pos]);
        dfs(pos + 1);
        G[i].erase(G[i].end() - 1);
    }
}

int main() {
    cin >> n >> a >> b;

    check_component_size_invariant(a, b, n); // Check component size invariant

    for (int i = 0; i < 4; i++) A[i] = a;
    for (int i = 4; i < 6; i++) A[i] = b;

    dfs(0);

    check_nested_loops_invariant(G, n); // Check nested loops invariant

    cout << ans << endl;
    return 0;
}