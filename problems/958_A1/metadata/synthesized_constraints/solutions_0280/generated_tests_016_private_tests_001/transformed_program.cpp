#include <bits/stdc++.h>
using namespace std;
char s[20][20], t[20][20], T[20][20];
int n;

void rot() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            t[j][n - 1 - i] = s[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            s[i][j] = t[i][j];
}

bool chk() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (T[i][j] != s[i][j])
                return false;
    return true;
}

void dfs(int a, int maxDepth) {
    check_dfs_invariant(a, maxDepth); // Detect excessive recursion depth
    if (a >= 8) return;
    if (chk()) {
        puts("Yes");
        exit(0);
    }
    int A[20][20];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            A[i][j] = s[i][j];
    rot();
    dfs(a + 1, maxDepth);
    for (int i = 0; i < n - 1 - i; ++i)
        for (int j = 0; j < n; ++j)
            swap(s[i][j], s[n - 1 - i][j]);
    dfs(a + 1, maxDepth);
    for (int i = 0; i < n - 1 - i; ++i)
        for (int j = 0; j < n; ++j)
            swap(s[i][j], s[n - 1 - i][j]);
    for (int i = 0; i < n - 1 - i; ++i)
        for (int j = 0; j < n; ++j)
            swap(s[j][i], s[j][n - 1 - i]);
    dfs(a + 1, maxDepth);
    for (int i = 0; i < n - 1 - i; ++i)
        for (int j = 0; j < n; ++j)
            swap(s[j][i], s[j][n - 1 - i]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    for (int i = 0; i < n; ++i) scanf("%s", T[i]);
    int maxDepth = 8; // Allowable depth for transformations
    dfs(0, maxDepth);
    puts("No");
}