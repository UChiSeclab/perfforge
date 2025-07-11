#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_initialization_invariant(int c, int d) {
    if (c > 50000 || d > 50000) {  // Threshold for large values
        cerr << "Warning: Initialization invariant triggered - large values of c or d causing large array initialization" << endl;
        abort();
    }
}

void check_get_function_invariant(int u) {
    if (u > 50000) {  // Threshold for deep iterations
        cerr << "Warning: Get function invariant triggered - large value of u causing deep iterations in get function" << endl;
        abort();
    }
}

int n, c, d;
int fc[100001];
int fd[100001];

void update(int *f, int u, int x) {
    for (; u <= 100000; u += u & -u) f[u] = max(f[u], x);
}

int get(int *f, int u) {
    check_get_function_invariant(u);  // Check before the loop in the get function
    int res = -1e9;
    for (; u > 0; u -= u & -u) res = max(res, f[u]);
    return res;
}

int main() {
    cin >> n >> c >> d;
    
    // Check invariants after reading inputs
    check_initialization_invariant(c, d);

    for (int i = 0; i <= c; i++) fc[i] = -1e9;
    for (int i = 0; i <= d; i++) fd[i] = -1e9;
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int b, p;
        char ch;
        cin >> b >> p >> ch;
        
        if (ch == 'C') {
            ans = max(ans, get(fc, c - p) + b);
            update(fc, p, b);
        } else {
            ans = max(ans, get(fd, d - p) + b);
            update(fd, p, b);
        }
    }
    
    ans = max(ans, get(fc, c) + get(fd, d));
    cout << ans << '\n';
}