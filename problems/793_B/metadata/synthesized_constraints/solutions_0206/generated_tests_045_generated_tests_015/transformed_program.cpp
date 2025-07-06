#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;

// Checkers for performance-characterizing invariants
void check_recursion_invariant(int recursionDepth, int branchingFactor) {
    if (recursionDepth > 100 || branchingFactor > 10) {
        cerr << "Warning: Recursion invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

void check_initialization_invariant(int n, int m) {
    if (n * m > 100000) {
        cerr << "Warning: Initialization invariant triggered - potentially large grid initialization" << endl;
        abort();
    }
}

void check_path_complexity_invariant(int obstacleCount, int n, int m) {
    if (obstacleCount > (n * m) / 2) {
        cerr << "Warning: Path complexity invariant triggered - high obstacle density" << endl;
        abort();
    }
}

long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
pair<long long, long long> shuru, ant;
vector<string> v;
long long n, m;
char a[4] = {'L', 'R', 'U', 'D'};
long long vis[1005][1005][5];

bool kro(long long x, long long y, long long dir, long long cnt) {
    check_recursion_invariant(cnt, 4); // Example call to monitor recursion

    if (x < 0 || y < 0 || x >= n || y >= m || cnt > 2 || v[x][y] == '*')
        return false;
    if (cnt <= 2 && x == ant.first && y == ant.second) return true;
    if (vis[x][y][dir]) return false;
    bool b, c, d, e;
    vis[x][y][dir] = 1;
    if (dir == 0) {
        b = kro(x, y + 1, 0, cnt);
        c = kro(x + 1, y, 2, cnt + 1);
        d = kro(x - 1, y, 3, cnt + 1);
    } else if (dir == 1) {
        b = kro(x, y - 1, 1, cnt);
        c = kro(x + 1, y, 2, cnt + 1);
        d = kro(x - 1, y, 3, cnt + 1);
    } else if (dir == 2) {
        b = kro(x, y + 1, 0, cnt + 1);
        c = kro(x + 1, y, 2, cnt);
        d = kro(x, y - 1, 1, cnt + 1);
    } else if (dir == 3) {
        b = kro(x, y + 1, 0, cnt + 1);
        c = kro(x - 1, y, 3, cnt);
        d = kro(x, y - 1, 1, cnt + 1);
    }
    return b || c || d;
}

void solve() {
    cin >> n >> m;
    v.resize(n);
    int obstacleCount = 0;

    for (long long i = 0; i < n; i++) cin >> v[i];
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            if (v[i][j] == 'S') shuru.first = i, shuru.second = j;
            if (v[i][j] == 'T') ant.first = i, ant.second = j;
            if (v[i][j] == '*') obstacleCount++;
        }
    }

    check_initialization_invariant(n, m); // Checking initialization thresholds
    check_path_complexity_invariant(obstacleCount, n, m); // Checking path complexity

    for (long long i = 0; i < 4; i++) {
        for (long long i = 0; i < 1001; i++) {
            for (long long j = 0; j < 1001; j++) {
                for (long long k = 0; k < 4; k++) vis[i][j][k] = 0;
            }
        }
        if (kro(shuru.first, shuru.second, i, 0)) {
            cout << "YES"
                 << "\n";
            return;
        }
    }
    cout << "NO"
         << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}