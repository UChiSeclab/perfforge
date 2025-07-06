#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int n, m, fst, a, b;
bool uz[2500];
vector<int> v[2500];
vector<pair<long long, long long> > ans;

void check_cycle_detection_invariant(int nodesChecked) {
    if (nodesChecked > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive cycle detection checks!" << endl;
        abort();
    }
}

void check_redundant_connectivity_invariant(int connectivityChecks) {
    if (connectivityChecks > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive connectivity checks!" << endl;
        abort();
    }
}

void check_graph_traversal_invariant(int nodeDegree, int nodeCount) {
    if (nodeDegree < 2 && nodeCount > 40) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient graph traversal due to low node connectivity!" << endl;
        abort();
    }
}

int cycle(int nod, int ant, int lg) {
    if (uz[nod]) return 0;
    uz[nod] = 1;
    int ok = 0;
    for (auto it : v[nod]) {
        if (it == ant && !ok) {
            ok = 1;
            continue;
        }
        if (uz[it]) {
            if (it != fst)
                return 1;
            else
                return lg;
        }
        int x = cycle(it, nod, lg + 1);
        if (x) return x;
    }
    return 0;
}

bool conex(int a, int b) {
    uz[a] = 1;
    if (a == b) return 1;
    for (auto it : v[a]) {
        if (uz[it]) continue;
        return conex(it, b);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    check_graph_traversal_invariant(0, n); // Check at the start with node count

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ok = -1;
    int cycleChecks = 0; // Counter for cycle detection calls
    for (int i = 1; i <= n; i++) {
        if (v[i].size() > 2) {
            cout << "NO\n";
            return 0;
        }
        fst = i;
        cycleChecks++;
        int x = cycle(i, -1, 1);
        if (x == n)
            ok = 1;
        else if (x)
            ok = 0;
        
        check_cycle_detection_invariant(cycleChecks); // Check cycle detection overhead
    }
    if (ok == 0) {
        cout << "NO\n";
        return 0;
    }

    vector<pair<long long, long long> > e;
    for (int i = 1; i <= n; i++)
        if (v[i].size() == 1) e.push_back({i, 1});
    int sav = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 0) {
            e.push_back({i, 0});
        }
    }
    sort(e.begin(), e.end());
    ok = 0;
    int connectivityChecks = 0; // Counter for connectivity checks
    for (int i = 0; i < e.size(); i++) {
        for (int j = i + 1; j < e.size(); j++) {
            memset(uz, 0, sizeof(uz));
            connectivityChecks++;
            bool x = conex(e[i].first, e[j].first);
            if (e[i].second <= 1 && e[j].second <= 1 && !x) {
                v[e[i].first].push_back(e[j].first);
                v[e[j].first].push_back(e[i].first);
                ans.push_back(
                    {min(e[i].first, e[j].first), max(e[i].first, e[j].first)});
                e[i].second++;
                e[j].second++;
                sort(e.begin(), e.end());
                i = 0;
                j = 0;
                continue;
            }
            
            check_redundant_connectivity_invariant(connectivityChecks); // Check redundant connectivity
        }
    }

    int a = 0, b = 0, aux = 0;
    for (int i = 0; i < e.size(); i++) {
        if (e[i].second == 0) {
            if (!aux)
                aux = e[i].first;
            else {
                cout << "NO\n";
                return 0;
            }
        } else if (e[i].second == 1) {
            if (!a)
                a = e[i].first;
            else if (!b)
                b = e[i].first;
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }

    if (aux && n == 1)
        ans.push_back({aux, aux});
    else if (aux) {
        cout << "NO\n";
        return 0;
    } else if (!aux && a && b)
        ans.push_back({min(a, b), max(a, b)});
    else if (!aux && a) {
        cout << "NO\n";
        return 0;
    }

    sort(ans.begin(), ans.end());
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto it : ans) {
        cout << it.first << ' ' << it.second << '\n';
    }
    return 0;
}