#include <bits/stdc++.h>
using namespace std;

int g[51][51];
bool vis[51];
int deg[51];
int n, m;
bool has_cir;

// Checker functions for performance bottlenecks
void check_dfs_recursion_depth(int depth, int threshold) {
    if (depth > threshold) {
        cerr << "Warning: Performance bottleneck due to high DFS recursion depth!" << endl;
        abort();
    }
}

void check_repeated_checks(int checkCount, int threshold) {
    if (checkCount > threshold) {
        cerr << "Warning: Performance bottleneck due to repeated execution of the check function!" << endl;
        abort();
    }
}

void check_nested_loop_iterations(int vertexCount, int edgeCount) {
    if (vertexCount * vertexCount > 2500) {
        cerr << "Warning: Performance bottleneck due to large number of nested loop iterations!" << endl;
        abort();
    }
}

void dfs(int u, int f, int depth) {
    vis[u] = true;
    
    // Check for high recursion depth
    check_dfs_recursion_depth(depth, 50); // Example threshold

    for (int i = 1; i <= n; i++) {
        if (g[u][i] && i != f || g[u][i] >= 2) {
            if (vis[i])
                has_cir = true;
            else
                dfs(i, u, depth + 1);
        }
    }
}

bool check() {
    // Track number of times 'check' is called
    static int checkCount = 0;
    checkCount++;

    // Check for excessive repeated calls
    check_repeated_checks(checkCount, 1000); // Example threshold

    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) return false;
    }
    int comp = 0;
    memset(vis, false, sizeof(vis));
    has_cir = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            comp++;
            dfs(i, -1, 1); // Initial recursion depth
        }
    }
    if (comp > 1 && has_cir) return false;
    return true;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {

        // Check for large number of iterations before heavy nested loops
        check_nested_loop_iterations(n, m);

        if (n == 2 && m == 0) {
            printf("YES\n2\n");
            printf("1 2\n1 2\n");
            continue;
        }
        memset(g, 0, sizeof(g));
        memset(deg, 0, sizeof(deg));
        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            g[a][b]++;
            g[b][a]++;
            deg[a]++;
            deg[b]++;
        }
        if (!check()) {
            printf("NO\n");
        } else {
            vector<int> a, b;
            printf("YES\n");
            printf("%d\n", n - m);
            for (int i = 1; i <= n; i++) {
                for (int j = i; j <= n; j++) {
                    g[i][j]++;
                    g[j][i]++;
                    deg[i]++;
                    deg[j]++;
                    if (check()) {
                        a.push_back(i);
                        b.push_back(j);
                    } else {
                        deg[i]--;
                        deg[j]--;
                        g[i][j]--;
                        g[j][i]--;
                    }
                }
            }
            for (int i = 0; i < a.size(); i++) printf("%d %d\n", a[i], b[i]);
        }
    }
    return 0;
}