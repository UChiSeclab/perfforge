#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k;
int ans;
vector<int> p;

int fct(int x) {
    if (!x) return 1;
    return x * fct(x - 1);
}

void check_permutation_complexity(int k) {
    if (k > 7) {
        cerr << "Warning: Performance bottleneck condition triggered - high permutation complexity!" << endl;
        abort();
    }
}

void check_nested_loop_overhead(int k) {
    if (k > 7) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop overhead!" << endl;
        abort();
    }
}

void check_recursive_factorial_calls(int k) {
    if (k > 7) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive factorial calls!" << endl;
        abort();
    }
}

int main() {
    while (cin >> n >> k) {
        // Check for performance bottlenecks before starting computation
        check_permutation_complexity(k);
        check_nested_loop_overhead(k);
        check_recursive_factorial_calls(k);

        ans = 0;
        p.clear();
        for (int i = 0; i <= k; i++) p.push_back(1);
        p[0] = 0;
        int o = fct(k);
        while (1) {
            bool f = 1;
            for (int i = 1; i <= k; i++) {
                bool f1 = 0;
                int x = i;
                for (int j = 0; j < 10; j++) {
                    x = p[x];
                    f1 |= x == 1;
                }
                f &= f1;
            }
            ans += f;
            int cur = k;
            p[cur]++;
            while (p[cur] == k + 1) {
                p[cur] = 1;
                cur--;
                p[cur]++;
            }
            if (!cur) break;
        }
        for (int i = k + 1; i <= n; i++) ans = 1LL * ans * (n - k) % mod;
        cout << ans << endl;
    }
    return 0;
}