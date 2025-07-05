#include <bits/stdc++.h>
const int inf = 1000000007;
using namespace std;

long long read() {
    long long x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f * x;
}

struct edge {
    int t;
    edge *next;
} e[20005], *h[400005], *o = e;

void add(int x, int y) {
    o->t = y;
    o->next = h[x];
    h[x] = o++;
}

int n, m, _x, _y, S, ans, _v[400005];
bool v[400005];
queue<int> q;

// Function to check graph connectivity invariant
void check_graph_connectivity(int disconnectedComponents, int totalCities) {
    if (disconnectedComponents > totalCities / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - too many disconnected components!" << endl;
        abort();
    }
}

// Function to check road density invariant
void check_road_density(int numCities, int numRoads) {
    if (numRoads < numCities / 10 && numCities > 1000) { // Assuming large cities should have more roads
        cerr << "Warning: Performance bottleneck condition triggered - sparse road network!" << endl;
        abort();
    }
}

// Function to check capital connectivity invariant
void check_capital_connectivity(bool isCapitalWellConnected) {
    if (!isCapitalWellConnected) {
        cerr << "Warning: Performance bottleneck condition triggered - capital city not well connected!" << endl;
        abort();
    }
}

void bfs(int S) {
    q.push(S);
    v[S]++;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (edge *j = h[t]; j; j = j->next)
            if (!v[j->t]) v[j->t]++, q.push(j->t);
    }
}

int bfs1(int S) {
    int s = 0;
    q.push(S);
    _v[S] = _x;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        s++;
        for (edge *j = h[t]; j; j = j->next)
            if (!v[j->t] && _v[j->t] != _x) _v[j->t] = _x, q.push(j->t);
    }
    return s;
}

int main() {
    n = read();
    m = read();
    S = read();
    
    // Check invariant for road density
    check_road_density(n, m);
    
    for (int i = 1; i <= m; i++) {
        _x = read();
        _y = read();
        add(_x, _y);
    }
    
    bfs(S);
    
    // Check if the capital city is well connected
    // Assuming that if at least one connection exists initially, it's considered well-connected
    bool isCapitalWellConnected = (h[S] != nullptr);
    check_capital_connectivity(isCapitalWellConnected);

    _x = 0;
    int disconnectedComponents = 0;
    while (1) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (!v[i]) {
                _x++;
                int t = bfs1(i);
                if (t > cnt) S = i, cnt = t;
                disconnectedComponents++;
            }
        if (!cnt) break;
        bfs(S);
        ans++;
    }
    
    // Check invariant for graph connectivity after processing
    check_graph_connectivity(disconnectedComponents, n);
    
    return 0 * printf("%d\n", ans);
}