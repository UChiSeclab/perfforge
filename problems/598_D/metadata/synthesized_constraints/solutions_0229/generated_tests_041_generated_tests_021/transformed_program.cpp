#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const long long mod = 1000000007ll;
int n, m;
int cnt;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char a[N][N];
bool vis[N][N], vis2[N][N];

// Checker functions
void check_large_component_invariant(int componentSize, int threshold) {
    if (componentSize > threshold) {
        cerr << "Warning: Large connected component invariant triggered - excessive BFS traversal" << endl;
        abort();
    }
}

void check_complex_structure_invariant(int wallsCount, int threshold) {
    if (wallsCount > threshold) {
        cerr << "Warning: Complex structure invariant triggered - frequent transitions" << endl;
        abort();
    }
}

void check_repeated_calculations_invariant(int startCount, int threshold) {
    if (startCount > threshold) {
        cerr << "Warning: Repeated calculations invariant triggered - multiple BFS from same components" << endl;
        abort();
    }
}

void bfs1(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    int wallsCount = 0;
    int componentSize = 0;
    
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int cx = p.first, cy = p.second;
        componentSize++;
        
        for (int i = 0; i < 4; i++) {
            int tx = cx + dx[i], ty = cy + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty]) continue;
            if (a[tx][ty] == '*') {
                wallsCount++;
                cnt++;
                continue;
            }
            vis[tx][ty] = 1;
            q.push({tx, ty});
        }
    }
    // Check for large connected components.
    check_large_component_invariant(componentSize, 500); // Adjustable threshold
    // Check for complex structure.
    check_complex_structure_invariant(wallsCount, 100); // Adjustable threshold
}

int ans[N][N];

void bfs2(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int cx = p.first, cy = p.second;
        ans[cx][cy] = cnt;
        for (int i = 0; i < 4; i++) {
            int tx = cx + dx[i], ty = cy + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || vis2[tx][ty]) continue;
            if (a[tx][ty] == '*') continue;
            vis2[tx][ty] = 1;
            q.push({tx, ty});
        }
    }
}

int main() {
    int i, j;
    int T;
    cin >> n >> m >> T;
    for (i = 1; i <= n; i++) {
        cin >> (a[i] + 1);
    }
    
    int startCount = 0; // To track repeated calculations for starting points
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (!vis[i][j] && a[i][j] != '*') {
                vis[i][j] = 1;
                cnt = 0;
                bfs1(i, j);
                bfs2(i, j);
                startCount++;
            }
        }
    }
    
    // Check for repeated calculations
    check_repeated_calculations_invariant(startCount, n * m / 10); // Adjustable threshold
    
    while (T--) {
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << endl;
    }
    
    return 0;
}