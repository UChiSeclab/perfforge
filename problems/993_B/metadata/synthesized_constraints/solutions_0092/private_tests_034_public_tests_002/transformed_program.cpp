#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vlli = vector<long long int>;
using vpii = vector<pair<int, int>>;

int n, m, x, y, cnt, ans;
bool check = true;
vpii a, b, A, B;
vi cntA(30, 0), cntB(30, 0);

// Checker for number of pairs
void check_pair_count_invariant(int n, int m) {
    if (n > 10 || m > 10) {
        cerr << "Warning: Performance bottleneck condition triggered - too many pairs!" << endl;
        abort();
    }
}

// Checker for excessive function calls
void check_function_call_invariant(int calls) {
    if (calls > 80) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive function calls!" << endl;
        abort();
    }
}

// Checker for excessive map operations
void check_map_operations_invariant(int mapSize) {
    if (mapSize > 5) {
        cerr << "Warning: Performance bottleneck condition triggered - map operations too frequent!" << endl;
        abort();
    }
}

int get(pii p, pii q) {
    map<int, int> cnt;
    cnt[p.first]++;
    cnt[p.second]++;
    cnt[q.first]++;
    cnt[q.second]++;
    if (cnt.size() == 4)
        return 0;
    else if (cnt.size() == 3)
        return 1;
    return 2;
}

int common(pii p, pii q) {
    map<int, int> cnt;
    cnt[p.first]++;
    cnt[p.second]++;
    cnt[q.first]++;
    cnt[q.second]++;
    if (cnt[p.first] == 2) return p.first;
    if (cnt[p.second] == 2) return p.second;
    if (cnt[q.first] == 2) return q.first;
    if (cnt[q.second] == 2) return q.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    // Check pair count invariant after input
    check_pair_count_invariant(n, m);

    for (int i = 0; i < n; i++) cin >> x >> y, a.push_back(make_pair(x, y));
    for (int i = 0; i < m; i++) cin >> x >> y, b.push_back(make_pair(x, y));

    int functionCalls = 0;
    for (auto p1 : a) {
        map<int, int> temp;
        for (auto p2 : b) {
            if (get(p1, p2) == 1) {
                temp[common(p1, p2)]++;
                functionCalls++;
            }
        }
        // Check map operations invariant
        check_map_operations_invariant(temp.size());

        if (temp.size() == 1)
            A.push_back(p1);
        else if (temp.size() > 1)
            check = false;
    }

    for (auto p1 : b) {
        map<int, int> temp;
        for (auto p2 : a) {
            if (get(p1, p2) == 1) {
                temp[common(p1, p2)]++;
                functionCalls++;
            }
        }
        // Check map operations invariant
        check_map_operations_invariant(temp.size());

        if (temp.size() == 1)
            B.push_back(p1);
        else if (temp.size() > 1)
            check = false;
    }

    // Check excessive function calls invariant
    check_function_call_invariant(functionCalls);

    set<int> ans;
    for (auto p1 : A)
        for (auto p2 : B)
            if (get(p1, p2) == 1) ans.insert(common(p1, p2));

    if (ans.size() > 1 && check)
        cout << 0;
    else if (ans.size() == 1 && check)
        cout << *(ans.begin());
    else
        cout << -1;
}