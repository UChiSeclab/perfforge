#include <bits/stdc++.h>
using namespace std;
int ans = 0;

// Checker functions for performance bottlenecks
void check_recursive_exploration(int k, int problemCount) {
    if (k == 4 && problemCount > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive subset exploration for k=4!" << endl;
        abort();
    }
}

void check_large_combinatorial_space(int k, int n) {
    if (k == 4 && n > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - large combinatorial space due to high problem count and team count!" << endl;
        abort();
    }
}

void check_high_recursive_calls(int k, int problemCount) {
    if (k == 4 && problemCount > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of recursive calls for k=4!" << endl;
        abort();
    }
}

void fun1(vector<vector<int>> a, int i, int n, int q, int u) {
    if (i < n) {
        fun1(a, i + 1, n, q, u);
        u += a[i][0];
        q++;
        if (q / 2 >= u) ans++;
        fun1(a, i + 1, n, q, u);
    }
}

void fun2(vector<vector<int>> a, int i, int n, int q, int u, int v) {
    if (i < n) {
        fun2(a, i + 1, n, q, u, v);
        u += a[i][0];
        v += a[i][1];
        q++;
        if (q / 2 >= max(u, v)) ans++;
        fun2(a, i + 1, n, q, u, v);
    }
}

void fun3(vector<vector<int>> a, int i, int n, int q, int u, int v, int w) {
    if (i < n) {
        fun3(a, i + 1, n, q, u, v, w);
        u += a[i][0];
        v += a[i][1];
        w += a[i][2];
        q++;
        if (q / 2 >= max(u, max(v, w))) ans++;
        fun3(a, i + 1, n, q, u, v, w);
    }
}

void fun4(vector<vector<int>> a, int i, int n, int q, int u, int v, int w, int x) {
    if (i < n) {
        fun4(a, i + 1, n, q, u, v, w, x);
        u += a[i][0];
        v += a[i][1];
        w += a[i][2];
        x += a[i][3];
        q++;
        if (q / 2 >= max(u, max(v, max(w, x)))) ans++;
        fun4(a, i + 1, n, q, u, v, w, x);
    }
}

int main() {
    int n, k, i, x, y, f[10000] = {};
    vector<vector<int>> v;
    cin >> n >> k;

    // Check for potential performance bottlenecks
    check_large_combinatorial_space(k, n);

    while (n--) {
        y = 0;
        vector<int> v2;
        for (i = 0; i < k; i++) {
            cin >> x;
            y = (y * 10) + x;
            v2.push_back(x);
        }
        if (f[y] == 0) v.push_back(v2);
        f[y]++;
    }

    // Check for more bottlenecks after input processing
    check_recursive_exploration(k, v.size());
    check_high_recursive_calls(k, v.size());

    if (k == 1)
        fun1(v, 0, v.size(), 0, 0);
    else if (k == 2)
        fun2(v, 0, v.size(), 0, 0, 0);
    else if (k == 3)
        fun3(v, 0, v.size(), 0, 0, 0, 0);
    else
        fun4(v, 0, v.size(), 0, 0, 0, 0, 0);

    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}