#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_path_complexity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Path complexity invariant triggered - excessive path exploration!" << endl;
        abort();
    }
}

void check_large_state_space_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Large state space invariant triggered - inefficient memory usage!" << endl;
        abort();
    }
}

void check_inefficient_path_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Inefficient path exploration invariant triggered - excessive recursion or revisits!" << endl;
        abort();
    }
}

vector<string> v;
long long int n, m;
pair<long long int, long long int> s, t;
bool vis[1009][1009][3][4];

// Helper functions
pair<long long int, long long int> find_pos(char ch) {
    for (long long int i = 0; i < n; i++) {
        for (long long int j = 0; j < m; j++) {
            if (v[i][j] == ch) {
                return {i, j};
            }
        }
    }
}

// Recursive DFS function
void dfs(long long int r, long long int c, long long int turns, long long int dir) {
    if (r >= n || r < 0 || c >= m || c < 0) return;
    if (turns > 2) return;
    if (vis[r][c][turns][dir] == 1) return;
    if (v[r][c] == '*') return;
    if (r == t.first && c == t.second) {
        cout << "YES\n";
        exit(0);
    }
    
    vis[r][c][turns][dir] = 1;

    // Check inefficient path invariant
    check_inefficient_path_invariant(turns > 2);

    if (dir == 0) {
        dfs(r - 1, c, turns, 0);
        dfs(r + 1, c, turns + 1, 2);
        dfs(r, c + 1, turns + 1, 1);
        dfs(r, c - 1, turns + 1, 3);
    } else if (dir == 1) {
        dfs(r - 1, c, turns + 1, 0);
        dfs(r + 1, c, turns + 1, 2);
        dfs(r, c + 1, turns, 1);
        dfs(r, c - 1, turns + 1, 3);
    } else if (dir == 2) {
        dfs(r - 1, c, turns + 1, 0);
        dfs(r + 1, c, turns, 2);
        dfs(r, c + 1, turns + 1, 1);
        dfs(r, c - 1, turns + 1, 3);
    } else if (dir == 3) {
        dfs(r - 1, c, turns + 1, 0);
        dfs(r + 1, c, turns + 1, 2);
        dfs(r, c + 1, turns + 1, 1);
        dfs(r, c - 1, turns, 3);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    v.resize(n);
    for (long long int i = 0; i < n; i++) cin >> v[i];

    s = find_pos('S');
    t = find_pos('T');

    // Check large state space invariant
    check_large_state_space_invariant(n * m > 1000000);

    for (long long int i = 0; i < 4; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(s.first, s.second, 0, i);
    }

    // Check path complexity invariant
    check_path_complexity_invariant(s.first == t.first && s.second == t.second);

    cout << "NO\n";
}