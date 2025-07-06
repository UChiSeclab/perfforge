#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &v) {
    static int find_calls = 0;
    find_calls++;

    for (int i = 0; i < v.size(); ++i)
        if (v[i]) return i;
    return 0;
}

void check_high_turns_invariant(int n, int lim, int x, int y) {
    if (lim > 100 * n && x <= y) {
        cerr << "Warning: High number of turns relative to doors when x <= y!" << endl;
        abort();
    }
}

void check_frequent_sorting_invariant(int n, int lim) {
    if (lim > 100 * n) {
        cerr << "Warning: Frequent sorting in loop with high iterations!" << endl;
        abort();
    }
}

void check_equal_durability_invariant(vector<int>& v, int x, int y) {
    int common_count = count(v.begin(), v.end(), v[0]);
    if (common_count > 50 && x <= y) {
        cerr << "Warning: Many doors have equal durability with x <= y!" << endl;
        abort();
    }
}

void check_repeated_find_invariant(int find_calls, int n) {
    if (find_calls > 10 * n) {
        cerr << "Warning: Excessive calls to find function!" << endl;
        abort();
    }
}

int main() {
    int n, x, y;
    while (cin >> n >> x >> y) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;

        // Check initial conditions
        check_equal_durability_invariant(v, x, y);

        if (x > y)
            cout << n << '\n';
        else {
            int lim = 5 * 1e5;

            // Check pre-loop conditions
            check_high_turns_invariant(n, lim, x, y);
            check_frequent_sorting_invariant(n, lim);

            int find_calls = 0;
            while (lim-- > 0) {
                sort(v.begin(), v.end());
                int ind = find(v);
                for (int i = ind; i < n; ++i) {
                    if (v[i] > v[ind] && v[i] <= x) {
                        ind = i;
                    }
                }
                v[ind] = max(0, v[ind] - x);
                sort(v.begin(), v.end());
                ind = find(v);
                if (v[ind]) {
                    v[ind] += y;
                }
            }

            // Post-loop checks
            check_repeated_find_invariant(find_calls, n);

            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += (v[i] == 0);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}