#include <bits/stdc++.h>
using namespace std;

void check_n_and_ki_invariant(int n, int ki) {
    if (n > 50000 || ki > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high n or ki!" << endl;
        abort();
    }
}

void check_coverage_invariant(int ma, int len) {
    if (ma > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive coverage!" << endl;
        abort();
    }
}

void check_ma_invariant(int ma) {
    if (ma > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large max index!" << endl;
        abort();
    }
}

bool t[4 * 2111111];
int n;
string now;
char c[4 * 2111111];

void update(int l, int r, int v = 1, int tl = 1, int tr = 2111111) {
    if (tl > r || tr < l) return;
    if (t[v]) return;
    if (tl == tr) {
        t[v] = 1;
        c[tl - 1] = now[tl - l];
        return;
    }
    int tm = (tl + tr) >> 1;
    update(l, r, v + v, tl, tm);
    update(l, r, v + 1 + v, tm + 1, tr);
    t[v] = t[v + v] && t[v + 1 + v];
}

int main() {
    cin >> n;
    int ma = 0;
    for (long long i = (0); i < (n); i++) {
        cin >> now;
        int k;
        cin >> k;
        
        // Check invariant for `n` and `ki`
        check_n_and_ki_invariant(n, k);
        
        int len = now.length() - 1;
        for (long long j = (0); j < (k); j++) {
            int w;
            cin >> w;
            ma = max(ma, w + len);
            
            // Check invariant for coverage and max index
            check_coverage_invariant(ma, len);
            check_ma_invariant(ma);
            
            update(w, w + len);
        }
    }
    
    for (long long i = (0); i < (ma); i++)
        if (c[i] >= 'a' && c[i] <= 'z')
            cout << c[i];
        else
            cout << 'a';
    return 0;
}