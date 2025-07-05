#include <bits/stdc++.h>
using namespace std;

int n, k;
int bm[(1 << 5)];
int arr[5];

int cek(int n, int a, int b, int c, int d) {
    for (int i = 0; i < 4; i++) {
        arr[i] = 0;
        if (a & (1 << i)) arr[i]++;
        if (b & (1 << i)) arr[i]++;
        if (c & (1 << i)) arr[i]++;
        if (d & (1 << i)) arr[i]++;
    }
    for (int i = 0; i < 4; i++) {
        if (arr[i] <= n / 2) continue;
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    check_large_search_space(n, k); // Check for a large search space immediately after inputs

    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < k; j++) {
            int bit;
            cin >> bit;
            if (bit) mask |= (1 << j);
        }
        bm[mask]++;
    }

    int cekCallCount = 0;

    for (int i = 0; i < (1 << k); i++) {
        for (int i2 = 0; i2 < (1 << k); i2++) {
            for (int i3 = 0; i3 < (1 << k); i3++) {
                map<int, int> cnt;
                cnt[i]++;
                cnt[i2]++;
                cnt[i3]++;
                bool can = true;
                for (auto it : cnt) {
                    if (bm[it.first] < it.second) {
                        can = false;
                    }
                }
                cekCallCount++;
                if (can && cek(3, i, i2, i3, 0)) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }

    check_excessive_cek_calls(cekCallCount); // Check after loops for excessive cek calls

    for (int i = 0; i < (1 << k); i++) {
        for (int i2 = 0; i2 < (1 << k); i2++) {
            map<int, int> cnt;
            cnt[i]++;
            cnt[i2]++;
            bool can = true;
            for (auto it : cnt) {
                if (bm[it.first] < it.second) {
                    can = false;
                }
            }
            cekCallCount++;
            if (can && cek(2, i, i2, 0, 0)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < (1 << k); i++) {
        for (int i2 = 0; i2 < (1 << k); i2++) {
            for (int i3 = 0; i3 < (1 << k); i3++) {
                for (int i4 = 0; i4 < (1 << k); i4++) {
                    map<int, int> cnt;
                    cnt[i]++;
                    cnt[i2]++;
                    cnt[i3]++;
                    cnt[i4]++;
                    bool can = true;
                    for (auto it : cnt) {
                        if (bm[it.first] < it.second) {
                            can = false;
                        }
                    }
                    cekCallCount++;
                    if (can && cek(4, i, i2, i3, i4)) {
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    if (bm[0] > 0) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}