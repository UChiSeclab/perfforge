#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MN = 55;
int lab[MN], n, m, qu[MN];
pair<int, int> e[MN * MN];
vector<int> ke[MN];
bool mark[MN];
vector<pair<int, int> > ls;
vector<int> zero;

void check_connectivity_invariant(int n, int m) {
    if (n - m > n / 2) {
        cerr << "Warning: Connectivity invariant triggered - too many edges needed to connect graph" << endl;
        abort();
    }
}

void check_union_find_invariant(const int lab[], int n) {
    int disjointSets = count_if(lab, lab + n, [](int x) { return x < 0; });
    if (disjointSets > n / 2) {
        cerr << "Warning: Union-find invariant triggered - too many disjoint sets" << endl;
        abort();
    }
}

void check_edge_iteration_invariant(int n, int loopCounter) {
    if (loopCounter > n * (n - 1) / 2) {
        cerr << "Warning: Edge iteration invariant triggered - excessive edge checks" << endl;
        abort();
    }
}

bool check() {
    for (int i = 1; i <= n; i++) ke[i].clear();
    for (int i = 1; i <= m; i++) {
        ke[e[i].first].push_back(e[i].second);
        ke[e[i].second].push_back(e[i].first);
    }
    if (m != n) return false;
    memset(mark, false, sizeof mark);
    int first = 1, last = 1;
    qu[1] = 1;
    mark[1] = true;
    while (first <= last) {
        int u = qu[first++];
        for (int i = 0, _a = ke[u].size(); i < _a; i++) {
            int v = ke[u][i];
            if (mark[v]) continue;
            qu[++last] = v;
            mark[v] = true;
        }
    }
    if (last != n) return false;
    for (int i = 1; i <= n; i++)
        if (ke[i].size() != 2) return false;
    return true;
}

int getRoot(int u) {
    if (lab[u] < 0)
        return u;
    else
        return lab[u] = getRoot(lab[u]);
}

void merge(int u, int v) {
    int x = lab[u] + lab[v];
    if (lab[u] < lab[v]) {
        lab[u] = x;
        lab[v] = u;
    } else {
        lab[v] = x;
        lab[u] = v;
    }
}

vector<pair<int, int> > res;
int deg[MN];

bool can() {
    if (check()) return true;
    bool ok = true;
    memset(deg, 0, sizeof deg);
    memset(lab, -1, sizeof lab);
    for (int i = 1; i <= m; i++) {
        int u = e[i].first, v = e[i].second;
        ++deg[u];
        ++deg[v];
        u = getRoot(u);
        v = getRoot(v);
        if (u == v) {
            ok = false;
            break;
        }
        merge(u, v);
    }

    check_union_find_invariant(lab, n);

    for (int i = 1; i <= n; i++)
        if (deg[i] > 2) {
            ok = false;
            break;
        }
    return ok;
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        if (n == 1 && m == 0) {
            puts("YES");
            puts("1");
            puts("1 1");
            continue;
        }
        res.clear();
        for (int i = 1; i <= n; i++) {
            ke[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &e[i].first, &e[i].second);
        }

        check_connectivity_invariant(n, m);

        if (check()) {
            puts("YES");
            puts("0");
            continue;
        }
        if (!can()) {
            puts("NO");
            continue;
        }
        puts("YES");
        printf("%d\n", n - m);
        int need = n - m;
        int loopCounter = 0;  // Loop counter for edge iteration

        for (int turn = 1; turn <= need; turn++) {
            bool ok = false;
            for (int u = 1; u <= n; u++) {
                for (int v = u + 1; v <= n; v++) {
                    ++m;
                    e[m] = make_pair(u, v);
                    if (can()) {
                        ok = true;
                        break;
                    } else
                        --m;

                    loopCounter++;
                    check_edge_iteration_invariant(n, loopCounter);
                }
                if (ok) break;
            }
            printf("%d %d\n", e[m].first, e[m].second);
        }
    }
    return 0;
}