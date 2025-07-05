#include <bits/stdc++.h>
using namespace std;

inline void file() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Checker functions to identify performance bottlenecks
void check_high_error_threshold(int len, int max_err) {
    if (max_err > 0.8 * len) {
        cerr << "Warning: Performance bottleneck - High error threshold with nested loop complexity!" << endl;
        abort();
    }
}

void check_combined_bug_count(int* a, int n, int max_err) {
    int sum_of_bugs = 0;
    for (int i = 1; i <= n; ++i) {
        sum_of_bugs += a[i];
    }
    if (sum_of_bugs > max_err * 0.75) {
        cerr << "Warning: Performance bottleneck - Combined bug count and error threshold effect!" << endl;
        abort();
    }
}

void check_excessive_add_calls(int calls) {
    if (calls > 100000) {
        cerr << "Warning: Performance bottleneck - Repeated execution of add function!" << endl;
        abort();
    }
}

const clock_t MAXT = (100 * CLOCKS_PER_SEC) / 1000;
const int PX[5] = {0, 0, 1, -1}, PY[5] = {-1, 1, 0, 0}, N = 503, INF = 1e9;
const long long INFL = 1e18, MOD = 1e9 + 7;
const long double EPS = 1e-6;
int n, len, max_err, mod, a[N];
int dp_old[N][N], dp_new[N][N];

inline void add(int& a, int b) {
    a += b;
    while (a >= mod) a -= mod;
}

int main() {
    file();
    cin >> n >> len >> max_err >> mod;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // Insert performance checks before starting computations
    check_high_error_threshold(len, max_err);
    check_combined_bug_count(a, n, max_err);

    dp_new[0][0] = 1;

    int add_calls = 0; // Track the number of add function calls

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j <= max_err; ++j)
            for (int k = 0; k <= n; ++k) {
                dp_old[j][k] = dp_new[j][k];
                dp_new[j][k] = 0;
            }
        for (int j = 0; j <= max_err; ++j)
            for (int k = 1; k <= n; ++k) {
                add(dp_old[j][k], dp_old[j][k - 1]);
                if (a[k] + j <= max_err) {
                    add(dp_new[j + a[k]][k], dp_old[j][k]);
                    ++add_calls;
                }
            }
    }

    // Check for excessive add calls after computation
    check_excessive_add_calls(add_calls);

    int ans = 0;
    for (int i = 0; i <= max_err; ++i)
        for (int j = 0; j <= n; ++j) add(ans, dp_new[i][j]);

    cout << ans;
}