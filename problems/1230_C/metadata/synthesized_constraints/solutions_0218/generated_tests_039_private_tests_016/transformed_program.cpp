#include <bits/stdc++.h>
using namespace std;

vector<long long int> a(7, 0);
vector<vector<long long int>> adj(7, vector<long long int>(7, 0));
long long int max_count = 0;
long long int gn = 0;

// Checker for recursion depth.
void check_recursion_depth_invariant(int recursionDepth, int vertexCount) {
    if (recursionDepth >= vertexCount) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth for vertex count!" << endl;
        abort();
    }
}

// Checker for large search space with sparse graph.
void check_large_search_space_invariant(int vertexCount, int edgeCount) {
    if (vertexCount > 6 && edgeCount < vertexCount / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large search space with sparse graph!" << endl;
        abort();
    }
}

void rec(int n) {
    // Check recursion depth invariant.
    check_recursion_depth_invariant(gn - n, gn);

    if (n == 0) {
        long long int count = 0;
        vector<vector<long long int>> dom(6, vector<long long int>(6, 0));
        for (long long int i = 0; i < 6; i++)
            for (long long int j = i; j < 6; j++) dom[i][j] = 1;
        for (long long int i = 0; i < gn; i++)
            for (long long int j = i + 1; j < gn; j++) {
                if (dom[a[i]][a[j]] == 1 && adj[i][j] == 1) {
                    count++;
                    dom[a[i]][a[j]]--;
                } else if (dom[a[j]][a[i]] == 1 && adj[j][i] == 1) {
                    count++;
                    dom[a[j]][a[i]]--;
                }
            }
        if (count > max_count) max_count = count;
    } else {
        for (long long int i = 0; i < 6; i++) {
            a[n - 1] = i;
            rec(n - 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n, m;
    cin >> n >> m;
    gn = n;
    
    // Check for large search space with sparse graph.
    check_large_search_space_invariant(n, m);

    for (long long int i = 0; i < m; i++) {
        long long int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1 - 1][temp2 - 1] = 1;
        adj[temp2 - 1][temp1 - 1] = 1;
    }

    rec(n);
    cout << max_count << endl;
    return 0;
}