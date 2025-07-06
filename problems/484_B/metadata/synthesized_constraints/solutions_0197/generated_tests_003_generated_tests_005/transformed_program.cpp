#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXV = 1000000;
int N;
int it[MAXV * 4 + 100];
bool dau[MAXV + 10];

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

void check_dense_range_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to dense range queries!" << endl;
        abort();
    }
}

void check_large_value_update_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to excessive updates for large values!" << endl;
        abort();
    }
}

void check_high_frequency_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to high frequency of similar values!" << endl;
        abort();
    }
}

void check_unique_elements_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to many unique elements!" << endl;
        abort();
    }
}

void nhap() {
    N = fast_int();
    memset(dau, 0, sizeof(dau));
    for (int i = 1; i <= N; i++) {
        int t = fast_int();
        dau[t] = 1;
    }
    
    // Check for a large number of unique elements
    int unique_count = 0;
    for (int i = 1; i <= MAXV; i++) {
        if (dau[i]) unique_count++;
    }
    check_unique_elements_invariant(unique_count > 100000);
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
    int mid = (l + r) / 2;
    int t1 = get(u, v, l, mid, (k << 1)),
        t2 = get(u, v, mid + 1, r, (k << 1) + 1);
    return max(t1, t2);
}

void tinh() {
    int res = 0;
    memset(it, 0, sizeof(it));
    for (int i = MAXV; i >= 1; i--)
        if (dau[i]) {
            if (res > i) break;
            update(i, 1, MAXV, 1);

            // Check for excessive updates for large values
            check_large_value_update_invariant(i > 100000 && i % 1000 == 0);

            int l = i;
            while (l <= MAXV) {
                int r = min(l + i - 1, MAXV);
                int t = get(l, r, 1, MAXV, 1);

                // Check for dense range queries
                check_dense_range_invariant((r - l) > 10000);

                if (t != 0) {
                    res = max(res, t - l);
                }
                l = r + 1;
            }
        }
    printf("%d\n", res);
}

int main() {
    nhap();
    tinh();
    fclose(stdin);
    return 0;
}