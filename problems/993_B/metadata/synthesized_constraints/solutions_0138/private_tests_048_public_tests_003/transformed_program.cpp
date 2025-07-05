#include <bits/stdc++.h>
using namespace std;

void check_nested_loop_invariant(int n, int m) {
    if (n * m > 120) {
        cerr << "Warning: Performance bottleneck condition triggered - nested loop iterations too high!" << endl;
        abort();
    }
}

void check_set_operation_invariant(int n, int m) {
    if (n * m > 120) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive set operations in nested loops!" << endl;
        abort();
    }
}

void check_function_call_invariant(int n, int m) {
    if (n * m > 120) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive function calls in nested loops!" << endl;
        abort();
    }
}

int val(int a, int b, int c, int d) {
    if (a == c || a == d) return a;
    if (b == c || b == d) return b;
    return -1; // Added to handle undefined return
}

int val1[100], val2[100];
vector<pair<int, int>> v1, v2;
set<int> s;

int main() {
    int n, m;
    cin >> n >> m;

    // Insert checks after input is read but before processing begins
    check_nested_loop_invariant(n, m);
    check_set_operation_invariant(n, m);
    check_function_call_invariant(n, m);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v1.push_back(make_pair(x, y));
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v2.push_back(make_pair(x, y));
    }
    for (int i = 0; i < 50; i++) {
        val1[i] = -1;
        val2[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s.clear();
            s.insert(v1[i].first);
            s.insert(v1[i].second);
            s.insert(v2[j].first);
            s.insert(v2[j].second);
            if (s.size() == 3) {
                if (val1[i] == -1 || val1[i] == val(v1[i].first, v1[i].second, v2[j].first, v2[j].second))
                    val1[i] = val(v1[i].first, v1[i].second, v2[j].first, v2[j].second);
                else
                    val1[i] = 0;
                if (val2[j] == -1 || val2[j] == val(v1[i].first, v1[i].second, v2[j].first, v2[j].second))
                    val2[j] = val(v1[i].first, v1[i].second, v2[j].first, v2[j].second);
                else
                    val2[j] = 0;
            }
        }
    }
    s.clear();
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (val1[i] == 0) flag = false;
    }
    for (int i = 0; i < m; i++) {
        if (val2[i] == 0) flag = false;
    }
    for (int i = 0; i < n; i++) {
        int x = val1[i];
        if (x > 0) s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x = val2[i];
        if (x > 0) s.insert(x);
    }
    if (flag && s.size() == 1) {
        int x = *s.begin();
        cout << x << '\n';
        return 0;
    }
    if (flag)
        cout << "0" << '\n';
    else
        cout << -1 << '\n';
}