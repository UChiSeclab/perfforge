#include <bits/stdc++.h>
using namespace std;

int col[1000][1000] = { { 0, } };
int n1 = 0;
int n2 = 0;
int N, M;

void check_large_field_invariant(int n, int m) {
    if (n * m > 500000) { // Arbitrary threshold less than 1000*1000 to catch large fields
        cerr << "Warning: Performance bottleneck condition triggered - large field size!" << endl;
        abort();
    }
}

void go(queue<pair<int, int> > &q, int u, int v, int x, int y) {
    if (x >= 0 && y >= 0 && x < N && y < M && col[x][y] == 0) {
        q.push(make_pair(x, y));
        col[x][y] = 3 - col[u][v];
        if (col[x][y] == 1)
            ++n1;
        else
            ++n2;
    }
}

int main() {
    cin >> N >> M;

    // Check for large field size as a potential performance bottleneck
    check_large_field_invariant(N, M);

    int x, y;
    int ans = 0;
    for (int _n = N, ii = 0; ii < _n; ++ii)
        for (int _n = M, jj = 0; jj < _n; ++jj) {
            if (col[ii][jj]) continue;
            col[ii][jj] = 1;
            n1 = 1;
            n2 = 0;
            queue<pair<int, int> > q;
            q.push(make_pair(ii, jj));
            while (!q.empty()) {
                int u = q.front().first;
                int v = q.front().second;
                q.pop();
                x = u - 1;
                y = v - 2;
                go(q, u, v, x, y);
                x = u - 1;
                y = v + 2;
                go(q, u, v, x, y);
                x = u + 1;
                y = v - 2;
                go(q, u, v, x, y);
                x = u + 1;
                y = v + 2;
                go(q, u, v, x, y);
                x = u - 2;
                y = v - 1;
                go(q, u, v, x, y);
                x = u - 2;
                y = v + 1;
                go(q, u, v, x, y);
                x = u + 2;
                y = v - 1;
                go(q, u, v, x, y);
                x = u + 2;
                y = v + 1;
                go(q, u, v, x, y);
            }
            ans += max(n1, n2);
        }
    cout << ans << endl;
}