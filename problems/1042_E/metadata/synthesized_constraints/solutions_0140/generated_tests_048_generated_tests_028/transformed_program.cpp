#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long arr[1005][1005];
long long dp[1005][1005];

// Checker Function Definitions
void check_fastpow_invariant(int callCount, int threshold) {
    if (callCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive fastpow calls!" << endl;
        abort();
    }
}

void check_search_invariant(int searchCount, int threshold) {
    if (searchCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive binary search operations!" << endl;
        abort();
    }
}

void check_matrix_operations_invariant(int elementCount, int threshold) {
    if (elementCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to extensive matrix operations!" << endl;
        abort();
    }
}

void check_update_invariant(int updateCount, int threshold) {
    if (updateCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to frequent updates!" << endl;
        abort();
    }
}

long long fastpow(long long base, long long power) {
    static int fastpow_calls = 0;
    fastpow_calls++;
    check_fastpow_invariant(fastpow_calls, 1000); // Arbitrary threshold for excessive calls

    if (!power) return 1;
    long long ret = fastpow(base, power / 2);
    ret = (ret * ret) % 998244353;
    if (power & 1) ret = (ret * ((base) % 998244353)) % 998244353;
    return ret;
}

long long mul(long long a, long long b) {
    long long ret = (a % 998244353) * (b % 998244353);
    while (ret < 0) ret += 998244353;
    ret %= 998244353;
    return ret;
}

long long add(long long a, long long b) {
    while (a < 0) a += 998244353;
    while (b < 0) b += 998244353;
    long long ret = ((a % 998244353) + (b % 998244353));
    while (ret < 0) ret += 998244353;
    ret %= 998244353;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<pair<int, pair<int, int>>> vec;
    vector<int> i2, j2, i, j, ans;
    cin >> n >> m;

    check_matrix_operations_invariant(n * m, 1000000); // Threshold for extensive matrix operations

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            vec.push_back({arr[i][j], {i, j}});
        }
    }

    int r, c;
    cin >> r >> c;
    sort(vec.begin(), vec.end());

    for (int z = 0; z < n * m; z++) {
        i.push_back(vec[z].second.first);
        j.push_back(vec[z].second.second);
        i2.push_back(mul(vec[z].second.first, vec[z].second.first));
        j2.push_back(mul(vec[z].second.second, vec[z].second.second));
        ans.push_back(0);
        if (z)
            i[z] = add(i[z], i[z - 1]), j[z] = add(j[z], j[z - 1]),
            i2[z] = add(i2[z], i2[z - 1]), j2[z] = add(j2[z], j2[z - 1]);
    }

    int binary_search_operations = 0;

    for (int z = 0; z < n * m; z++) {
        int curx = vec[z].second.first, cury = vec[z].second.second;
        int have = -1, x2 = 0, y2 = 0, x = 0, y = 0, sol = 0, have2 = 0;
        int st = 0, en = z - 1;
        while (st <= en) {
            binary_search_operations++;
            int mid = (st + en) / 2;
            if (vec[mid].first == vec[z].first)
                en = mid - 1;
            else
                st = mid + 1, have = mid;
        }

        check_search_invariant(binary_search_operations, 10000); // Arbitrary threshold for search operations

        have++;
        if (!have) continue;
        x = i[have - 1], y = j[have - 1], x2 = i2[have - 1], y2 = j2[have - 1],
        sol = ans[have - 1];
        have2 = fastpow(have, 998244353 - 2);
        int newHave = add(mul(-2, mul(x, curx)), mul(-2, mul(y, cury)));
        newHave = add(newHave, x2);
        newHave = add(newHave, y2);
        newHave = add(newHave, mul(have, mul(curx, curx)));
        newHave = add(newHave, mul(have, mul(cury, cury)));
        newHave = add(newHave, sol);
        newHave = mul(newHave, have2);
        ans[z] = newHave;
        if (ans[z]) ans[z] = add(ans[z], ans[z - 1]);
        if (curx == r && cury == c) {
            cout << newHave;
            return 0;
        }
    }
    cout << 0;
    return 0;
}