#include <bits/stdc++.h>
using namespace std;

namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char* s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
    bool read(int& x) {
        int n = read(str), bf;
        if (!n) return 0;
        int i = 0;
        if (str[i] == '-')
            bf = -1, i++;
        else
            bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};

const int N = 1e5 + 7, INF = 0x3f3f3f3f, mz = 1e9 + 7, M = 1e5 + 3;
const double PI = acos(0.0) * 2;

struct node {
    int f, p, t;
    node() { p = t = f = 0; }
    node(int a, int b, int e) : p(b), t(e), f(a) {}
    bool operator<(const node& rhs) const {
        if (f == rhs.f) return f == 2 ? p > rhs.p : p < rhs.p;
        return f > rhs.f;
    }
} p[N];

vector<int> e[N << 1];
vector<int> x, y;

struct Edge {
    int x, y;
    Edge() { x = y = 0; }
    Edge(int a, int b) : x(a), y(b) {}
    bool operator<(const Edge& rhs) const {
        if (x) return x < rhs.x;
        return y < rhs.y;
    }
} ans[N];

bool cmp(const int a, const int b) { return p[a] < p[b]; }

// Performance Checkers
void check_maxn_invariant(int maxn, int n) {
    if (maxn > n * 10) {
        cerr << "Warning: Performance bottleneck condition triggered - large maxn leading to many iterations!" << endl;
        abort();
    }
}

void check_sparse_population_invariant(const vector<int>& e, int threshold) {
    int emptyCount = 0;
    for (const auto& vec : e) {
        if (vec.empty()) ++emptyCount;
    }
    if (emptyCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - sparse population in e array!" << endl;
        abort();
    }
}

int main() {
    int n, w, h, maxn = -1;
    FastIO::read(n);
    FastIO::read(w);
    FastIO::read(h);
    for (int i = 1; i <= n; i++) {
        int g, q, t;
        FastIO::read(g);
        FastIO::read(q);
        FastIO::read(t);
        p[i] = node(g, q, t);
        e[q - t + M].push_back(i);
        maxn = max(q - t + M, maxn);
    }
    
    // Insert checks after data preparation, before the main processing loop
    check_maxn_invariant(maxn, n);
    check_sparse_population_invariant(e, maxn / 2); // threshold set to half of maxn for example

    for (int i = 0; i <= maxn; i++) {
        if (e[i].empty()) continue;
        x.clear();
        y.clear();
        sort(e[i].begin(), e[i].end(), cmp);
        for (auto it = e[i].begin(); it != e[i].end(); it++)
            if (p[*it].f == 1)
                x.push_back(p[*it].p);
            else
                y.push_back(p[*it].p);
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        auto js = e[i].begin();
        for (auto it = x.begin(); it != x.end(); it++, js++)
            ans[*js] = Edge(*it, h);
        for (int j = y.size() - 1; ~j; j--, js++) ans[*js] = Edge(w, y[j]);
    }
    for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i].x, ans[i].y);
    return 0;
}