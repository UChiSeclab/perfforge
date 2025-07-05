#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int deg[N], f[N], n, m;
int unionFindCalls = 0;  // Track union-find calls
int checksPerformed = 0; // Track pairwise checks performed

int find(int x) {
    unionFindCalls++;  // Increment on each find call for bottleneck detection
    if (x != f[x]) return f[x] = find(f[x]);
    return x;
}

// Function to check union-find operations
void check_union_find_invariant(int unionFindCalls, int threshold) {
    if (unionFindCalls > threshold) {
        cerr << "Warning: Performance bottleneck detected due to excessive union-find operations!" << endl;
        abort();
    }
}

// Function to check combinatorial pairwise checks
void check_combinatorial_checks_invariant(int n, int checksPerformed, int threshold) {
    if (checksPerformed > threshold) {
        cerr << "Warning: Performance bottleneck detected due to excessive pairwise checks!" << endl;
        abort();
    }
}

// Function to check graph sparsity and edge additions
void check_graph_sparsity_invariant(int addedEdges, int n, int m, int threshold) {
    if ((addedEdges + m) > threshold * n) {
        cerr << "Warning: Performance bottleneck detected due to high edge additions in sparse graph!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d", &n, &m);
    if (n == 1) {
        if (m == 0) {
            puts("YES\n1\n1 1");
            return 0;
        }
        if (m == 1) {
            puts("YES\n0");
            return 0;
        }
        return puts("NO");
    }
    for (int i = 1; i <= n; i++) f[i] = i;
    bool circle = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (find(x) != find(y))
            f[find(x)] = find(y);
        else
            circle = 1;
        deg[x]++;
        deg[y]++;
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] > 2) return puts("NO");
    if (circle && m != n) return puts("NO");
    if (circle) {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (find(i) != find(j)) return puts("NO");
    }
    puts("YES");
    vector<pair<int, int>> ans;
    int addedEdges = 0;  // Track added edges

    while (m != n) {
        m++;
        bool ok = 0;
        for (int i = 1; i <= n && !ok; i++) {
            for (int j = i + 1; j <= n && !ok; j++) {
                checksPerformed++;  // Increment for each pairwise check
                if (find(i) != find(j) && deg[i] < 2 && deg[j] < 2) {
                    f[find(i)] = find(j);
                    deg[i]++;
                    deg[j]++;
                    ans.push_back(make_pair(i, j));
                    ok = 1;
                    addedEdges++;
                    // Check at this point for excessive edge additions
                    check_graph_sparsity_invariant(addedEdges, n, m, 2);
                }
            }
        }
    }
    
    // Check after loops for excessive union-find and combinatorial checks
    check_union_find_invariant(unionFindCalls, n * 10);
    check_combinatorial_checks_invariant(n, checksPerformed, n * n / 2);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (deg[i] == 1 && deg[j] == 1) {
                ans.push_back(make_pair(i, j));
                deg[i]++;
                deg[j]++;
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}