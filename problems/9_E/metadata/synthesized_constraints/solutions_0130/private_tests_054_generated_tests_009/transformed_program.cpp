#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;

const int N = int(5e1) + 9;

int n, m;
bool mat[N][N];
int cnt[N];
int col[N];
int dfs_call_count = 0;

void dfs(int v, int c) {
    col[v] = c;
    for (int i = 0; i < (int)(n); ++i)
        if (mat[v][i] && col[i] == -1) dfs(i, c);
    ++dfs_call_count;
}

// Checker functions
void check_graph_sparsity(int n, int m, const int cnt[]) {
    int disconnectedCount = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] < 2) {
            ++disconnectedCount;
        }
    }
    if (disconnectedCount > n / 2) {
        cerr << "Warning: Performance bottleneck triggered - graph is too sparse with many disconnected components!" << endl;
        abort();
    }
}

void check_initial_edges(int n, int m) {
    if (n > 40 && m < n / 4) {
        cerr << "Warning: Performance bottleneck triggered - high number of nodes with minimal initial edges!" << endl;
        abort();
    }
}

void check_dfs_calls(int callCount) {
    if (callCount > 5000) {
        cerr << "Warning: Performance bottleneck triggered - excessive DFS recursive calls!" << endl;
        abort();
    }
}

void solve() {
    cin >> n >> m;
    
    check_initial_edges(n, m); // Check for minimal initial edges with high node count

    if (n == 1) {
        if (m == 1) {
            cout << "YES\n0";
        } else if (m == 0) {
            cout << "YES\n1\n1 1";
        } else
            cout << "NO";
        return;
    }
    for (int i = 0; i < (int)(m); ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        mat[x][y] = mat[y][x] = true;
        ++cnt[x], ++cnt[y];
    }
    
    // Check for sparsity before the heavy loop
    check_graph_sparsity(n, m, cnt);

    if (m > n) {
        cout << "NO";
        return;
    }
    
    vector<pair<int, int>> res;
    while (m < n) {
        ++m;
        memset(col, -1, sizeof col);
        for (int i = 0; i < (int)(n); ++i)
            if (col[i] == -1) dfs(i, i);
         
        check_dfs_calls(dfs_call_count); // Check for excessive DFS calls

        bool fnd = false;
        for (int i = 0; i < (int)(n); ++i)
            for (int j = i + 1; j < n; ++j)
                if (cnt[i] < 2 && cnt[j] < 2 && (col[i] != col[j] || m == n)) {
                    mat[i][j] = mat[j][i] = true;
                    res.push_back(make_pair(i + 1, j + 1));
                    ++cnt[i], ++cnt[j];
                    j = i = n + 1;
                    fnd = true;
                }
        if (!fnd) {
            cout << "NO";
            return;
        }
    }
    memset(col, -1, sizeof col);
    dfs(0, 0);
    for (int i = 0; i < (int)(n); ++i)
        if (col[i] == -1 || cnt[i] != 2) {
            cout << "NO";
            return;
        }
    cout << "YES\n";
    cout << (int)(res.size()) << endl;
    for (int i = 0; i < (int)((int)(res.size())); ++i)
        cout << res[i].first << ' ' << res[i].second << endl;
}

int main() {
    srand(time(NULL));
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;
    solve();
    return 0;
}