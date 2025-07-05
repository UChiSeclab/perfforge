#include <bits/stdc++.h>
using namespace std;

int V, E, g[5003][5003];
int cnt, Stack[5003], top;
char vis[5003], ins[5003], ans[5003];
int dfn[5003], low[5003];
int uf[5003];
int used[5003];
int findCount = 0;  // Counter for find operations
struct Edge {
  int u, v;
  Edge(void) {}
  Edge(int uu, int vv) : u(uu), v(vv) {}
} Es[5003];

// Checker functions
void check_graph_connectivity(int V, int visCount) {
    if (visCount < V / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - many disconnected components or isolated nodes!" << endl;
        abort();
    }
}

void check_union_find_efficiency(int findCount, int V) {
    if (findCount > V * 10) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive union-find operations!" << endl;
        abort();
    }
}

void check_dense_graph_traversal(int edgeChecks, int V, int E) {
    if (edgeChecks > V * V && E < V / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient dense graph traversal!" << endl;
        abort();
    }
}

// Union-find function with counter
int find(int x) {
    findCount++;
    if (uf[x] >= 0) return uf[x] = find(uf[x]);
    return x;
}

void merge(int x, int y) {
    int r1 = find(x);
    int r2 = find(y);
    if (r1 < r2) {
        uf[r1] += uf[r2];
        uf[r2] = r1;
    } else if (r2 < r1) {
        uf[r2] += uf[r1];
        uf[r1] = r2;
    }
}

void Tarjian(int u) {
    vis[u] = ins[u] = 1;
    dfn[u] = low[u] = ++cnt;
    Stack[top++] = u;
    for (int v = 1; v <= V; ++v) {
        if (g[u][v]) {
            if (!vis[v]) {
                Tarjian(v);
                if (low[u] > low[v]) low[u] = low[v];
            } else if (ins[v]) {
                if (low[u] > dfn[v]) low[u] = dfn[v];
            }
        }
    }
    if (dfn[u] == low[u]) {
        int now, sum = 0;
        while (1) {
            now = Stack[--top];
            ins[now] = 0;
            if (now == u) break;
            merge(now, u);
        }
    }
}

int main() {
    int u, v, e, ccnt = 0, tp, src;
    memset(uf, -1, sizeof(uf));
    scanf("%d %d %d", &V, &E, &src);
    for (e = 0; e < E; ++e) {
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        Es[e] = Edge(u, v);
    }

    int visCount = 0;
    for (u = 1; u <= V; ++u)
        if (!vis[u]) {
            Tarjian(u);
            visCount++;
        }

    // Perform checker for graph connectivity after DFS
    check_graph_connectivity(V, visCount);

    for (u = 1; u <= V; ++u) tp = find(u), used[tp] = tp;

    int edgeChecks = 0;
    for (e = 0; e < E; ++e) {
        tp = find(Es[e].v);
        if (find(Es[e].u) != tp) {
            ans[tp] = 1;
        }
        edgeChecks++;
    }

    // Perform checker for dense graph traversal
    check_dense_graph_traversal(edgeChecks, V, E);

    // Perform checker for union-find efficiency
    check_union_find_efficiency(findCount, V);

    ans[0] = 1;
    for (u = 1; u <= V; ++u)
        if (!ans[used[u]]) ccnt++;
    if (!ans[find(src)]) ccnt--;
    printf("%d\n", ccnt);
}