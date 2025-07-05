#include <bits/stdc++.h>
using namespace std;

int a[200005];
const int mod = 998244353;
long long p(long long x, long long y) {
    long long ret = 1;
    while (y) {
        if (y % 2) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return ret;
}
int c[200005], n;

int get(int x) {
    int ret = 0;
    while (x) {
        ret += c[x];
        x -= x & (-x);
    }
    return ret;
}

void add(int x) {
    while (x <= n) {
        c[x]++;
        x += x & (-x);
    }
}

set<int> s;
vector<int> b;

void check_high_unknowns(int unknown, int n) {
    if (unknown > n / 2) {
        cerr << "Warning: Performance bottleneck due to high count of unknown elements!" << endl;
        abort();
    }
}

void check_large_iterations(int unknown, int n) {
    if (unknown > n / 2) {
        cerr << "Warning: Performance bottleneck due to large-scale iterations over arrays!" << endl;
        abort();
    }
}

void check_data_structure_usage(int size, int n) {
    if (size > n / 2) {
        cerr << "Warning: Performance bottleneck due to extensive data structure usage!" << endl;
        abort();
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) s.insert(i);

    long long ans = 0;
    long long unknown = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1)
            unknown++;
        else
            s.erase(a[i]);
    }

    // Check for high unknowns
    check_high_unknowns(unknown, n);

    for (auto it = s.begin(); it != s.end(); it++) b.push_back(*it);

    // Check data structure usage
    check_data_structure_usage(b.size(), n);

    long long tmp = 0;
    tmp += ((unknown - 1) * (unknown)) % mod;
    tmp *= p(4, mod - 2);
    tmp %= mod;
    ans = tmp;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == -1) continue;
        ans = (ans + get(a[i])) % mod;
        add(a[i]);
    }

    long long lft = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1)
            lft++;
        else {
            long long gt = (long long)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());
            gt = unknown - gt;
            long long tmp = (gt * lft) % mod;
            tmp = (tmp * p(unknown, mod - 2)) % mod;
            ans = (ans + tmp) % mod;
        }
    }

    lft = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == -1)
            lft++;
        else {
            long long gt = (long long)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());
            long long tmp = (gt * lft) % mod;
            tmp = (tmp * p(unknown, mod - 2)) % mod;
            ans = (ans + tmp) % mod;
        }
    }

    cout << ans << endl;
}