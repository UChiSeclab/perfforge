#include <bits/stdc++.h>
using namespace std;
const int maxn = 233333;
long long n, k, sum;
long long a[maxn];

struct DD {
    DD() {}
    DD(long long _d, long long _l, long long _w) { d = _d, l = _l, w = _w; }
    long long d, l, w;
    bool operator<(const DD& b) const { return w < b.w; }
    void output() { printf("len: %lld d: %lld w: %lld\n", l, d, w); }
};

inline long long sqr(long long x) { return x * x; }

inline long long calc(long long l, long long d) {
    long long r = l % d, q = l / d;
    return r * sqr(q + 1) + (d - r) * sqr(q);
}

void check_priority_queue_operations(long long n, long long k) {
    if ((k - n) > 10000) { // Assuming a threshold based on typical usage patterns
        cerr << "Warning: High number of priority queue operations due to large k - n!" << endl;
        abort();
    }
}

bool chk(long long mid) {
    long long m = sum - mid;
    if (m <= 0) return true;
    priority_queue<DD> q;
    for (int i = 1; i <= n; ++i) {
        q.push(DD(1, a[i], calc(a[i], 1) - calc(a[i], 2)));
    }
    long long sz = k - n;
    check_priority_queue_operations(n, k); // Check for high priority queue operations

    DD cur;
    for (long long i = 1; i <= sz; ++i) {
        cur = q.top();
        q.pop();
        m -= cur.w;
        ++cur.d;
        cur.w = calc(cur.l, cur.d) - calc(cur.l, cur.d + 1);
        if (m <= 0) return true;
        q.push(cur);
    }
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i] * a[i];
    }
    long long le = 0, ri = 1e18;
    long long mid = (le + ri) >> 1;
    while (le < ri) {
        if (chk(mid)) {
            ri = mid;
        } else {
            le = mid + 1;
        }
        mid = (le + ri) >> 1;
    }
    printf("%lld\n", mid);
}