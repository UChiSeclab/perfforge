#include <bits/stdc++.h>
using namespace std;

int a[2005];
int sz[2005];
int adj[2005][2005];

void push(int ind, int n) {
    for (int i = 0; i < n; ++i) {
        if (i != ind && a[ind] != a[i]) {
            adj[ind][sz[ind]++] = i;
        }
    }
}

int val[2005];

int f(int x, int y) {
    if (x > y) {
        swap(x, y);
    }
    if (a[x] > a[y]) {
        return 1;
    } else {
        return 0;
    }
}

void check_inversion_invariant(int n, const int* arr) {
    int distinct_count = 0;
    set<int> distinct_elements;
    
    for (int i = 0; i < n; ++i) {
        if (distinct_elements.find(arr[i]) == distinct_elements.end()) {
            distinct_elements.insert(arr[i]);
            distinct_count++;
        }
    }

    // Example condition: more than 70% of elements are distinct
    if (distinct_count > (n * 0.7)) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive distinct elements causing many inversion checks!" << endl;
        abort();
    }
}

void check_set_operation_invariant(int n, const int* arr) {
    multiset<int> element_counts;
    for (int i = 0; i < n; ++i) {
        element_counts.insert(arr[i]);
    }

    // Example condition: if more than half of the elements occur only once
    int single_occurrences = 0;
    for (const auto& elem : element_counts) {
        if (element_counts.count(elem) == 1) {
            single_occurrences++;
        }
    }

    if (single_occurrences > (n * 0.5)) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive unique elements causing inefficient set operations!" << endl;
        abort();
    }
}

void solve() {
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d ", &a[i]);
        a[i] = abs(a[i]);
    }

    // Insert the performance invariant checks after input reading
    check_inversion_invariant(n, a);
    check_set_operation_invariant(n, a);

    set<pair<int, int>> s;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        push(i, n);
        for (int j = 0; j < sz[i]; ++j) {
            val[i] += f(i, adj[i][j]);
        }
        ret += val[i];
        a[i] *= -1;
        for (int j = 0; j < sz[i]; ++j) {
            val[i] -= f(i, adj[i][j]);
        }
        a[i] *= -1;
        s.insert({val[i], i});
    }
    assert(ret % 2 == 0);
    ret /= 2;
    while (s.size() > 0 && (*prev(s.end())).first > 0) {
        pair<int, int> v = *prev(s.end());
        s.erase(v);
        ret -= v.first;
        v.first *= -1;
        s.insert(v);
        int id = v.second;
        for (int i = 0; i < sz[id]; ++i) {
            int vv = f(id, adj[id][i]);
            s.erase({val[adj[id][i]], adj[id][i]});
            val[adj[id][i]] -= f(id, adj[id][i]);
            a[adj[id][i]] *= -1;
            val[adj[id][i]] += f(id, adj[id][i]);
            a[adj[id][i]] *= -1;
            val[id] *= -1;
            val[adj[id][i]] += f(id, adj[id][i]);
            a[adj[id][i]] *= -1;
            val[adj[id][i]] -= f(id, adj[id][i]);
            a[adj[id][i]] *= -1;
            val[id] *= -1;
            s.insert({val[adj[id][i]], adj[id][i]});
        }
        val[id] *= -1;
        a[id] *= -1;
    }
    printf("%d\n", ret);
}

int main() {
    solve();
    return 0;
}