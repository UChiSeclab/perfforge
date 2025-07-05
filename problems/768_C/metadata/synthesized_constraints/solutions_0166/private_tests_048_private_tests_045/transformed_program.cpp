#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
int n, k, x, flag, mx, mn, new_cnt[MAXN], cnt[MAXN];

// Performance checkers
void check_high_iteration_count(int k) {
    if (k > 10000) {
        cerr << "Warning: Performance bottleneck due to high iteration count!" << endl;
        abort();
    }
}

void check_array_manipulation(int maxN, int k) {
    if (k * maxN > 30000000) { // An arbitrary large threshold for combined iterations
        cerr << "Warning: Performance bottleneck due to heavy array manipulation!" << endl;
        abort();
    }
}

void check_repetitive_computation(int k) {
    if (k > 50000) {
        cerr << "Warning: Performance bottleneck due to repetitive computation!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &x);

    // Insert checks right after inputs are read
    check_high_iteration_count(k);
    check_array_manipulation(MAXN, k);
    check_repetitive_computation(k);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 0; i < k; i++) {
        int cur = 0;
        for (int j = 0; j < MAXN; j++) {
            if (cur == 0) {
                new_cnt[j ^ x] += (cnt[j] + 1) / 2;
                new_cnt[j] += cnt[j] / 2;
            } else {
                new_cnt[j ^ x] += cnt[j] / 2;
                new_cnt[j] += (cnt[j] + 1) / 2;
            }
            cur = (cur + cnt[j]) % 2;
        }
        for (int j = 0; j < MAXN; j++) {
            cnt[j] = new_cnt[j];
            new_cnt[j] = 0;
        }
    }
    for (int i = 0; i < MAXN; i++) {
        if (cnt[i]) mx = i;
        if (cnt[i] && !flag) mn = i, flag = 1;
    }
    cout << mx << " " << mn;
}