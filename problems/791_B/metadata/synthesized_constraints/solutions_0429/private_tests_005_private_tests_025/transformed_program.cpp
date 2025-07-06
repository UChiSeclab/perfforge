#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1000000000;
const long long int MOD = 1000000007;

// Checkers based on performance invariants
void check_members_friends_ratio(int n, int m) {
    if (n > 10000 && m < n / 10) {  // arbitrary threshold for sparse network
        cerr << "Warning: Performance bottleneck condition triggered - large number of members with sparse friendships!" << endl;
        abort();
    }
}

void check_sparse_network(int n, int m) {
    if (n > 10000 && m < n / 5) {
        cerr << "Warning: Performance bottleneck condition triggered - high member count with sparse connections!" << endl;
        abort();
    }
}

void check_redundant_set_operations(int n, int m) {
    if (n > 10000 && m == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - redundant set operations due to lack of friendships!" << endl;
        abort();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    register long long int i, j, x, y, m, n, t, k, sum = 0, max, min, count = 0, temp, w, q, f = 0;
    
    cin >> n >> m;

    // Insert performance checks right after input reading
    check_members_friends_ratio(n, m);
    check_sparse_network(n, m);
    check_redundant_set_operations(n, m);

    vector<set<long long int> > v(n + 1);
    vector<bool> visited(n + 1, false);
    for (i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
    }
    for (i = 1; i <= n; i++) {
        v[i].insert(i);
    }
    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            for (auto &it : v[i]) {
                visited[it] = true;
                if (v[it] != v[i]) {
                    f = 1;
                    break;
                }
            }
        }
        if (f) {
            break;
        }
    }
    if (f)
        cout << "NO";
    else
        cout << "YES";
}