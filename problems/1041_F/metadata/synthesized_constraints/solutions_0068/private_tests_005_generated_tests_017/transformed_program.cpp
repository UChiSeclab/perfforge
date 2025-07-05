#include <bits/stdc++.h>
using namespace std; 
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
int n, m;
int in1, in2;
int a[100050], b[100050], pots[32];
int qa[100050][32][2], qb[100050][32][2];
int ans;
unordered_map<int, int> restoa[32], restob[32];
unordered_map<int, int> aa, bb;

// Checkers for performance bottlenecks
void check_nested_loop_invariant(int sensorCount) {
    if (sensorCount > 80000) {
        cerr << "Warning: nested_loop_invariant triggered - high frequency of nested loop execution" << endl;
        abort();
    }
}

void check_large_structure_update(int n, int m) {
    if (n > 80000 && m > 80000) {
        cerr << "Warning: large_structure_invariant triggered - frequent updates on large data structures" << endl;
        abort();
    }
}

void check_preprocessing_invariant(int n, int m) {
    if ((n + m) > 150000) {
        cerr << "Warning: preprocessing_invariant triggered - preprocessing overhead with large inputs" << endl;
        abort();
    }
}

void check_input_size_invariant(int n, int m) {
    if (n > 95000 || m > 95000) {
        cerr << "Warning: input_size_invariant triggered - excessive operations due to large input sizes" << endl;
        abort();
    }
}

int testaa(int i, int pot) {
    return restoa[pot + 1][qa[i][pot][0]] + restob[pot + 1][qa[i][pot][1]];
}

int testab(int i, int pot) {
    return restob[pot + 1][qb[i][pot][0]] + restoa[pot + 1][qb[i][pot][1]];
}

void upa(int i) {
    for (int pot = 1; pot <= 30; pot++) {
        restoa[pot][qa[i][pot - 1][0]] += 1;
    }
}

void upb(int i) {
    for (int pot = 1; pot <= 30; pot++) {
        restob[pot][qb[i][pot - 1][0]] += 1;
    }
}

void solve() {
    int pa = n - 1, push_back = m - 1;
    while (pa >= 0 and push_back >= 0) {
        if (a[pa] > b[push_back]) {
            for (int i = 0; i < 30; i++) {
                ans = max(ans, 1 + testaa(pa, i));
            }
            upa(pa);
            --pa;
        } else {
            for (int i = 0; i < 30; i++) {
                ans = max(ans, 1 + testab(push_back, i));
            }
            upb(push_back);
            --push_back;
        }
    }
    while (pa >= 0) {
        for (int i = 0; i < 30; i++) {
            ans = max(ans, 1 + testaa(pa, i));
        }
        upa(pa);
        --pa;
    }
    while (push_back >= 0) {
        for (int i = 0; i < 30; i++) {
            ans = max(ans, 1 + testab(push_back, i));
        }
        upb(push_back);
        --push_back;
    }
    for (int i = 0; i < n; i++) ans = max(ans, aa[a[i]] + bb[b[i]]);
    for (int i = 0; i < m; i++) ans = max(ans, aa[b[i]] + bb[a[i]]);
}

void prezao() {
    pots[0] = 1;
    for (int i = 1; i <= 30; i++) pots[i] = pots[i - 1] + pots[i - 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            qa[i][j][0] = a[i] % pots[j + 1];
            qa[i][j][1] = (a[i] + pots[j] + pots[j + 1]) % pots[j + 1];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 30; j++) {
            qb[i][j][0] = b[i] % pots[j + 1];
            qb[i][j][1] = (b[i] + pots[j] + pots[j + 1]) % pots[j + 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> in1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        aa[a[i]] += 1;
    }
    cin >> m >> in2;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        bb[b[i]] += 1;
    }

    // Place performance checks here after reading inputs
    check_nested_loop_invariant(n + m);
    check_large_structure_update(n, m);
    check_preprocessing_invariant(n, m);
    check_input_size_invariant(n, m);

    prezao();
    solve();
    cout << ans << endl;
    return 0;
}