#include <bits/stdc++.h>
using namespace std;

int n, k, ans, st[10], edge[10];
vector<int> L[10];
bool fr[10];

// Checker functions
void check_dfs_invariant(int currentDepth, int maxDepth, int branchFactor) {
    if (currentDepth > maxDepth || branchFactor > k) {
        cerr << "Warning: dfs_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

void check_backtracking_invariant(int currentStep) {
    if (currentStep > k) {
        cerr << "Warning: backtracking_invariant triggered - excessive backtracking steps" << endl;
        abort();
    }
}

void check_connectivity_invariant(int checkCount) {
    if (checkCount > (1 << k)) {
        cerr << "Warning: connectivity_invariant triggered - excessive connectivity checks" << endl;
        abort();
    }
}

void check_plaque_assignment_invariant(int pathCount) {
    if (pathCount > (1 << k)) {
        cerr << "Warning: plaque_assignment_invariant triggered - complex plaque assignments" << endl;
        abort();
    }
}

inline int Pow_Log(int x, int p) {
    int sol = 1;
    while (p) {
        if (p & 1) {
            sol = (1LL * sol * x) % 1000000007;
            --p;
        }
        p >>= 1;
        x = (1LL * x * x) % 1000000007;
    }
    return sol;
}

inline void Dfs(int nod, int currentDepth) {
    vector<int>::iterator it;
    int branchFactor = L[nod].size();
    check_dfs_invariant(currentDepth, k, branchFactor);
    for (it = L[nod].begin(); it != L[nod].end(); ++it) {
        if (!fr[*it]) {
            fr[*it] = true;
            Dfs(*it, currentDepth + 1);
        }
    }
}

inline bool Ok() {
    int i, cnt, connectivityCheckCount = 0;
    for (i = 1; i <= k; ++i) L[i].clear();
    for (i = 1; i <= k; ++i) {
        fr[i] = false;
        L[st[i]].push_back(i);
    }
    Dfs(1, 0);
    for (i = 1, cnt = 0; i <= k; ++i) cnt += fr[i];
    connectivityCheckCount++;
    check_connectivity_invariant(connectivityCheckCount);
    return (cnt == k);
}

inline void Back(int pas) {
    check_backtracking_invariant(pas);
    int i;
    if (pas == k + 1) {
        if (Ok()) ++ans;
        return;
    }
    for (i = 1; i <= k; ++i) {
        st[pas] = i;
        Back(pas + 1);
    }
}

int main() {
    int i, j;
    cin.sync_with_stdio(0);
    cin >> n >> k;
    Back(1);
    check_plaque_assignment_invariant(ans);
    ans = (1LL * ans * Pow_Log(n - k, n - k)) % 1000000007;
    cout << ans;
    return 0;
}