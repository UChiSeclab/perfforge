#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXV = 1000000;
int N;
int it[MAXV * 4 + 100];
bool dau[MAXV + 10];

// Checker functions
void check_segment_tree_querying(int queryCount, int threshold) {
    if (queryCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive segment tree queries!" << endl;
        abort();
    }
}

void check_loop_iterations(int iterationCount, int threshold) {
    if (iterationCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations!" << endl;
        abort();
    }
}

void check_input_patterns(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - problematic input pattern!" << endl;
        abort();
    }
}

int fast_int() {
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    int res = 0;
    while (c >= '0' && c <= '9') {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}

void nhap() {
    N = fast_int();
    memset(dau, 0, sizeof(dau));
    for (int i = 1; i <= N; i++) {
        int t = fast_int();
        dau[t] = 1;
    }
}

void update(int u, int l, int r, int k) {
    it[k] = max(it[k], u);
    if (l == r) return;
    int mid = (l + r) / 2;
    if (u <= mid)
        update(u, l, mid, (k << 1));
    else
        update(u, mid + 1, r, (k << 1) + 1);
}

int get(int u, int v, int l, int r, int k) {
    if (u > r || v < l) return 0;
    if (u <= l && v >= r) return it[k];
    if (it[k] == 0) return 0;
    int mid = (l + r) / 2;
    int t2 = get(u, v, mid + 1, r, (k << 1) + 1);
    if (t2 > 0) return t2;
    int t1 = get(u, v, l, mid, (k << 1));
    return t1;
}

void tinh() {
    int res = 0;
    memset(it, 0, sizeof(it));
    int queryCount = 0;  // Track the number of segment tree queries
    for (int i = MAXV; i >= 1; i--)
        if (dau[i]) {
            if (res > i) break;
            update(i, 1, MAXV, 1);
            int l = i;
            int iterationCount = 0;  // Track loop iterations
            while (l <= MAXV) {
                iterationCount++;
                check_loop_iterations(iterationCount, 100000);  // Check for excessive iterations
                int r = min(l + i - 1, MAXV);
                int t = get(l, r, 1, MAXV, 1);
                queryCount++;
                check_segment_tree_querying(queryCount, 500000);  // Check for excessive queries
                if (t != 0) {
                    res = max(res, t - l);
                }
                if (t == i - 1) break;
                l = r + 1;
            }
        }
    printf("%d\n", res);
}

int main() {
    nhap();

    // Check input patterns before main computation
    check_input_patterns(N > 150000 && dau[1] == 1);  // Example: certain conditions in input

    tinh();
    fclose(stdin);
    return 0;
}