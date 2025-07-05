#include <bits/stdc++.h>
#pragma comment(linker, "/stack:256000000")
using namespace std;

const int N = 5000 + 13;
const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};
int n, m;
int cnt[N];
int d[N][N];

// Invariant checkers
void check_large_sparse_matrix(bool condition) {
    if (condition) {
        cerr << "Warning: large_sparse_matrix_invariant triggered - potential slow BFS propagation!" << endl;
        abort();
    }
}

void check_large_x_value(bool condition) {
    if (condition) {
        cerr << "Warning: large_x_value_invariant triggered - excessive iterations likely!" << endl;
        abort();
    }
}

void check_bfs_spread(bool condition) {
    if (condition) {
        cerr << "Warning: bfs_spread_invariant triggered - broad BFS expansion!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> m;
    int x;
    cin >> x;

    // Check invariants at the beginning of the program
    check_large_sparse_matrix(n * m > 20000000); // Example threshold for large grids
    check_large_x_value(x > 1000 && n < 100 && m < 100); // Large x with small n, m combination
    check_bfs_spread(n > 4000 && m > 4000 && x < 1500); // Large grid with small x

    if (x >= N) {
        cout << 0 << endl;
        return 0;
    }
    
    queue<pair<int, int>> q;
    int firstAns = 0;
    
    for (int i = 0; i < int(n); i++)
        for (int it = 0; it < int(2); it++) {
            int j = 0;
            if (it == 1) j = m - 1;
            if (!(i == 0 || i == n - 1 || j == 0 || j == m - 1)) continue;
            if (i % 2 != j % 2) continue;
            if (d[i][j] == 0) firstAns++;
            d[i][j] = 1;
            q.push(make_pair((i), (j)));
        }
    
    for (int j = 0; j < int(m); j++)
        for (int it = 0; it < int(2); it++) {
            int i = 0;
            if (it == 1) i = n - 1;
            if (!(i == 0 || i == n - 1 || j == 0 || j == m - 1)) continue;
            if (i % 2 != j % 2) continue;
            if (d[i][j] == 0) firstAns++;
            d[i][j] = 1;
            q.push(make_pair((i), (j)));
        }
    
    if (n > 4000 && m > 4000 && x < 1501) {
        int ans = firstAns;
        ans -= 4 * (x - 1);
        cout << ans << endl;
        return 0;
    }
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < int(4); i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!(0 <= (nx) && (nx) < (n) && 0 <= (ny) && (ny) < (m))) continue;
            if (d[nx][ny] > d[x][y] + 1 || d[nx][ny] == 0) {
                d[nx][ny] = d[x][y] + 1;
                q.push(make_pair((nx), (ny)));
            }
        }
    }
    
    for (int i = 0; i < int(n); i++)
        for (int j = 0; j < int(m); j++) cnt[d[i][j]]++;
    
    cout << cnt[x] << endl;
    cerr << clock() << endl;
    return 0;
}