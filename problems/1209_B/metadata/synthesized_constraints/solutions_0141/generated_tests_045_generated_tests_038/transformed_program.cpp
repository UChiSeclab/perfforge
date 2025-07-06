#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
int n;
char s[maxn];
int a[maxn], b[maxn];
int sta[maxn];

void check_frequent_toggle_invariant(int a[], int n) {
    int small_a_count = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= 2) {
            small_a_count++;
        }
    }
    if (small_a_count > n / 2) {
        cerr << "Warning: Frequent toggle invariant triggered - many lights with small a_i cause excessive recalculations!" << endl;
        abort();
    }
}

void check_large_n_small_a_invariant(int n, int a[]) {
    int small_a_count = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= 2) {
            small_a_count++;
        }
    }
    if (n > 80 && small_a_count > n / 3) {
        cerr << "Warning: Large n with small a_i invariant triggered - large n with many frequent toggles!" << endl;
        abort();
    }
}

void check_synchronized_toggle_invariant(int b[], int n) {
    map<int, int> b_count;
    for (int i = 1; i <= n; i++) {
        b_count[b[i]]++;
    }
    for (const auto& [key, count] : b_count) {
        if (count > n / 4) {
            cerr << "Warning: Synchronized toggle invariant triggered - many lights with similar b_i!" << endl;
            abort();
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);

    check_frequent_toggle_invariant(a, n);
    check_large_n_small_a_invariant(n, a);
    check_synchronized_toggle_invariant(b, n);
  
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1')
            sta[i] = 1, ans++;
        else
            sta[i] = 0;
    }
    for (int time = 1; time <= 50000; time++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (time > b[i]) {
                if ((time - b[i]) % a[i] == 0) sta[i] ^= 1;
            } else if (time == b[i])
                sta[i] ^= 1;
            if (sta[i]) cnt++;
        }
        ans = max(ans, cnt);
        if (ans == n) break;
    }
    printf("%d\n", ans);
    return 0;
}