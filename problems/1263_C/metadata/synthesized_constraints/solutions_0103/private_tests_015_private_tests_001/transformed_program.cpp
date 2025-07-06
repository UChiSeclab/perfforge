#include <bits/stdc++.h>
using namespace std;

int t;
int cnt, ans[100010];
map<int, bool> ma;

int main() {
    int i, j, k;
    scanf("%d", &t);
    while (t--) {
        int n;
        ma.clear();
        cnt = 0;
        scanf("%d", &n);
        ans[++cnt] = 0;

        int iterationCount = 0;

        for (i = 1; i * i <= n; i++) {
            iterationCount++;

            // Check for the square root loop invariant
            check_sqrt_loop_invariant(n, iterationCount);

            if (ma[n / i])
                ans[cnt] = i;
            else {
                ans[++cnt] = i;
                ma[n / i] = true;
            }
        }

        // Check for map operations invariant
        check_map_operations_invariant(ma.size(), n);

        ma.clear();
        for (i = 1; i <= cnt; i++) ma[ans[i]] = true;

        int tmp = cnt;
        for (i = 2; i <= tmp; i++) {
            if (!ma[n / ans[i]]) {
                ans[++cnt] = n / ans[i];
                ma[n / ans[i]] = true;
            }
        }

        sort(ans + 1, ans + cnt + 1);

        // Check for result list size invariant
        check_result_list_size_invariant(cnt);

        cout << cnt << endl;
        for (i = 1; i <= cnt; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}