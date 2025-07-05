#include <bits/stdc++.h>
using namespace std;
const int S = 2e5 + 1, inf = 1e9;
int n, k;
int a[S];
int cnt[S], res[S];

// Check for large and distinct numbers
void check_large_distinct_invariant(int* a, int n, int k) {
    int largeDistinctCount = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 100000) { // Arbitrary large threshold
            largeDistinctCount++;
        }
    }
    if (largeDistinctCount >= k) {
        cerr << "Warning: Performance bottleneck condition triggered - large and distinct numbers present!" << endl;
        abort();
    }
}

// Check for extensive bit shifts
void check_extensive_shifts_invariant(int* a, int n) {
    for (int i = 1; i <= n; i++) {
        int num = a[i];
        int shiftCount = 0;
        while (num) {
            num >>= 1;
            shiftCount++;
            if (shiftCount > 18) { // Arbitrary threshold for extensive shifts
                cerr << "Warning: Performance bottleneck condition triggered - number requires extensive bit shifts!" << endl;
                abort();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] >= k) {
            cout << 0;
            return 0;
        }
    }

    // Insert invariant checks before processing
    check_large_distinct_invariant(a, n, k);
    check_extensive_shifts_invariant(a, n);

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        int tmp = a[i] >> 1;
        int b = 0;
        while (tmp) {
            b++;
            if (cnt[tmp] < k) {
                cnt[tmp]++;
                res[tmp] += b;
            }
            tmp >>= 1;
        }
    }
    
    int ans = inf;
    for (int i = 1; i <= S - 1; i++)
        if (cnt[i] >= k && ans > res[i]) ans = res[i];
    cout << ans;
}