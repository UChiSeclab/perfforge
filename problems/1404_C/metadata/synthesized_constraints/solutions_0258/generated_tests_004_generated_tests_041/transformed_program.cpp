#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Performance check functions
void check_segment_tree_operations(int operationCount) {
    if (operationCount > 100000) {
        cerr << "Warning: Performance bottleneck due to excessive segment tree operations!" << endl;
        abort();
    }
}

void check_fenwick_tree_operations(int operationCount) {
    if (operationCount > 100000) {
        cerr << "Warning: Performance bottleneck due to excessive Fenwick tree operations!" << endl;
        abort();
    }
}

void check_find_last_operations(int operationCount) {
    if (operationCount > 50000) {
        cerr << "Warning: Performance bottleneck due to excessive find_last operations!" << endl;
        abort();
    }
}

void check_query_processing(int queryCount) {
    if (queryCount > 300000) {
        cerr << "Warning: Performance bottleneck due to excessive query processing!" << endl;
        abort();
    }
}

template <class T>
struct segtree {
    int n;
    T def = 1e9;
    vector<T> node, lazy;
    vector<bool> flag;
    function<T(T, T)> f = [&](T a, T b) { return min(a, b); };
    function<T(T, T)> g = [&](T a, T b) { return a + b; };
    int operationCount = 0;

    segtree(int _n) {
        n = 1 << (32 - __builtin_clz(_n - 1));
        node.resize(2 * n - 1, def);
        lazy.resize(2 * n - 1);
        flag.resize(2 * n - 1, false);
    }

    segtree(vector<T> a) {
        n = 1 << (32 - __builtin_clz((int)a.size() - 1));
        node.resize(2 * n - 1, def);
        lazy.resize(2 * n - 1);
        flag.resize(2 * n - 1, false);
        for (int i = 0; i < (int)a.size(); i++) {
            node[i + n - 1] = a[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            node[i] = f(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    void eval(int x, int l, int r) {
        if (!flag[x]) {
            return;
        }
        node[x] = g(node[x], lazy[x]);
        if (r - l > 1) {
            lazy[x * 2 + 1] = g(lazy[x * 2 + 1], lazy[x]);
            lazy[x * 2 + 2] = g(lazy[x * 2 + 2], lazy[x]);
            flag[x * 2 + 1] = flag[x * 2 + 2] = true;
        }
        lazy[x] = 0;
        flag[x] = false;
    }

    void update(int a, int b, T v, int x, int l, int r) {
        eval(x, l, r);
        operationCount++;
        check_segment_tree_operations(operationCount); // Check segment tree operations
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[x] = g(lazy[x], v);
            flag[x] = true;
            eval(x, l, r);
        } else {
            update(a, b, v, 2 * x + 1, l, (l + r) / 2);
            update(a, b, v, 2 * x + 2, (l + r) / 2, r);
            node[x] = f(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    T get(int a, int b, int x, int l, int r) {
        eval(x, l, r);
        if (b <= l || r <= a) {
            return def;
        }
        if (a <= l && r <= b) {
            return node[x];
        }
        T vl = get(a, b, 2 * x + 1, l, (l + r) / 2);
        T vr = get(a, b, 2 * x + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

    void update(int a, int b, T v) { update(a, b, v, 0, 0, n); }
    T get(int a, int b) { return get(a, b, 0, 0, n); }
    T get(int a) { return get(a, a + 1, 0, 0, n); }

    int find_last(int a, int b, function<bool(T)> fn, int x, int l, int r) {
        eval(x, l, r);
        operationCount++;
        check_find_last_operations(operationCount); // Check find_last operations
        if (!fn(node[x]) || b <= l || r <= a) {
            return a - 1;
        }
        if (x >= n - 1) {
            return x - n + 1;
        }
        int res = find_last(a, b, fn, 2 * x + 2, (l + r) / 2, r);
        if (res != a - 1) {
            return res;
        }
        return find_last(a, b, fn, 2 * x + 1, l, (l + r) / 2);
    }

    int find_last(int a, int b, function<bool(T)> fn) {
        return find_last(a, b, fn, 0, 0, n);
    }
};

template <class T>
struct fenwick {
    vector<T> node;
    int n;
    int operationCount = 0;

    fenwick(int _n) : n(_n) { node.resize(n); }

    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
            operationCount++;
            check_fenwick_tree_operations(operationCount); // Check Fenwick tree operations
        }
    }

    T get(int x) {
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
            operationCount++;
            check_fenwick_tree_operations(operationCount); // Check Fenwick tree operations
        }
        return v;
    }

    T get(int x, int y) { return (get(y) - (x ? get(x - 1) : 0)); }

    int lower_bound(T v) {
        int x = 0;
        int h = 1;
        while (n >= (h << 1)) {
            h <<= 1;
        }
        for (int k = h; k > 0; k >>= 1) {
            if (x + k <= n && node[x + k - 1] < v) {
                v -= node[x + k - 1];
                x += k;
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    check_query_processing(q); // Check query count
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        a[i] = i - a[i];
        if (a[i] < 0) {
            a[i] = n + 1;
        }
    }
    segtree<int> t(a);
    function<bool(int)> fa = [&](int p) { return p == 0; };
    vector<int> b;
    map<int, int> mp;
    while (t.get(0, t.n) == 0) {
        int x = t.find_last(0, t.n, fa);
        mp[x] = b.size();
        b.emplace_back(x);
        t.update(x, x + 1, 1e9);
        t.update(x, t.n, -1);
    }
    vector<int> c = b;
    sort(c.rbegin(), c.rend());
    vector<int> mnb = b;
    for (int i = 1; i < b.size(); i++) {
        mnb[i] = min(mnb[i], mnb[i - 1]);
    }
    vector<vector<int>> ans(q, vector<int>(4));
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (b.empty() || b[0] < x) {
            ans[i][0] = -1;
            ans[i][2] = i;
            continue;
        }
        y = n - y;
        int id = mnb.rend() - upper_bound(mnb.rbegin(), mnb.rend(), x - 1) - 1;
        int res = id + 1;
        ans[i][0] = y;
        ans[i][1] = res;
        ans[i][2] = i;
        ans[i][3] = id;
    }
    fenwick<int> bt(n + 1);
    sort(ans.rbegin(), ans.rend());
    int j = 0;
    for (int i = 0; i < q; i++) {
        if (ans[i][0] == -1) {
            break;
        }
        while (j != c.size() && c[j] >= ans[i][0]) {
            bt.add(mp[c[j]], 1);
            j++;
        }
        ans[i][1] -= bt.get(ans[i][3]);
    }
    sort(ans.begin(), ans.end(),
         [&](vector<int> iv, vector<int> jv) { return iv[2] < jv[2]; });
    for (int i = 0; i < q; i++) {
        cout << ans[i][1] << '\n';
    }
    return 0;
}