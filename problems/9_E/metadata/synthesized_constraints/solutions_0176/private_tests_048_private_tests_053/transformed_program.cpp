#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[55];
int col[55];
bool wasCicle;
bool matr[55][55];
int cnt[55];
bool add[55][55];

void resetCol() {
    static int resetCount = 0;
    resetCount++;
    check_reset_invariant(resetCount, 100); // Performance check for excessive resets

    for (int i = 1; i <= n; i++) col[i] = 0;
}

bool isOne() {
    for (int i = 1; i <= n; i++)
        if (col[i] != 2) return false;
    return true;
}

void dfs(int num, int p) {
    static int recursionDepth = 0;
    recursionDepth++;
    check_dfs_invariant(recursionDepth, v[num].size()); // Check recursion depth and branch factor

    col[num] = 1;
    for (int i = 0; i < v[num].size(); i++) {
        if (!matr[num][v[num][i]]) continue;
        if (!col[v[num][i]])
            dfs(v[num][i], num);
        else if (col[v[num][i]] == 1 && v[num][i] != p)
            wasCicle = true;
    }
    col[num] = 2;
    recursionDepth--;
}

void check_dfs_invariant(int recursionDepth, int branchFactor) {
    if (recursionDepth > 50 || branchFactor > 50) {
        cerr << "Warning: dfs_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

void check_reset_invariant(int resetCount, int threshold) {
    if (resetCount > threshold) {
        cerr << "Warning: reset_invariant triggered - excessive reset calls" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int iterationCount, int n) {
    if (iterationCount > n * n * n) { 
        cerr << "Warning: nested_loop_invariant triggered - large number of iterations" << endl;
        abort();
    }
}

void check_edge_operations_invariant(int edgeUpdates, int n) {
    if (edgeUpdates > n * n) {
        cerr << "Warning: edge_operations_invariant triggered - excessive edge updates" << endl;
        abort();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (n > 2 && matr[a][b]) {
            cout << "NO";
            return 0;
        }
        v[a].push_back(b);
        v[b].push_back(a);
        matr[a][b] = matr[b][a] = true;
        add[a][b] = add[b][a] = true;
        if (n != 1 && a == b) {
            cout << "NO";
            return 0;
        }
    }
    if (n == m) {
        bool ok = true;
        for (int i = 1; i <= n; i++)
            if (v[i].size() == 2)
                ;
            else
                ok = false;
        dfs(1, 0);
        if (ok && isOne() && (wasCicle || (n == 2 && matr[1][2]))) {
            cout << "YES" << endl << 0;
            return 0;
        }
    }
    bool bad1 = false, bad2 = false, bad3 = false;
    if (m > n) bad1 = true;
    wasCicle = false;
    resetCol();
    dfs(1, 0);
    if (wasCicle) bad2 = true;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() > 2) bad3 = true;
        cnt[i] = v[i].size();
    }
    if (bad1 || bad2 || bad3) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl << n - m << endl;
    if (n == 1) {
        cout << 1 << " " << 1;
        return 0;
    }
    int iterationCount = 0; // Track iteration count for nested loop check
    int edgeUpdates = 0; // Track edge update operations for performance check
    for (int i = 0; i < n - m - 1; i++) {
        bool post = false;
        for (int j = 1; j <= n && !post; j++) {
            for (int k = j + 1; k <= n && !post; k++) {
                iterationCount++;
                check_nested_loop_invariant(iterationCount, n); // Check nested loop operations

                if (!matr[j][k] && cnt[j] < 2 && cnt[k] < 2) {
                    matr[j][k] = matr[k][j] = true;
                    resetCol();
                    wasCicle = false;
                    dfs(j, 0);
                    edgeUpdates++;
                    check_edge_operations_invariant(edgeUpdates, n); // Monitor edge updates

                    if (!col[k]) {
                        if (!add[j][k]) {
                            v[j].push_back(k);
                            v[k].push_back(j);
                            add[j][k] = add[k][j] = true;
                        }
                        cout << j << " " << k << endl;
                        cnt[j]++;
                        cnt[k]++;
                        post = true;
                    } else
                        matr[j][k] = matr[k][j] = false;
                }
            }
        }
    }
    int p[55];
    p[0] = 0;
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 1) p[++p[0]] = i;
    sort(p + 1, p + 2);
    cout << p[1] << " " << p[2];
    return 0;
}