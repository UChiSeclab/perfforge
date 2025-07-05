#include <bits/stdc++.h>
using namespace std;

char str[1000001];
int n;
vector<string> v;
vector<vector<int>> g;
vector<bool> vis;
vector<string> sol;

void check_graph_traversal_invariant(int nodes, int dfsCalls) {
    if (nodes > 25 && dfsCalls > 50) {
        cerr << "Warning: Performance bottleneck due to complex graph traversal!" << endl;
        abort();
    }
}

void check_substring_nested_loops_invariant(int stringCount, int operationsCount) {
    if (stringCount > 20 && operationsCount > 500) {
        cerr << "Warning: Performance bottleneck due to nested loop operations on substrings!" << endl;
        abort();
    }
}

void check_substring_counting_invariant(int potentialGoodStringLength, int checkCount) {
    if (potentialGoodStringLength > 100 && checkCount > 600) {
        cerr << "Warning: Performance bottleneck due to extensive substring counting!" << endl;
        abort();
    }
}

void DFS(int u) {
    static int dfsCalls = 0;
    ++dfsCalls;  // Increment DFS call count
    if (vis[u]) {
        puts("NO");
        exit(0);
    }
    vis[u] = true;
    sol.back() += char(u + 'a');
    if (g[u].empty()) return;
    DFS(g[u][0]);

    // Check DFS invariant during traversal
    check_graph_traversal_invariant(g.size(), dfsCalls);
}

int main() {
    scanf("%d", &n);
    vector<bool> seen(26);
    int operationsCount = 0;  // To count operations in nested loops

    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        v.push_back(str);
        set<char> s;
        for (int i = 0; str[i]; ++i) {
            s.insert(str[i]);
            seen[str[i] - 'a'] = true;
        }
        if (s.size() != v.back().size()) {
            puts("NO");
            return 0;
        }
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    if (v.size() > 700) {
        puts("NO");
        return 0;
    }

    for (int it = 0; it < 2; ++it) {
        for (int i = 0; i < v.size(); ++i)
            for (int j = i + 1; j < v.size(); ++j) {
                operationsCount++;  // Increment operations count
                if ((int)v[i].find(v[j]) != -1) {
                    v[j] = v.back();
                    v.pop_back();
                    --j;
                }
            }
        reverse(v.begin(), v.end());
    }

    // Check nested loop operations invariant after potential heavy operations
    check_substring_nested_loops_invariant(v.size(), operationsCount);

    g.resize(26);
    vector<int> in(g.size());
    set<pair<int, int>> e;
    for (int i = 0; i < v.size(); ++i) {
        string s = v[i];
        for (int j = 0; j + 1 < s.size(); ++j) {
            int u = s[j] - 'a';
            int v = s[j + 1] - 'a';
            if (e.insert(make_pair(u, v)).second) {
                g[u].push_back(v);
                ++in[v];
            }
        }
    }

    for (int i = 0; i < g.size(); ++i) {
        if (g[i].size() > 1) {
            puts("NO");
            return 0;
        }
    }

    vis.resize(g.size());
    for (int i = 0; i < g.size(); ++i)
        if (seen[i] && !vis[i] && in[i] == 0) {
            sol.push_back(string());
            DFS(i);
        }

    for (int i = 0; i < g.size(); ++i)
        if (seen[i] && !vis[i]) {
            puts("NO");
            return 0;
        }

    sort(sol.begin(), sol.end());
    string ans = "";
    for (auto x : sol) ans += x;
    set<char> zz;
    for (auto x : ans) zz.insert(x);
    if (zz.size() != ans.size())
        ans = "NO";
    else {
        set<int> S;
        int checkCount = 0;  // For counting substring checks
        for (int i = 0; i < v.size(); ++i) {
            int occ = 0;
            for (int j = 0; j + v[i].size() <= ans.size(); ++j) {
                checkCount++;  // Increment check count
                if (ans.substr(j, v[i].size()) == v[i]) ++occ;
            }
            if (!occ) {
                ans = "NO";
                break;
            }
            S.insert(occ);
        }
        if (S.size() != 1) ans = "NO";

        // Check substring counting invariant after checks
        check_substring_counting_invariant(ans.size(), checkCount);
    }

    cout << ans << endl;
    return 0;
}